#include "SensorManager.h"

SensorManager::SensorManager(
    WaterTempSensor& temp,
    PHSensor& ph,
    TDSSensor& tds,
    WaterLevel& level,
    ESPNowManager& esp,
    FlowMeter& water,
    FlowMeter& a,
    FlowMeter& b
)
:
tempSensor(temp),
phSensor(ph),
tdsSensor(tds),
levelSensor(level),
espNow(esp),
flowWater(water),
flowA(a),
flowB(b),
data{}
{
    _readState      = STATE_READ_PH;
    _lastStateChange = 0;
    _lastLevelUpdate  = 0;
}

void SensorManager::update() {
    unsigned long now = millis();

    // ================================================================
    // State Machine: Pembacaan sensor secara sequential
    // Urutan: PH (avg 500ms) → tunggu 30s → Suhu Air → tunggu 30s → TDS
    // Tujuan: mencegah GND nabrak antar sensor analog,
    //         dan memastikan TDS pakai suhu terbaru.
    // ================================================================
    switch (_readState) {

        // --- [0] Baca PH: sampling rata-rata tiap 500ms ---
        case STATE_READ_PH:
            if (now - _lastStateChange >= PH_SAMPLE_INTERVAL) {
                data.ph          = phSensor.readPH();
                _lastStateChange = now;

                // Setelah selesai satu putaran baca PH, masuk jeda
                _readState = STATE_WAIT_PH;
            }
            break;

        // --- [1] Jeda 30 detik sebelum baca Suhu ---
        case STATE_WAIT_PH:
            if (now - _lastStateChange >= SENSOR_GAP_MS) {
                _lastStateChange = now;
                _readState = STATE_READ_TEMP;
            }
            break;

        // --- [2] Baca Suhu Air (DS18B20, butuh 750ms konversi) ---
        case STATE_READ_TEMP:
            if (now - _lastStateChange >= TEMP_CONVERT_MS) {
                data.temperature = tempSensor.getTemperature();
                _lastStateChange = now;
                _readState = STATE_WAIT_TEMP;
            }
            break;

        // --- [3] Jeda 30 detik sebelum baca TDS ---
        case STATE_WAIT_TEMP:
            if (now - _lastStateChange >= SENSOR_GAP_MS) {
                _lastStateChange = now;
                _readState = STATE_READ_TDS;
            }
            break;

        // --- [4] Baca TDS menggunakan suhu air terbaru ---
        case STATE_READ_TDS:
            if (now - _lastStateChange >= PH_SAMPLE_INTERVAL) {
                // TDS membutuhkan suhu untuk kompensasi
                data.ppm         = tdsSensor.readPPM(data.temperature);
                _lastStateChange = now;
                _readState = STATE_WAIT_TDS;
            }
            break;

        // --- [5] Jeda 30 detik lalu kembali ke pembacaan PH ---
        case STATE_WAIT_TDS:
            if (now - _lastStateChange >= SENSOR_GAP_MS) {
                _lastStateChange = now;
                _readState = STATE_READ_PH;  // kembali ke awal siklus
            }
            break;
    }

    // Ultrasonic — baca setiap 100ms (tidak bergantung state, tidak pakai GND analog)
    if (now - _lastLevelUpdate >= 100UL) {
        data.waterLevel  = levelSensor.getLevelPercent();
        data.tankVolume  = levelSensor.getVolumeLiter();
        _lastLevelUpdate = now;
    }

    // Flow meter — realtime via ISR, baca langsung setiap update
    data.flowWater = flowWater.getVolumeLiter();
    data.flowA     = flowA.getVolumeLiter();
    data.flowB     = flowB.getVolumeLiter();

    // Soil data dari ESP-NOW
    if (espNow.hasNewData()) {
        SoilData soil = espNow.getData();
        data.soilADC  = soil.averageRawADC;
        espNow.clearFlag();
    }
}

SensorData
SensorManager::getData()
const {
    return data;
}
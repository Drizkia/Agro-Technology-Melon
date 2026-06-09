void setup() {
    Serial.begin(115200);

    // initRelay();
    // initSuhu();
    initPH();
}

void loop() {
    // readRelay();
    // readRelay();
    readPH();
    delay(1000);
}
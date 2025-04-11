#define HALL_SENSOR_PIN 34  // Connect 3144 sensor OUT to GPIO 34

void setup() {
    Serial.begin(115200);
    pinMode(HALL_SENSOR_PIN, INPUT);
}

void loop() {
    int hallState = digitalRead(HALL_SENSOR_PIN);

    if (hallState == LOW) {  // Magnet detected (3144 pulls LOW when near a magnet)
        Serial.println("Magnet Detected!");
    } else {
        Serial.println("No Magnet.");
    }

    delay(500);
}

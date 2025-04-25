#include <Wire.h>
#include <ak8975.h>

AK8975 compass(Wire);

void setup() {
    Serial.begin(115200);
    Wire.begin();
    
    compass.initialize();
    if (!compass.test_connection()) {
        Serial.println("Compass connection failed!");
        while(1);
    }
}

void loop() {
    AK8975::CompassReading reading;
    compass.get_reading(&reading);
    
    Serial.printf("X: %d  Y: %d  Z: %d\n", 
                 reading.x, reading.y, reading.z);
    delay(100);
}
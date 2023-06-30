#include "esphome.h"

class MyCustomSensor : public Component, public Sensor {
 public:
  void setup() override {
    // This will be called by App.setup()
    // Set up the serial port
    Serial.begin(115200);
  }

  void loop() override {
    // This will be called by App.loop()
    if (Serial.available() > 0) {
      // Read the incoming string
      String valueString = Serial.readStringUntil('\n');
      valueString.trim();  // Remove leading/trailing whitespace

      // Parse the string as an integer
      int value = valueString.toInt();

      // Publish the value as a sensor reading
      publish_state(value);
    }
  }
};

class MyCustomSensor : public PollingComponent {
 public:

  Sensor *temperature_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();

  MyCustomSensor() : PollingComponent(5000) { }

  void setup() override {
  }
    float temperature = -300.00;
    float humidity = -300.00;

void loop() override {
  if (Serial.available() > 0) {
      String valueString = Serial.readStringUntil('\n');
      valueString.trim(); 

      sscanf(valueString.c_str(), "Temperature: %f, Humidity: %f", &temperature, &humidity);
    }
}

  void update() override {

    temperature_sensor->publish_state(temperature);
    humidity_sensor->publish_state(humidity);
  }
};
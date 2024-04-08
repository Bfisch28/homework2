//Question 1
//made with the assistance of chatgpt
#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Abstract base class for sensors
class Sensor {
public:
    virtual void gatherData() = 0;
    virtual void processData() = 0;
    virtual ~Sensor() {}
};

// Derived classes for specific sensors
class TemperatureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Temperature Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Temperature Sensor." << std::endl;
    }
};

class PressureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Pressure Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Pressure Sensor." << std::endl;
    }
};

class PositionSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Position Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Position Sensor." << std::endl;
    }
};

// Factory class to create sensors
class SensorFactory {
public:
    static std::unique_ptr<Sensor> createSensor(const std::string& sensorType) {
        if (sensorType == "Temperature")
            return std::make_unique<TemperatureSensor>();
        else if (sensorType == "Pressure")
            return std::make_unique<PressureSensor>();
        else if (sensorType == "Position")
            return std::make_unique<PositionSensor>();
        else
            return nullptr;
    }
};

// Aerospace control system class
class AerospaceControlSystem {
private:
    std::vector<std::unique_ptr<Sensor>> sensors;

public:
    void addSensor(std::unique_ptr<Sensor> sensor) {
        sensors.push_back(std::move(sensor));
    }

    void monitorAndAdjust() {
        for (const auto& sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data." << std::endl;
        }
    }
};

int main() {
    AerospaceControlSystem ctrlSys;

    // Adding sensors
    ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
    ctrlSys.addSensor(SensorFactory::createSensor("Pressure"));
    ctrlSys.addSensor(SensorFactory::createSensor("Position"));

    // Monitoring and adjusting
    ctrlSys.monitorAndAdjust();

    return 0;
}

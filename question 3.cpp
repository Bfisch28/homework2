//Question 3
#include <iostream>
#include <queue>

class AirTrafficController {
private:
    bool asleep = true;
    int trafficPattern = 0;

public:
    void wakeUp() {
        asleep = false;
    }

    void fallAsleep() {
        asleep = true;
    }

    bool isAsleep() const {
        return asleep;
    }

    bool isTrafficPatternFull() const {
        return trafficPattern >= 3;
    }

    void addToTrafficPattern() {
        ++trafficPattern;
    }

    void removeFromTrafficPattern() {
        --trafficPattern;
    }
};

int main() {
    AirTrafficController atc;
    std::queue<int> landingQueue; // Queue of aircraft approaching for landing

    // Simulate 10 aircraft coming to the airport
    for (int i = 1; i <= 10; ++i) {
        // New aircraft approaches
        landingQueue.push(i);

        // If ATC is asleep, wake them up
        if (atc.isAsleep()) {
            atc.wakeUp();
            std::cout << "ATC wakes up." << std::endl;
        }

        // Check if traffic pattern is full
        if (!atc.isTrafficPatternFull()) {
            // Check if ATC is talking to another pilot
            if (!atc.isAsleep()) {
                // ATC is available, aircraft can enter traffic pattern
                atc.addToTrafficPattern();
                std::cout << "Aircraft " << i << " enters traffic pattern." << std::endl;
            }
        }
        else {
            // Traffic pattern is full, divert aircraft to other airports
            std::cout << "Aircraft " << i << " diverted to other airports." << std::endl;
        }

        // Simulate landing process
        std::cout << "Aircraft " << i << " lands." << std::endl;

        // Remove aircraft from traffic pattern after landing
        atc.removeFromTrafficPattern();

        // If no more aircraft in queue, ATC falls asleep
        if (landingQueue.empty()) {
            atc.fallAsleep();
            std::cout << "ATC falls asleep." << std::endl;
        }
    }

    return 0;
}

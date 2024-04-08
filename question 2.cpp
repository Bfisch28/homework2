//Question 2
#include <iostream>
#include <vector>
#include <algorithm>

const int NUM_ROBOTS = 5;
const int NUM_TOOLS = 5;
const int TIME_TO_GRAB_TOOLS = 1;
const int TIME_TO_COMPLETE_TASK = 5;

int main() {
    // Vector to store time taken by each robot
    std::vector<int> timeTaken(NUM_ROBOTS, 0);

    // Simulate each robot grabbing tools and completing tasks
    for (int i = 0; i < NUM_ROBOTS; ++i) {
        // Calculate the index of the tool for the current robot
        int toolIndex = (i + 1) % NUM_TOOLS;

        // Time taken to grab tools
        timeTaken[i] += TIME_TO_GRAB_TOOLS;

        // Time taken to complete task
        timeTaken[i] += TIME_TO_COMPLETE_TASK;

        // Time taken to return tools
        timeTaken[i] += TIME_TO_GRAB_TOOLS;

        // Update time taken for the next robot to start
        int nextRobotIndex = (i + 1) % NUM_ROBOTS;
        timeTaken[nextRobotIndex] = std::max(timeTaken[nextRobotIndex], timeTaken[i]);
    }

    // Calculate total time taken by all robots
    int totalTime = *std::max_element(timeTaken.begin(), timeTaken.end());

    // Output the result
    std::cout << "Total time taken by all robots to finish all tasks: " << totalTime << " seconds" << std::endl;

    return 0;
}

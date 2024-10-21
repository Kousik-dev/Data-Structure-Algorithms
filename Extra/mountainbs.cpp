#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool destroyMountain(int height, vector<int>& workerTimes, long long maxTime) {
        long long totalDestroy = 0;
        cout << "Checking with maxTime = " << maxTime << "\n";

        for(int time : workerTimes) {
            long long low = 1, high = height;
            cout << "  Worker with time = " << time << " starts binary search:\n";
            
            while(low <= high) {
                long long mid = low + (high - low) / 2;
                long long cost = (mid * (mid + 1)) / 2 * time;

                cout << "    low = " << low << ", mid = " << mid << ", high = " << high << ", cost = " << cost << "\n";
                
                // Check if the cost exceeds maxTime
                if(cost <= maxTime) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            totalDestroy += high;
            cout << "  Worker can destroy " << high << " units. Total destroyed = " << totalDestroy << "\n";
            
            if(totalDestroy >= height) {
                cout << "  Mountain is destroyed! Exiting early.\n";
                return true;
            }
        }
        return totalDestroy >= height;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1, high = 1e18, result = high;

        cout << "Starting binary search for minimum time to destroy the mountain...\n";
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            cout << "\nBinary search: low = " << low << ", mid = " << mid << ", high = " << high << "\n";
            
            if(destroyMountain(mountainHeight, workerTimes, mid)) {
                result = mid;
                high = mid - 1;
                cout << "Result found, reducing high to " << high << "\n";
            } else {
                low = mid + 1;
                cout << "Could not destroy mountain in " << mid << " time, increasing low to " << low << "\n";
            }
        }

        cout << "Minimum time to destroy the mountain = " << result << "\n";
        return result;
    }
};

int main() {
    Solution solution;
    int mountainHeight = 4;
    vector<int> workerTimes = {2, 1, 1};

    solution.minNumberOfSeconds(mountainHeight, workerTimes);
}

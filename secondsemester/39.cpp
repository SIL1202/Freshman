#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Train {
private:
    vector<int> LIS, LDS;

public:
    Train() {}

    int findLongestTrain(const vector<int>& cars) {
        int maxLen = 0;
        int n = cars.size();
        
        LIS.clear();
        LDS.clear();
        
        for (int i = n - 1; i >= 0; --i) {
            int len1, len2;
            auto it = lower_bound(LDS.begin(), LDS.end(), cars[i]);
            if (it == LDS.end()) {
                LDS.push_back(cars[i]);
                len2 = LDS.size();
            } else {
                *it = cars[i];
                len2 = distance(LDS.begin(), it) + 1;
            }

            it = lower_bound(LIS.begin(), LIS.end(), -cars[i]);
            if (it == LIS.end()) {
                LIS.push_back(-cars[i]);
                len1 = LIS.size();
            } else {
                *it = -cars[i];
                len1 = distance(LIS.begin(), it) + 1;
            }

            maxLen = max(maxLen, len1 + len2 - 1);
        }
        return maxLen;
    }
};

int main() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int n;
        cin >> n;

        vector<int> cars(n);
        for (int i = 0; i < n; ++i) {
            cin >> cars[i];
        }

        Train train;
        cout << train.findLongestTrain(cars) << endl;
    }

    return 0;
}


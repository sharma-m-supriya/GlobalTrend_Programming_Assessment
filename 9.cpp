#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDifference(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int minElement = nums[0];
    int maxDiff = 0;
    for (int i = 1; i < nums.size(); ++i) {
        maxDiff = max(maxDiff, nums[i] - minElement);
        minElement = min(minElement, nums[i]);
    }
    return maxDiff;
}

int main() {
    vector<int> nums = {2, 3, 15, 6, 4, 8, 9};
    cout << "Maximum difference: " << maxDifference(nums) << endl;
    return 0;
}


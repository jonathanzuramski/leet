#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main() {
    int target = 6;
    vector<int> nums{3, 2, 4};

    vector<int> results = twoSum(nums, target);

    cout << results[0] << ", " << results[1] << endl;
}

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> locations;
    unordered_map<int, int> map;

    int comp = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        comp = target - nums[i];
        auto it = map.find(comp);

        if (it != map.end()) {
            return {i, it->second};
        }
        map.insert({nums[i], i});
    }

    return locations;
}

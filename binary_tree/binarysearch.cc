#include <iostream>
#include <vector>

class Solution {
    public:
    /// @brief Perform binary search to find the index of the target in a sorted array.
    /// @param nums A sorted vector of integers.
    /// @param target The integer value to search for.
    /// @return The index of the target if found; otherwise, -1.
    int binarySearch(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            //这里因为是int型，所以奇数时取整。比如3/2 = 1
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }else if (nums[mid] < target) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    std::vector <int> nums ={1,3,4,4,5,6,7,8,9};
    int target_left = 3;
    int target_right = 8;
    Solution sol;
    int left_index = sol.binarySearch(nums, target_left);
    int right_index = sol.binarySearch(nums, target_right);

    std::cout << "Index of left " << left_index <<"\n";
    std::cout << "index of right " << right_index;
}

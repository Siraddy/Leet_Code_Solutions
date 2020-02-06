#include <iostream>
#include <string>
#include <vector>

int linear_search(const std::vector<int>& nums, const int& target, const int& min, const int& max);
int binary_search(const std::vector<int>& nums, const int& target);
int searchInsert(std::vector<int>& nums, int target);

int linear_search(const std::vector<int>& nums, const int& target, const int& min, const int& max) {
    int closest_index = min;
    for(int i = min; i <= max; i++) {
        if(nums[i] == target) {
            return i;
        } else {
            if(nums[i] > target) {
                return closest_index;
            } else if(target - nums[i] <= target - nums[closest_index]) {
                    closest_index = i + 1;
            } else {
                //do nothing
            }
        }
    }

    return closest_index;
}



int binary_search(const std::vector<int>& nums, const int& target) {
    int min = 0;
    int max = nums.size() - 1;
    int index = (int)((max + min)/2);

    while(true) {
        if(nums[index] == target) {
            return index;
        } else {
            if(nums[index] > target) {
                max = index;
                index = (int)((max + min)/2);
            } else if(nums[index] < target) {
                min = index;
                index = (int)((max + min)/2);
            } else {
                //do nothing
            }

            if(max - min <= 18) {
                return linear_search(nums, target, min, max);
            } 
        }
    }
}

int searchInsert(std::vector<int>& nums, int target) {
    return binary_search(nums, target);
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    std::cout << searchInsert(nums, target) << std::endl;
}
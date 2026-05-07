#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int ans = 0;
        int startingIndex = 0;
        bool isAnswerFound = false;
        int firstAnswerIndex = 0;
        int secondAnswerIndex = 0;
        while (!isAnswerFound){
            for (int i = startingIndex+1; i < nums.size(); i++){
                if (nums[startingIndex] + nums[i] == target){
                    isAnswerFound = true;
                    firstAnswerIndex = startingIndex;
                    secondAnswerIndex = i;
                    break;
                }
            }
            startingIndex++;
        }
        return {firstAnswerIndex, secondAnswerIndex};
    }
};

void printVector(std::vector<int> vector){
    std::cout << "[ ";
    for (int i = 0; i < vector.size(); i++){
        std::cout << vector[i];
        if (i < vector.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}

std::string vectorToString(std::vector<int> vector){
    std::string str = "[ ";
    for (int i = 0; i < vector.size(); i++){
        str += std::to_string(vector[i]);
        if (i < vector.size()-1){
            str += ", ";
        }
    }
    str += " ]";
    return str;
}

int main() {
    std::vector<int> nums1 = {2,7,11,15};
    /*
    0,1 2+7
    0,2 2+11
    0,3 2+15
    1,2 7+11
    1,3 7+15 
    2,3 11+15
    */
    int target1 = 9;
    std::vector<int> nums2 = {3,2,4};
    int target2 = 6;
    std::vector<int> nums3 = {3,3};
    int target3 = 6;

    std::cout << "Case 1: \n\tNums: " << vectorToString(nums1) << " Target: " << target1 << "\n\tSolution: " << vectorToString(Solution().twoSum(nums1, target1)) << "\n";
    std::cout << "Case 2: \n\tNums: " << vectorToString(nums2) << " Target: " << target2 << "\n\tSolution: " << vectorToString(Solution().twoSum(nums2, target2)) << "\n";
    std::cout << "Case 3: \n\tNums: " << vectorToString(nums3) << " Target: " << target3 << "\n\tSolution: " << vectorToString(Solution().twoSum(nums3, target3)) << "\n";
    return 0;
}
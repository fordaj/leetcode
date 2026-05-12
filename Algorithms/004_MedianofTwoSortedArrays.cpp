#include <iostream>
#include <array>

std::string to_string(std::vector<int>& inputVector){
    std::string str = "[ ";
    for (int i = 0; i < inputVector.size(); i++){
        str += std::to_string(inputVector[i]) + " ";
    }
    str += "]";
    return str;
}

class Solution {
private:
    std::vector<int> output = {};
public:
    void sortVector(std::vector<int>& input){
        bool isSorted = false;
        while (!isSorted){
            isSorted = true;
            for (int i = 1; i < input.size(); i++){
                if (input[i-1] > input[i]){
                    isSorted = false;
                    int temp = input[i];
                    input[i] = input[i-1];
                    input[i-1] = temp;
                }
            }
        }
    }
    double getMedian(std::vector<int>& input){
        int size = input.size();
        int middle = size / 2;
        bool isMiddleEven = (size % 2 == 0);
        if (isMiddleEven){
            int left = input[middle-1];
            int right = input[middle];
            return double((left + right) / 2.0);
        }else{
            return double(input[middle]);
        }

    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        output = {};
        for (int i = 0; i < nums1.size(); i++){
            output.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++){
            output.push_back(nums2[i]);
        }
        std::cout << "Unsorted: " << to_string(output) << "\n";
        sortVector(output);
        std::cout << "Sorted: " << to_string(output) << "\n";
        
        return getMedian(output);
    }
};

int main() {
    {
        std::vector<int> nums1 = {1,3};
        std::vector<int> nums2 = {2};
        std::cout << "nums1: " << to_string(nums1) << " nums2: " << to_string(nums2)  << " Output: " << std::to_string(Solution().findMedianSortedArrays(nums1, nums2)) << "\n";
    }
    {
        std::vector<int> nums1 = {1,2};
        std::vector<int> nums2 = {3,4};
        std::cout << "nums1: " << to_string(nums1) << " nums2: " << to_string(nums2)  << " Output: " << std::to_string(Solution().findMedianSortedArrays(nums1, nums2)) << "\n";
    }
    return 0;
}
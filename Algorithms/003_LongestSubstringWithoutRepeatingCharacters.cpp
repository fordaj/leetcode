#include <iostream>

class Solution {
public:

    bool isCharInString(char& character, std::string& str){
        for (int i = 0; i < str.length(); i++){
            if (character == str[i]){
                return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(std::string s) {
        int maxSubstringLength = 0;
        for (int i = 0; i < s.length()-1; i++){
            int substringLength = 0;
            std::string substring = std::to_string(s[i]);
            for (int j = i; j < s.length(); j++){
                if(isCharInString(s[j], substring)){
                    substring += s[j];
                    substringLength++;
                }else{
                    break;
                }
            }
            if (substringLength > maxSubstringLength) maxSubstringLength = substringLength;
        }
        return maxSubstringLength;
    }
};

int main() {
    {
        std::string input = "abcabcbb";
        std::cout << "Input: " << input << " Output: " << std::to_string(Solution().lengthOfLongestSubstring(input)) << "\n";
        // output: 3
    }
    {
        std::string input = "bbbbb";
        std::cout << "Input: " << input << " Output: " << std::to_string(Solution().lengthOfLongestSubstring(input)) << "\n";
        // output: 1
    }
    {
        std::string input = "pwwkew";
        std::cout << "Input: " << input << " Output: " << std::to_string(Solution().lengthOfLongestSubstring(input)) << "\n";
        // output: 3
    }
    return 0;
}
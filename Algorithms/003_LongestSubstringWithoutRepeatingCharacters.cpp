#include <iostream>

class Solution {
public:

    bool isCharInString(char& character, std::string& str){
        for (int i = 0; i < str.length(); i++){
            if (character == str[i]){
                return true;
            }
        }
        return false;
    }

    int lengthOfLongestSubstring(std::string s) {
        if (s.length() < 2){
            return s.length();
        }
        int maxSubstringLength = 0;

        for (int i = 0; i < s.length(); i++){
            int substringLength = 1;

            std::string substring(1, s[i]);

            for (int j = i + 1; j < s.length(); j++){
                if(!isCharInString(s[j], substring)){
                    substring += s[j];
                    substringLength++;
                } else {
                    break;
                }
            }

            if (substringLength > maxSubstringLength)
                maxSubstringLength = substringLength;
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
    {
        std::string input = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::cout << "Input: " << input << " Output: " << std::to_string(Solution().lengthOfLongestSubstring(input)) << "\n";
    }
    std::cout << std::to_string(4);
    return 0;
}
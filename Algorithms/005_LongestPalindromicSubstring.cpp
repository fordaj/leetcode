#include <iostream>
class Solution {
public:

    bool isPalindrome(const std::string& s, int left, int right){

        while (left < right){
            if (s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    std::string longestPalindrome(std::string s) {

        int bestStart = 0;
        int bestLength = 1;

        for (int windowSize = s.length(); windowSize >= 1; windowSize--){

            for (int start = 0; start + windowSize <= s.length(); start++){

                int end = start + windowSize - 1;

                if (isPalindrome(s, start, end)){
                    return s.substr(start, windowSize);
                }
            }
        }

        return "";
    }
};

int main() {
    {
        std::cout<<Solution().longestPalindrome("asdfdsasssss") << "\n";
    }
    {
        std::cout<<Solution().longestPalindrome("asddsa") << "\n";
    }
    {
        std::cout<<Solution().longestPalindrome("xaabacxcabaaxcabaax") << "\n";
    }
    {
        std::cout<<Solution().longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << "\n";
    }
    return 0;
}
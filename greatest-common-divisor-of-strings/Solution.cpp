// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";

        while(1) {
            if (str1.length() == str2.length()) return str1;
            if (str2.length() > str1.length()) str1.swap(str2);
            const auto m = str2.length();
            str2 = str1.substr(m, str1.length()-m);
            str1 = str1.substr(0, m);
        }

    }
};
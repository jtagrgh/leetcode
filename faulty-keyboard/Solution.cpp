// https://leetcode.com/problems/faulty-keyboard

class Solution {
public:
    string finalString(string s) {
        auto out = std::string{};
        for(const auto& c: s) {
            if (c == 'i') {
                std::reverse(out.begin(), out.end());
            } else {
                out.push_back(c);
            }
        }
        return out;
    }
};
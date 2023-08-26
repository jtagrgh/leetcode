// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        auto isDigit = [](const char& c){
            if (c >= '0' && c <= '9') {
                return true;
            } else {
                return false;
            }
        };

        auto toNum = [](const char& c) {
            return c - '0';
        };

        int sum = 0;
        int sign = 1;

        auto m10 = [&]() {
            if (sum < (sign == 1 ? -1*INT_MAX/10 : INT_MIN/10)) {
                sum = (sign == 1 ? -1*INT_MAX : INT_MIN);
                return false;
            } else {
                sum *= 10;
                return true;
            }
        };

        auto mc = [&](int c) {
            if (sum < (sign == 1 ? -1*INT_MAX + c : INT_MIN + c)) {
                sum = (sign == 1 ? -1*INT_MAX : INT_MIN);
                return false;
            } else {
                sum -= c;
                return true;
            }
        };

        enum State {PRE, IN, DONE};
        State state = PRE; 
        for (const auto& c : s) {
            switch (state) {
                case PRE:
                    if (c == ' ') continue;
                    if (c == '+') {
                        sign = 1;
                        state = IN;
                    }
                    else if (c == '-') {
                        sign = -1;
                        state = IN;
                    }
                    else if (isDigit(c)) {
                        sum -= toNum(c);
                        state = IN;
                    } else {
                        state = DONE;
                    }
                    break;
                case IN:
                    if (!isDigit(c)) {
                        state = DONE;
                    } else {
                        if (m10()) {
                            if (!mc(toNum(c))) state = DONE;
                        } else {
                            state = DONE;
                        }
                    }
                    break;
                case DONE:
                    goto END;
                    break;
                default:
                    break;
            }
        }
        END:
        return sign == 1 ? -1 * sum : sum;
    }
};
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        arr.push_back(pref[0]);
        for (auto i = pref.begin(); i != pref.end()-1; i++) {
            arr.push_back((*i) ^ (*next(i)));
        }
        
        return arr;
    }
};
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto area = [&](int i1, int i2) {
            return min(height[i1], height[i2]) * abs(i2 - i1);
        };

        int i1 = 0, i2 = height.size() - 1;
        int area_max = 0;
        do {
            area_max = max(area_max, area(i1,i2));
            if (height[i1] < height[i2]) {
                i1++;
            } else {
                i2--;
            }
        } while (abs(i2-i1) >= 1);

        return area_max;
    }
};
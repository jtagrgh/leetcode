// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int work_times[500] = {0};
        work_times[logs[0][0]] = logs[0][1];
        int tworked;
        for (auto i = logs.begin()+1; i != logs.end(); i++) {
            tworked = (*i)[1] - (*prev(i))[1];
            if (tworked > work_times[(*i)[0]])
                work_times[(*i)[0]] = tworked;
        }
        int id, t_max = 0;
        for (int i = 0; i < n; i++) {
            if (work_times[i] > t_max) {
                t_max = work_times[i];
                id = i;
            }
        }
        return id;
    }
};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for (auto it : deadends) {
            mp[it] = 1;
        }
        if (mp.count("0000") > 0 || mp.count(target) > 0) {
            return -1;
        }
        int ans = 0;
        queue<string> q;
        q.push("0000");
        mp["0000"] = 1; 
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    return ans;
                }
                for (int j = 0; j < 4; j++) {
                    for (int d = -1; d <= 1; d += 2) {
                        auto next = p;
                        next[j] = '0' + (next[j] - '0' + d + 10) % 10;
                        if (mp.count(next) == 0) {
                            q.push(next);
                            mp[next] = 1;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */
#include "headers.h"

// @lc code=start
class Solution {
public:
    bool isSameLine(vector<int>& a, vector<int>& b, vector<int>& c) {
        // k = (a[1] - b[1]) / (a[0] - b[0]) = (a[1] - c[1]) / (a[0] - c[0])
        return (long long)(a[0] - b[0]) * (long long)(a[1] - c[1]) == (long long)(a[1] - b[1]) * (long long)(a[0] - c[0]);
        // 都不为0时，没有问题；为0时，分别是三个横坐标/纵坐标相等或者两个点重合
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return 1;
        }
        int ans = 2;
        int count;
        for (int i = 0; i < len - 2; i++) {
            int same_points = 0;
            for (int j = i + 1; j < len; j++) {  // 可能有三个点相同的情况
                if (points[i] == points[j]) {
                    same_points++;
                    continue;
                }
                count = 2;
                for (int k = j + 1; k < len; k++) {
                    if (isSameLine(points[i], points[j], points[k])) {
                        count++;
                    }
                }
                if (count + same_points > ans) {
                    ans = count + same_points;
                }
            }
            if (1 + same_points > ans) {
                ans = 1 + same_points;
            }
        }
        
        return ans;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> v;
    v.push_back({1, 1});
    v.push_back({2, 2});
    v.push_back({3, 3});
    cout << Solution().maxPoints(v);
    return 0;
}
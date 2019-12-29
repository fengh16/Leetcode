/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */
#include "headers.h"

// @lc code=start
class Solution
{
public:
    string simplify(const string &s1, const string &s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 == 0) {
            return s2;
        }
        if (len2 == 0) {
            return s1;
        }
        if (s1[len1 - 1] == s2[0]) {
            if (len1 > 1 && s1[len1 - 2] == s1[len1 - 1] && len2 > 1 && s2[0] == s2[1]) {
                return simplify(s1.substr(0, len1 - 2), s2.substr(2, len2 - 2));
            }
            if (len1 > 1 && s1[len1 - 2] == s1[len1 - 1]) {
                return simplify(s1.substr(0, len1 - 2), s2.substr(1, len2 - 1));
            }
            if (len2 > 1 && s2[0] == s2[1]) {
                return simplify(s1.substr(0, len1 - 1), s2.substr(2, len2 - 2));
            }
        }
        return s1 + s2;
    }

    int myMin(int a, int b) {
        unsigned int ua = a, ub = b;
        return int(ua < ub ? ua : ub);
    }

    int findMinStep(string board, string hand)
    {
        int len = board.size();
        if (len == 0) {
            return 0;
        }
        int handlen = hand.size();
        if (handlen == 9) {
            return -1;
        }
        set<char> ans;
        int min_ans = -1;
        for (int i = 0; i < handlen; i++)
        {
            char c = hand[i];
            if (ans.count(c) == 0)
            {
                // check
                ans.insert(c);
                for (int index = 0; index < len; index++)
                {
                    if (board[index] == c)
                    {
                        string temp_ans = simplify(board.substr(0, index + 1), board.substr(index, len - index));
                        string temp_hand = hand.substr(0, i) + hand.substr(i + 1, handlen - i - 1);
                        int now_min = findMinStep(temp_ans, temp_hand) + 1;
                        if (now_min > 0) {
                            min_ans = myMin(now_min, min_ans);
                        }
                        // avoid extra checks
                        if (index < len - 1 && board[index] == board[index + 1])
                        {
                            index++;
                        }
                    }
                }
            }
        }
        // cout << min_ans << ": " << board << "   " << hand << endl;
        return min_ans;
    }
};
// @lc code=end

int main() {
    cout << Solution().findMinStep("WRRBBW", "RB");
    return 0;
}
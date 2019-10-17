/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
#include "headers.h"

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<char> op;
        stack<int> nums;
        int now_number = 0;
        for (int i = 0; i < len; i++) {
            char data = s[i];
            char poped = op.empty() ? 0 : op.top();
            switch (data)
            {
            case ' ':
                break;
            case '(':
                op.push('(');
                break;
            case ')':
                op.pop();
                if (poped == '(') {
                    break;
                }
                if (poped == '+') {
                    now_number = nums.top() + now_number;
                }
                else {
                    now_number = nums.top() - now_number;
                }
                nums.pop();
                i--;
                break;
            case '+':
            case '-':
                if (poped && poped != '(') {
                    op.pop();
                    if (poped == '+') {
                        now_number = nums.top() + now_number;
                    }
                    else {
                        now_number = nums.top() - now_number;
                    }
                    nums.pop();
                }
                nums.push(now_number);
                now_number = 0;
                op.push(data);
                break;
            default:
                now_number = now_number * 10 + (data - '0');
                break;
            }
        }
        while (!op.empty()) {
            if (op.top() == '+') {
                now_number = nums.top() + now_number;
            }
            else {
                now_number = nums.top() - now_number;
            }
            op.pop();
            nums.pop();
        }
        return now_number;
    }
};
// @lc code=end

int main() {
    cout << Solution().calculate("(1+2)+(3-9)") << endl;
    return 0;
}
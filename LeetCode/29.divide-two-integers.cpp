/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (17.02%)
 * Likes:    2231
 * Dislikes: 8061
 * Total Accepted:    413.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: dividend = 0, divisor = 1
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: dividend = 1, divisor = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int x, int y) {
        int minus = 1;
        if (x > 0 && y < 0 || x < 0 && y > 0) minus = -1;
        if (x == INT_MIN && y == -1) return INT_MAX;
        if (y == 1) return x;
        if (x > 0) x = -x;
        if (y > 0) y = -y;
        vector<int> exp;
        for (int i = y; i >= x; i = i + i) {
            exp.push_back(i);
            if (x - i > i) break;
        }
        int res = 0;
        for (int i = exp.size() - 1; i >= 0; --i) {
            if (x <= exp[i]) {
                x -= exp[i];
                res += 1 << i;
            }
        }
        if (minus == -1) res = -res;
        return res;
    }
};

// @lc code=end


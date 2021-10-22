/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (53.22%)
 * Likes:    3680
 * Dislikes: 631
 * Total Accepted:    586K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[10];
        memset(st, 0, sizeof st);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                auto c = board[i][j];
                if (c == '.') continue;
                if (st[c - '0'] == true) return false;
                else st[c - '0'] = true;
            }
            memset(st, 0, sizeof st);
        }
        memset(st, 0, sizeof st);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                auto c = board[j][i];
                if (c == '.') continue;
                if (st[c - '0'] == true) return false;
                else st[c - '0'] = true;
            }
            memset(st, 0, sizeof st);
        }
        bool s[3][3][10];
        memset(s, 0, sizeof s);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                auto c = board[i][j];
                if (c == '.') continue;
                if (s[i/3][j/3][c - '0'] == true) return false;
                else s[i/3][j/3][c - '0'] = true;
            }
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.77%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 183.4K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string str="aeiouAEIOU";
        for(int left=0,right=s.size()-1;left<right;){
            while(left<right&&str.find(s[left])==string::npos)++left;//找到最左边元音字母
            while(left<right&&str.find(s[right])==string::npos)--right;//找到最右边元音字母
            swap(s[left++],s[right--]);//交换后移位
        }
        return s;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode-cn.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (58.98%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 97.2K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines
 * 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
 * 
 * (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设两个字符串均只含有小写字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> r,m;
        for(const auto &it:ransomNote){
            ++r[it];
        }
        for(const auto &it:magazine){
            ++m[it];
        }
        for(const auto &it:r){
            int tempr=it.second;
            int tempm=m.count(it.first);
            if(m.find(it.first)==m.end()||it.second>m[it.first])return false;
        }
        return true;
    }
};
// @lc code=end


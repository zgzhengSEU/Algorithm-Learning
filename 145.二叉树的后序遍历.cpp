/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (74.84%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    273.8K
 * Total Submissions: 365.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        travPost_Iteration(root, ans);
        return ans;
    }
    void travPost_Iteration(TreeNode* root,vector<int> &visit){
        stack<TreeNode*> st;
        if(root)st.push(root);
        while(!st.empty()){
            if(root!=st.top()->left&&root!=st.top()->right)gotoHLVFL(st);
            root=st.top();st.pop();visit.push_back(root->val);
        }
    }
    void gotoHLVFL(stack<TreeNode*> &st){
        while(auto root=st.top()){
            if(root->left){
                if(root->right)st.push(root->right);
                st.push(root->left);
            }else{
                st.push(root->right);
            }
        }
        st.pop();
    }
};
// @lc code=end


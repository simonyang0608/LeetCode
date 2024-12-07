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
    int rob(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result maximun money)  //
        //=================================//

        /*Recursion-based DFS loop traversal*/
        vector<int> res_vect = dfsTraversal(root); //Recursion function call (i.e. root whole node)

        return *max_element(res_vect.begin(), res_vect.end());
    }


    vector<int> dfsTraversal(TreeNode * root)
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//
        if (! root) { return {0, 0}; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        vector<int> left_vect = dfsTraversal((root->left)); //Recursion function call (i.e. root left-half node)
        vector<int> right_vect = dfsTraversal((root->right)); //Recursion function call (i.e. root right-half node)

        return {(*max_element(left_vect.begin(), left_vect.end()) + *max_element(right_vect.begin(), right_vect.end())), ((root->val + left_vect[0] + right_vect[0]))};
    }
};

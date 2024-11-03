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
    TreeNode * sortedArrayToBST(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//
        if (! nums.size()) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record middle index /////
        int record_mid_idx = (nums.size() / 2);

        ///// Record vector (i.e. left, right-half) /////
        vector<int> record_left_vect(nums.begin(), (nums.begin() + record_mid_idx));
        vector<int> record_right_vect((nums.begin() + (record_mid_idx + 1)), (nums.begin() + nums.size()));


        /*Recursion-based loop traversal*/
        TreeNode * root = new TreeNode(nums[record_mid_idx]); //Root tree-node

        (root->left) = sortedArrayToBST(record_left_vect); //Recursion function call (i.e. root left-half tree-node)
        (root->right) = sortedArrayToBST(record_right_vect); //Recursion function call (i.e. root right-half tree-node)

        return root;
    }
};

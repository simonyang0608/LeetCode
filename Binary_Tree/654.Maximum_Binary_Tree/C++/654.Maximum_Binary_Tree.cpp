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
    TreeNode * constructMaximumBinaryTree(vector<int> & nums)  
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - TreeNode * (result tree-node)  //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record deque /////
        deque<TreeNode * > record_dq;


        /*Deque-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            TreeNode * record_node = new TreeNode(nums[nums_idx]); //Record tree-node

            while ((! record_dq.empty()) && (((record_dq.back())->val) < nums[nums_idx])) //Part
            {
                (record_node->left) = record_dq.back(); //Keep updating, overwriting

                record_dq.pop_back(); //Keep updating, popped

            } //Part

            ///// Check if the current deque is empty or not /////
            if (! record_dq.empty()) { ((record_dq.back())->right) = record_node; } //Keep updating, overwriting
            else { ; }

            record_dq.emplace_back(record_node); //Keep updating, recording

        } //Whole

        return record_dq.front();
    }
};

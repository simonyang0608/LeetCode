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
    int pathSum(TreeNode * root, int targetSum) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root tree-node)  //
        //   - int (target summary value)   //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<long long, int> record_map;

        record_map[0] = 1;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_map, 0, targetSum, res_cnter); //Recursion function call (i.e. whole root node)

        return res_cnter;
    }


    void dfsTraversal(TreeNode * root, unordered_map<long long, int> & record_map, long long record_prefix_sum, int & targetSum, int & res_cnter)
    {
        //=====================================================================//
        // Input type:                                                         //
        //   - TreeNode * (root tree-node)                                     //
        //   - unordered_map<long long, int> ref. (record dictionary, hashmap) //
        //   - int (record prefix-summary value)                               //
        //   - int ref. (target summary value)                                 //
        // Return type:                                                        //
        //   - void (no return)                                                //
        //=====================================================================//

        /*Initialize*/
        ///// Current prefix-summary value /////
        long long curr_prefix_sum = (record_prefix_sum + (root->val));

        /*Whole process, flow*/
        ///// Check if the current prefix-summary value existed or not /////
        if (record_map.find((curr_prefix_sum - targetSum)) != record_map.end())
        {
            res_cnter += record_map[(curr_prefix_sum - targetSum)]; //Keep updating, accumulating
        }

        ///// Check if the current prefix-summary value existed or not /////
        if (record_map.find(curr_prefix_sum) != record_map.end()) { record_map[curr_prefix_sum] += 1; } //Keep updating, recording
        else { record_map[curr_prefix_sum] = 1; } //Keep updating, recording

        if ((root->left)) { dfsTraversal((root->left), record_map, curr_prefix_sum, targetSum, res_cnter); } //Recursion function call (i.e. root left-half node)
        if ((root->right)) { dfsTraversal((root->right), record_map, curr_prefix_sum, targetSum, res_cnter); } //Recursion function call (i.e. root right-half node)

        record_map[curr_prefix_sum] -= 1; //Keep updating, recording
    }
};

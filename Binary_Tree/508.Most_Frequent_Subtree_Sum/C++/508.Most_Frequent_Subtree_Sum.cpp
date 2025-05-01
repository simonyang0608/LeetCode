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
    vector<int> findFrequentTreeSum(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record maximun summary counter /////
        int record_max_cnter = (-1);

        ///// Result vector /////
        vector<int> res_vect;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        int res_sum_val = dfsTraversal(root, record_map, record_max_cnter); //Recursion function call (i.e. whole root tree-node)

        for (auto record_ele = record_map.cbegin(); (record_ele != record_map.cend()); (record_ele++)) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if ((record_ele->second) != record_max_cnter) { continue; }
 
            res_vect.emplace_back((record_ele->first)); //Keep updating, recording

        } //Whole

        return res_vect;
    }


    int dfsTraversal(TreeNode * root, unordered_map<int, int> & record_map, int & record_max_cnter)
    {
        //===============================================================//
        // Input type:                                                   //
        //   - TreeNode * (root tree-node)                               //
        //   - unordered_map<int, int> ref. (record dictionary, hashmap) //
        // Return type:                                                  //
        //   - int (result summary value)                                //
        //===============================================================//
        if (root == nullptr) { return 0; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        int root_left_val = dfsTraversal((root->left), record_map, record_max_cnter); //Root left-half value
        int root_right_val = dfsTraversal((root->right), record_map, record_max_cnter); //Root right-half value

        int record_sum_val = ((root->val) + root_left_val + root_right_val); //Record summary value

        ((record_map[record_sum_val])++); //Update, Accumulate

        record_max_cnter = (record_map[record_sum_val] > record_max_cnter) ? record_map[record_sum_val] : record_max_cnter; //Update, Overwrite

        return record_sum_val;
    }
};

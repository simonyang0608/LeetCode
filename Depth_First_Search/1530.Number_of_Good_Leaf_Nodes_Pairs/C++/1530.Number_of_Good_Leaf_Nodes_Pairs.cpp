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
    int countPairs(TreeNode * root, int distance) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root tree-node)  //
        //   - int (distance value)         //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0; 

        /*Recursion-based DFS loop traversal*/
        vector<int> res_vect = dfsTraversal(root, distance, res_cnter); //Recursion function call (whole root-node)

        return res_cnter;
    }


    vector<int> dfsTraversal(TreeNode * root, int & distance, int & res_cnter)
    {
        //=======================================//
        // Input type:                           //
        //   - TreeNode * (root tree-node)       //
        //   - int ref. (distance value)         //
        //   - int ref. (result summary counter) //
        // Return type:                          //
        //   - vector<int> (result vector)       //
        //=======================================//
        if (! root) { return {}; } //Issue, Boundary-case handling

        if ((! (root->left)) && (! (root->right))) { return {1}; } //Issue, Boundary-case handling


        /*Initialize*/
        ///// Result vector /////
        vector<int> res_vect;

        /*Whole process, flow*/
        vector<int> left_dist_vect = dfsTraversal((root->left), distance, res_cnter); //Recursion function call (root left-half node)
        vector<int> right_dist_vect = dfsTraversal((root->right), distance, res_cnter); //Recursion function call (root right-half node)

        for (int left_dist_idx = (left_dist_vect.size() - 1); (left_dist_idx >= 0); (left_dist_idx--)) //Left-half
        {
            for (int right_dist_idx = (right_dist_vect.size() - 1); (right_dist_idx >= 0); (right_dist_idx--)) //Right-half
            {
                ///// Check if the current inner distance matched conditions or not /////
                if ((left_dist_vect[left_dist_idx] + right_dist_vect[right_dist_idx]) <= distance)
                {
                    (res_cnter++); //Keep updating, accumulating
                }
                else { ; }

            } //Right-half

        } //Left-half

        left_dist_vect.insert(left_dist_vect.end(), right_dist_vect.begin(), right_dist_vect.end()); //Concate operations

        for (int left_dist_idx = (left_dist_vect.size() - 1); (left_dist_idx >= 0); (left_dist_idx--)) //Left-half
        {
            ///// Check if the current inner distance matched conditions or not /////
            if ((left_dist_vect[left_dist_idx] + 1) <= distance) { res_vect.emplace_back((left_dist_vect[left_dist_idx] + 1)); } //Keep updating, recording
            else { ; }

        } //Left-half

        return res_vect;
    }
};

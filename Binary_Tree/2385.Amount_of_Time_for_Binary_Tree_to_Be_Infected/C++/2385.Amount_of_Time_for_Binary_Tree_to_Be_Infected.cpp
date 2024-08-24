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
    int dfsTraversal(TreeNode * root, int & start, int & res_times)
    {
        //==========================================//
        // Input type:                              //
        //   - TreeNode * root (root tree-node)     //
        //   - int ref. (start node, value)         //
        //   - int ref. (result maximun cost times) //
        // Return type:                             //
        //   - int (result cost times)              //
        //==========================================//
        if (! root) //Issue, Boundary-case handling
        {
            return 0;
        }

        /*Whole process, flow*/
        ///// Step 1: Recursion-based DFS loop traversal /////
        int root_left = dfsTraversal((root->left), start, res_times); //Resursion function call (i.e. root left-half node)
        int root_right = dfsTraversal((root->right), start, res_times); //Resursion function call (i.e. root right-half node)

        ///// Step 2: Check if the current root left, right-half node matched conditions or not /////
        if ((root->val) == start) //Start tree-node
        {
            res_times = max(res_times, max(root_left, root_right)); //Update, Overwrite

            return (-1);
        }

        else if ((root_left < 0) || (root_right < 0)) //Upon start tree-node
        {
            res_times = max(res_times, (abs(root_left) + abs(root_right))); //Update, Overwrite

            return (min(root_left, root_right) - 1);
        }

        else if ((root_left >= 0) && (root_right >= 0)) //Below start tree-node
        {
            res_times = max(res_times, (max(root_left, root_right) + 1)); //Update, Overwrite

            return (max(root_left, root_right) + 1);
        }

        return (100001);
    }


    int amountOfTime(TreeNode * root, int start) 
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        //   - int (start node, value)         //
        // Return type:                        //
        //   - int (result maximun cost times) //
        //=====================================//

        /*Initialize*/
        ///// Result maximun cost times /////
        int res_times = 0;

        /*Resursion-based DFS loop traversal*/
        int res_time = dfsTraversal(root, start, res_times); //Resursion function call (i.e. whole node)

        return res_times;
    }
};

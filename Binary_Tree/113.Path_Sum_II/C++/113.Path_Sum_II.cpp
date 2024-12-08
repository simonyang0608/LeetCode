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
    vector<vector<int>> pathSum(TreeNode * root, int targetSum) 
    {
        //=========================================//
        // Input type:                             //
        //   - TreeNode * (root tree-node)         //
        //   - int (target summary value)          //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Result vector /////
        vector<vector<int>> res_vect;

        if (! root) { return res_vect; } //Issue, Boundary-case handling

        ///// Record vector /////
        vector<int> record_vect = {(root->val)};


        /*Recursion-based DFS loop traversal with recorded vector*/
        dfsTraversal(root, record_vect, res_vect, targetSum); //Recursion function call (i.e. whole root node)

        return res_vect;
    }


    void dfsTraversal(TreeNode * root, vector<int> & record_vect, vector<vector<int>> & res_vect, int & targetSum)
    {
        //==============================================//
        // Input type:                                  //
        //   - TreeNode * (root tree-node)              //
        //   - vector<int> ref. (record vector)         //
        //   -  vector<vector<int> ref. (result vector) //
        //   - int ref. (target summary value)          //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//
        if ((! (root->left)) && (! (root->right))) //Issue, Boundary-case handling
        {
            ///// Check if the current summary matched conditions or not /////
            if (accumulate(record_vect.begin(), record_vect.end(), 0) == targetSum)
            {
                res_vect.push_back(record_vect); //Update, Record
            }
        }

        /*Whole process, flow*/
        if ((root->left))
        {
            record_vect.emplace_back(((root->left)->val)); //Update, Record

            dfsTraversal((root->left), record_vect, res_vect, targetSum); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right))
        {
            record_vect.emplace_back(((root->right)->val)); //Update, Record

            dfsTraversal((root->right), record_vect, res_vect, targetSum); //Recursion function call (i.e. root right-half node)
        }

        record_vect.pop_back(); //Update, Popped
    }
};

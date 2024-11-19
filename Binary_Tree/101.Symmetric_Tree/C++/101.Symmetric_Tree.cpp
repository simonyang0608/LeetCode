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
    bool isSymmetric(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if ((! (root->left)) && (! (root->right))) { return true; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result vector (i.e. left, right-half) /////
        vector<int> res_left_vect, res_right_vect;

        /*Recursion-based DFS loop traversal*/
        preorderLeft(root, root, res_left_vect); //Recursion function call (i.e. root left-half node)
        preorderRight(root, root, res_right_vect); //Recursion function call (i.e. root right-half node)

        return (res_left_vect == res_right_vect) ? true : false;
    }


    void preorderLeft(TreeNode * root, TreeNode * main_root, vector<int> & res_left_vect)
    {
        //================================================//
        // Input type:                                    //
        //   - TreeNode * (root tree-node)                //
        //   - TreeNode * (main root tree-node)           //
        //   - vector<int> ref. (result left-half vector) //
        // Return type:                                   //
        //   - void (no return)                           //
        //================================================//
        if (! root) //Issue, Boundary-case handling
        {
            res_left_vect.emplace_back((-1)); //Update, Record

            return;
        }

        /*Whole process, flow*/
        res_left_vect.emplace_back((root->val)); //Update, Record

        preorderLeft((root->left), main_root, res_left_vect); //Recursion function call (i.e. root left-half node)

        if (root == main_root) { return; } //Issue, Boundary-case handling

        preorderLeft((root->right), main_root, res_left_vect); //Recursion function call (i.e. root right-half node)
    }


    void preorderRight(TreeNode * root, TreeNode * main_root, vector<int> & res_right_vect)
    {
        //================================================//
        // Input type:                                    //
        //   - TreeNode * (root tree-node)                //
        //   - TreeNode * (main root tree-node)           //
        //   - vector<int> ref. (result right-half vector) //
        // Return type:                                   //
        //   - void (no return)                           //
        //================================================//
        if (! root) //Issue, Boundary-case handling
        {
            res_right_vect.emplace_back((-1)); //Update, Record

            return;
        }

        /*Whole process, flow*/
        res_right_vect.emplace_back((root->val)); //Update, Record

        preorderRight((root->right), main_root, res_right_vect); //Recursion function call (i.e. root right-half node)

        if (root == main_root) { return; } //Issue, Boundary-case handling

        preorderRight((root->left), main_root, res_right_vect); //Recursion function call (i.e. root left-half node)
    }
};

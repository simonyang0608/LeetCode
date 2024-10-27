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
    int dfsTraversal(TreeNode * root, vector<int> & res_vect)
    {
        //======================================//
        // Input type:                          //
        //   - TreeNode * (root tree-node)      //
        //   - vector<int> ref. (result vector) //
        // Return type:                         //
        //   - int (record size)                //
        //======================================//
        if (! root) { return (-1); } //Issue, Boundary-case handling

        if ((! (root->left)) && (! (root->right))) //Issue, Boundary-case handling
        {
            res_vect.emplace_back(1); //Update, Record

            return 1; 
        }


        /*Whole process, flow*/
        int root_left = dfsTraversal((root->left), res_vect); //Recursion function call (i.e. root left-half node)
        int root_right = dfsTraversal((root->right), res_vect); //Recursion function call (i.e. root right-half node)

        ///// Check if the current tree-node matched conditions or not /////
        if (((root_left == (-1)) || (root_right == (-1))) || (root_left != root_right)) //Not perfect sub-tree node
        {
            return (-1);
        }

        else if (root_left == root_right) //Is perfect sub-tree node
        {
            res_vect.emplace_back((root_left + root_right + 1)); //Update, Record

            return (root_left + root_right + 1);
        }

        return (-2);
    }


    int kthLargestPerfectSubtree(TreeNode * root, int k) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        //   - int (k-th largest size)     //
        // Return type:                    //
        //   - int (result target size)    //
        //=================================//

        /*initialize*/
        ///// Result vector /////
        vector<int> res_vect;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, res_vect); //Recursion function call (i.e. root whole node)

        ///// Check if the current vector matched conditions or not /////
        if (res_vect.size() < k) { return (-1); }

        sort(res_vect.begin(), res_vect.end(), greater<int>()); //Sorted operations

        return res_vect[(k - 1)];
    }
};

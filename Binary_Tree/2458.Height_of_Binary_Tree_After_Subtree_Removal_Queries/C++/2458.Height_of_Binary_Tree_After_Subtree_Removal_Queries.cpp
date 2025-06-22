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
    vector<int> treeQueries(TreeNode * root, vector<int> & queries) 
    {
        //=======================================//
        // Input type:                           //
        //   - TreeNode * (root tree-node)       //
        //   - vector<int> ref. (queries vector) //
        // Return type:                          //
        //   - vector<int> (result vector)       //
        //=======================================//

        /*Initialize*/
        ///// Length of queries vector /////
        int len_queries = queries.size();

        ///// Record dictionary, hashmaps (i.e. left, right) /////
        unordered_map<int, int> left_map, right_map;

        ///// Record maximun depths (i.e. left, right) /////
        int left_max_depth = 0, right_max_depth = 0;

        ///// Result vector /////
        vector<int> res_vect(len_queries);


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-roots informations with dictionary, hashmap /////
        dfsLeft(root, left_map, 0, left_max_depth); //Recursion function call (i.e. root left-half node)
        dfsRight(root, right_map, 0, right_max_depth); //Recursion function call (i.e. root right-half node)

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            res_vect[queries_idx] = max(left_map[queries[queries_idx]], right_map[queries[queries_idx]]); //Keep updating, overwriting

        } //Whole

        return res_vect;
    }


    void dfsLeft(TreeNode * root, unordered_map<int, int> & left_map, int left_depth, 
                 int & left_max_depth)
    {
        //==================================================================//
        // Input type:                                                      //
        //   - TreeNode * (root tree-node)                                  //
        //   - unordered_map<int, int> ref. (left-half dictionary, hashmap) //
        //   - int (left-half depth)                                        //
        //   - int ref. (maximun left-half depth)                           //
        // Return type:                                                     //
        //   - void (no return)                                             //
        //==================================================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        left_map[(root->val)] = left_max_depth; //Update, Overwrite

        left_max_depth = (left_depth > left_max_depth) ? left_depth : left_max_depth; //Update, Overwrite

        dfsLeft((root->left), left_map, (left_depth + 1), left_max_depth); //Recursion function call (i.e. root left-half node)
        dfsLeft((root->right), left_map, (left_depth + 1), left_max_depth); //Recursion function call (i.e. root right-half node)
    }


    void dfsRight(TreeNode * root, unordered_map<int, int> & right_map, int right_depth, 
                  int & right_max_depth)
    {
        //===================================================================//
        // Input type:                                                       //
        //   - TreeNode * (root tree-node)                                   //
        //   - unordered_map<int, int> ref. (right-half dictionary, hashmap) //
        //   - int (right-half depth)                                        //
        //   - int ref. (maximun right-half depth)                           //
        // Return type:                                                      //
        //   - void (no return)                                              //
        //===================================================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        right_map[(root->val)] = right_max_depth; //Update, Overwrite

        right_max_depth = (right_depth > right_max_depth) ? right_depth : right_max_depth; //Update, Overwrite

        dfsRight((root->right), right_map, (right_depth + 1), right_max_depth); //Recursion function call (i.e. root right-half node)
        dfsRight((root->left), right_map, (right_depth + 1), right_max_depth); //Recursion function call (i.e. root left-half node)
    }
};

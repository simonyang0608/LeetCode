class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        //====================================//
        // Input type:                        //
        //   - int (n-th completeness)        //
        // Return type:                       //
        //   - vector<string> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Result vector /////
        vector<string> res_vect;

        /*Back-track based loop traversal*/
        backtrackTraversal(n, 1, 0, "(", res_vect); //Recursion function call

        return res_vect;
    }


    void backtrackTraversal(int & n, int left_sider, int right_sider, string record_str, vector<string> & res_vect)
    {
        //=========================================//
        // Input type:                             //
        //   - int ref. (n-th completeness)        //
        //   - int (left-sider quantities)         //
        //   - int (right-sider quantities)        //
        //   - string (record string)              //
        //   - vector<string> ref. (result vector) //
        // Return type:                            //
        //   - void (no return)                    //
        //=========================================//
        if ((left_sider == n) && (right_sider == n)) //Issue, Boundary-case handling
        {
            res_vect.emplace_back(record_str); //Update, Record

            return;
        }

        /*Whole process, flow*/
        ///// Check if the current quantities matched conditions or not /////
        if (left_sider < n)
        {
            backtrackTraversal(n, (left_sider + 1), right_sider, (record_str + "("), res_vect); //Recursion function call (i.e. left-sider)
        }

        if (right_sider < left_sider)
        {
            backtrackTraversal(n, left_sider, (right_sider + 1), (record_str + ")"), res_vect); //Recursion function call (i.e. right-sider)
        }
    }
};

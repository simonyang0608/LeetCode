class Solution {
public:
    string longestPalindrome(string s) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. original, new) /////
        int len_new_s, len_s = s.size();

        ///// New string /////
        string new_s = "$#";

        for (int s_idx = 0; (s_idx < len_s); (s_idx++))
        {
            new_s += s[s_idx];
            new_s += '#';
        }

        new_s += '@';

        len_new_s = new_s.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record mirror, center, right-bound /////
        int record_mirror, record_center = record_trav_ptr, record_rbound = record_trav_ptr;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp(len_new_s, 0);

        ///// Result maximun index, radius /////
        int res_max_idx, res_max_rds = 0;


        /*Manacher-based loop traversal with recorded dynamic-programming vector*/
        while (record_trav_ptr < len_new_s) //Whole
        {
            record_mirror = ((2 * record_center) - record_trav_ptr); //Record mirror

            ///// Check if the current pointer matched conditions or not /////
            if ((record_trav_ptr < record_rbound) && ((record_trav_ptr + record_dp[record_mirror])) < record_rbound)
            {
                record_dp[record_trav_ptr] = record_dp[record_mirror]; //Keep updating, overwriting
            }

            else if ((record_trav_ptr < record_rbound) && ((record_trav_ptr + record_dp[record_mirror])) > record_rbound)
            {
                record_dp[record_trav_ptr] = (record_rbound - record_trav_ptr); //Keep updating, overwriting

                while (((((record_trav_ptr - record_dp[record_trav_ptr]) - 1) >= 0) && (((record_trav_ptr + record_dp[record_trav_ptr]) + 1) < len_new_s)) && (new_s[((record_trav_ptr - record_dp[record_trav_ptr]) - 1)] == new_s[((record_trav_ptr + record_dp[record_trav_ptr]) + 1)])) //Radius
                {
                    ((record_dp[record_trav_ptr])++); //Keep updating, accumulating

                } //Radius

                record_rbound = (record_trav_ptr + record_dp[record_trav_ptr]); //Keep updating, overwriting
                record_center = record_trav_ptr; //Keep updating, overwriting
            }

            else
            {
                record_dp[record_trav_ptr] = 0; //Keep updating, overwriting

                while (((((record_trav_ptr - record_dp[record_trav_ptr]) - 1) >= 0) && (((record_trav_ptr + record_dp[record_trav_ptr]) + 1) < len_new_s)) && (new_s[((record_trav_ptr - record_dp[record_trav_ptr]) - 1)] == new_s[((record_trav_ptr + record_dp[record_trav_ptr]) + 1)])) //Radius
                {
                    ((record_dp[record_trav_ptr])++); //Keep updating, accumulating

                } //Radius

                record_rbound = (record_trav_ptr + record_dp[record_trav_ptr]); //Keep updating, overwriting
                record_center = record_trav_ptr; //Keep updating, overwriting
            }

            ///// Check if the current radius is larger or not /////
            if (record_dp[record_trav_ptr] > res_max_rds) { res_max_rds = record_dp[record_trav_ptr]; res_max_idx = record_trav_ptr; } //Keep updating, overwriting
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return s.substr((((res_max_idx - record_dp[res_max_idx]) - 1) / 2), record_dp[res_max_idx]);
    }
};

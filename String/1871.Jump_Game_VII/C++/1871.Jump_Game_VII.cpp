class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        //=========================//
        // Input type:             //
        //   - string (s string)   //
        //   - int (minJump steps) //
        //   - int (maxJump steps) //
        // Return type:            //
        //   - bool (result flag)  //
        //=========================//
        if (s[(s.size() - 1)] == '1') { return false; } //Issue, Boundary-case handling
        if ((s.size() > minJump) && (s.size() <= (maxJump + 1))) { return true; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

       ///// Record dynamic-programming (i.e. DP) vector /////
       vector<int> record_dp(minJump, 1);

       ///// Record reached-differences /////
       int record_reach_diff;


       /*Dynamic-programming (i.e. DP) based loop traversal*/
       for (int s_idx = minJump; (s_idx < len_s); (s_idx++)) //Whole
       {
            record_reach_diff = 0; //Record reached-differences

            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '0')
            {
                record_reach_diff += record_dp[(s_idx - minJump)]; //Keep updating, accumualting

                ///// Check if the current indexes matched conditions or not /////
                if (s_idx > maxJump)
                {
                    record_reach_diff -= record_dp[(s_idx - maxJump - 1)]; //Keep updating, reducing
                }
                else { ; }
            }

            else { ; }

            ///// Check if the current differences matched conditions or not /////
            if (record_reach_diff) { record_dp.push_back((record_dp.back() + 1)); } //Keep updating, recording
            else { record_dp.push_back(record_dp.back()); } //Keep updating, recording

       } //Whole

       return (record_reach_diff) ? true : false;
    }
};

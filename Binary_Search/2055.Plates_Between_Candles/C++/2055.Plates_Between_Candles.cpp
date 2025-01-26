class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> & queries) 
    {
        //===============================================//
        // Input type:                                   //
        //   - string (s string)                         //
        //   - vector<vector<int>> ref. (queries vector) //
        // Return type:                                  //
        //   - vector<int> (result vector)               //
        //===============================================//

        /*Initialize*/
        ///// Length of s string, queries vector /////
        int len_s = s.size(), len_queries = queries.size();

        ///// Plates, Prefix-summary vectors /////
        vector<int> plates_vect, prefixSum_vect(len_s, 0);

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Record flag /////
        bool record_flag = false;

        ///// Result vector /////
        vector<int> res_vect(len_queries, 0);


        /*Binary-search based loop traversal with recorded prefix-summary vector*/
        ///// Step 1: Record summary counter with prefix-summary vector /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '*')
            {
                ///// Check if the current flag matched conditions or not /////
                if (! record_flag) { ; }
                else { (record_cnter++); } //Keep updating, accumulating
            }

            else
            {
                plates_vect.emplace_back(s_idx); //Keep updating, recording

                ///// Check if the current flag matched conditions or not /////
                if (! record_flag) { record_flag |= true; } //Keep updating, overwriting
                else { prefixSum_vect[s_idx] = record_cnter; } //Keep updating, overwriting
            }

        } //Whole

        ///// Step 2: Looped-traversal with recorded prefix-summary vector /////
        if (plates_vect.empty()) { return res_vect; } //Issue, Boundary-case handling

        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            int left_idx = binarySearch_left(plates_vect, (queries[queries_idx])[0]); //Left index
            int right_idx = binarySearch_right(plates_vect, (queries[queries_idx])[1]); //Right index

            ///// Check if the current index boundary is valid or not /////
            if (left_idx < right_idx) { res_vect[queries_idx] = (prefixSum_vect[right_idx] - prefixSum_vect[left_idx]); } //Keep updating, overwriting
            else { ; }

        } //Whole

        return res_vect;
    }


    int binarySearch_left(const vector<int> & plates_vect, const int & left_val)
    {
        //============================================//
        // Input type:                                //
        //   - const vector<int> ref. (plates vector) //
        //   - const int ref. (left value)            //
        // Return type:                               //
        //   - int (result left index)                //
        //============================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (plates_vect.size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            ///// Check if the current indexed-value is larger than target or not /////
            if (plates_vect[record_mid_ptr] >= left_val) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return plates_vect[record_left_ptr];
    }


    int binarySearch_right(const vector<int> & plates_vect, const int & right_val)
    {
        //============================================//
        // Input type:                                //
        //   - const vector<int> ref. (plates vector) //
        //   - const int ref. (right value)           //
        // Return type:                               //
        //   - int (result right index)               //
        //============================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (plates_vect.size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            ///// Check if the current indexed-value is larger than target or not /////
            if (plates_vect[record_mid_ptr] > right_val) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return plates_vect[record_left_ptr];
    }
};

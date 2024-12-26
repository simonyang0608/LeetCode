class Solution {
public:
    int hIndex(vector<int> & citations) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (citations vector) //
        // Return type:                            //
        //   - int (result maximun value)          //
        //=========================================//

        /*Initialize*/
        ///// Length of citations vector /////
        int len_citations = citations.size();

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (len_citations - 1);

        ///// Result maximun value /////
        int res_max_val = 0;


        /*Binary-search based loop traversal*/
        sort(citations.begin(), citations.end()); //Sorted operations

        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Keep updating, overwriting

            res_max_val = max(res_max_val, min((len_citations - record_mid_ptr), citations[record_mid_ptr])); //Keep updating, overwriting

            ///// Check if the current indexed-value matche conditions or not /////
            if (citations[record_mid_ptr] > (len_citations - record_mid_ptr)) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return res_max_val;
    }
};

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        //====================================//
        // Input type:                        //
        //   - int (n-th versions)            //
        // Return type:                       //
        //   - int (result first bad version) //
        //====================================//

        /*Initialize*/
        ///// Record two-pointers (i.e. left, right) /////
        long long record_left_ptr = 1, record_right_ptr = n;

        ///// Record middle pointer /////
        long long record_middle_ptr;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_middle_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (! isBadVersion(record_middle_ptr))
            {
                record_left_ptr = (record_middle_ptr + 1); //Keep updating, overwriting
            }

            else
            {
                if (record_middle_ptr == 1) { return (int)(record_middle_ptr); }
                else
                {
                    if (isBadVersion((record_middle_ptr - 1)))
                    {
                        record_right_ptr = (record_middle_ptr - 1); //Keep updating, overwriting
                    }
                    else { return (int)(record_middle_ptr); }
                }
            }

        } //Binary-search

        return (-1);
    }
};

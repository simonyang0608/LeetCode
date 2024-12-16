class Solution {
public:
    int maxScore(vector<int> & cardPoints, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (cardPoints vector) //
        //   - int (k-th times)                     //
        // Return type:                             //
        //   - int (result maximun score)           //
        //==========================================//

        /*Initialize*/
        ///// Length, Summary of cardPoints vector /////
        int len_cardPoints = cardPoints.size(), sum_cardPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (len_cardPoints == k) { return sum_cardPoints; } //Issue, Boundary-case handling

        ///// Record window-size /////
        int record_winsize = (len_cardPoints - k);

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record score /////
        int record_score = 0;

        ///// Result minimun score /////
        int res_min_score = (1e9 + 1);


        /*Sliding-window based loop traversal*/
        while (record_right_ptr < len_cardPoints) //Whole
        {
            record_score += cardPoints[record_right_ptr]; //Keep updating, accumulating

            ///// Check if the current window-size matched conditions or not /////
            if (((record_right_ptr - record_left_ptr) + 1) >= record_winsize)
            {
                res_min_score = min(res_min_score, record_score); //Keep updating, overwriting

                while (((record_right_ptr - record_left_ptr) + 1) >= record_winsize) //Part
                {
                    record_score -= cardPoints[(record_left_ptr++)]; //Keep updating, reducing

                } //Part
            }
            else { ; }

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return (sum_cardPoints - res_min_score);
    }
};

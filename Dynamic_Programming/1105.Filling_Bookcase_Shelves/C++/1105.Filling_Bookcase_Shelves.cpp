class Solution {
public:
    int minHeightShelves(vector<vector<int>> & books, int shelfWidth) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (books vector) // 
        //   - int (shelfWidth value)                  //
        // Return type:                                //
        //   - int (result minimun height)             //
        //=============================================//

        /*Initialize*/
        ///// Length of books vector /////
        int len_books = books.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((len_books + 1), 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int record_idx = 1; (record_idx <= len_books); (record_idx++)) //Whole
        {
            int book_width = (books[(record_idx - 1)])[0]; int book_height = (books[(record_idx - 1)])[1]; //Book width, height

            record_dp[record_idx] = (record_dp[(record_idx - 1)] + book_height); //Keep updating, overwriting

            for (int prev_idx = (record_idx - 2); ((prev_idx >= 0) && ((book_width + (books[prev_idx])[0]) <= shelfWidth)); (prev_idx--)) //Part
            {
                book_width += (books[prev_idx])[0]; //Keep updating, accumulating

                book_height = max(book_height, (books[prev_idx])[1]); //Keep updating, overwriting

                record_dp[record_idx] = min(record_dp[record_idx], (record_dp[prev_idx] + book_height)); //Keep updating, overwriting

            } //Part

        } //Whole

        return record_dp[len_books];
    }
};

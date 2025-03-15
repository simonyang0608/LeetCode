class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>> & tiles, int carpetLen) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (tiles vector) //
        //   - int (length of carpet)                  //
        // Return type:                                //
        //   - int (result maximun window-size)        //
        //=============================================//

        /*Initialize*/
        ///// Length of tiles vector /////
        int len_tiles = tiles.size();

        ///// Prefix-summary vector /////
        vector<int> prefix_sum((len_tiles + 1), 0);

        ///// Result maximun window-size /////
        int res_max_window = 0;


        /*Binary-search based loop traversal with recorded prefix-summary vector*/
        ///// Step 1: Record indexed-intervals with prefix-summary vector /////
        sort(tiles.begin(), tiles.end(), [&](const vector<int> & vect_1, const vector<int> & vect_2)
        {
            return (vect_1[0] < vect_2[0]);

        }); //Sorted-operations

        for (int tiles_idx = 1; (tiles_idx <= len_tiles); (tiles_idx++)) //Whole
        {
            prefix_sum[tiles_idx] += (prefix_sum[(tiles_idx - 1)] + ((((tiles[(tiles_idx - 1)])[1] - (tiles[(tiles_idx - 1)])[0])) + 1)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded prefix-summary vector /////
        for (int tiles_idx = 0; (tiles_idx < len_tiles); (tiles_idx++)) //Whole
        {
            int prev_edge = (((tiles[tiles_idx])[1] - carpetLen) + 1); //Previous edge

            ///// Check if the previous edge less than 1 or not /////
            if (prev_edge < 1) { prev_edge = 1; } //Keep updating, overwriting
            else { ; }

            int record_idx = binarySearch(len_tiles, tiles, prev_edge); //Record index

            int record_window = (prefix_sum[(tiles_idx + 1)] - prefix_sum[(record_idx + 1)]); //Record window

            ///// Check if the range of previous edge matched conditions or not /////
            if (prev_edge > (tiles[record_idx])[0]) { record_window += ((tiles[record_idx])[1] - prev_edge + 1); } //Keep updating, accumulating
            else { record_window += ((tiles[record_idx])[1] - (tiles[record_idx])[0] + 1); } //Keep updating, accumulating

            res_max_window = max(res_max_window, record_window); //Keep updating, overwriting

        } //Whole

        return res_max_window;
    }


    int binarySearch(const int & len_tiles, const vector<vector<int>> & tiles, const int & prev_edge)
    {
        //===================================================//
        // Input type:                                       //
        //   - const int ref. (length of tiles vector)       // 
        //   - const vector<vector<int>> ref. (tiles vector) //
        //   - const int ref. (previous edge)                //
        // Return type:                                      //
        //   - int (result index)                            //
        //===================================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_tiles - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            ///// Check if the current value matched conditions or not /////
            if ((tiles[record_mid_ptr])[1] >= prev_edge) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};

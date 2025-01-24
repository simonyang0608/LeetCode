class Solution {
public:
    int removeStones(vector<vector<int>> & stones) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (stones vector) //
        // Return type:                                 //
        //   - int (result maximun removal)             //
        //==============================================//

        /*Initialize*/
        ///// Length of stones vector /////
        int len_stones = stones.size();

        ///// Record dictionary, hashmap /////
        map<int, bool> record_map;

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        for (int stones_idx = 0; (stones_idx < len_stones); (stones_idx++)) //Whole
        {
            ///// Check if the current index is visited or not /////
            if (record_map[stones_idx]) { continue; }

            dfsTraversal(stones, len_stones, record_map, stones_idx); (res_min_cnter++); //Recursion function call
        }

        return (len_stones - res_min_cnter);
    }


    void dfsTraversal(vector<vector<int>> & stones, const int & len_stones, map<int, bool> & record_map, int record_idx)
    {
        //======================================================//
        // Input type:                                          //
        //   - vector<vector<int>> ref. (stones vector)         //
        //   - const int ref. (length of stones vector)         //
        //   - map<int, bool> ref. (record dictionary, hashmap) //
        //   - int (record index)                               //
        // Return type:                                         //
        //   - void (no return)                                 //
        //======================================================//

        /*Whole process, flow*/
        record_map[record_idx] = true; //Update, Record

        for (int stones_idx = 0; (stones_idx < len_stones); (stones_idx++)) //Whole
        {
            ///// Check if the current index is visited or not /////
            if (record_map[stones_idx]) { continue; }

            ///// Check if the current rows or columns is shared or not /////
            if (((stones[stones_idx])[0] == (stones[record_idx])[0]) || ((stones[stones_idx])[1] == (stones[record_idx])[1]))
            {
                dfsTraversal(stones, len_stones, record_map, stones_idx); //Recursion function call
            }

        } //Whole
    }
};

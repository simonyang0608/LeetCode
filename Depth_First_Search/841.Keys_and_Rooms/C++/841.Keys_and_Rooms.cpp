class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> & rooms) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (rooms vector) //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Length of rooms vector /////
        int len_rooms = rooms.size();

        ///// Record dictionary, hashmap /////
        map<int, bool> record_map;

        ///// Record node /////
        int record_node = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        dfsTraversal(rooms, record_map, record_node, res_cnter); //Recursion function call

        return (res_cnter == len_rooms) ? true : false;
    }


    void dfsTraversal(vector<vector<int>> & rooms, map<int, bool> & record_map, int & record_node, int & res_cnter)
    {
        //======================================================//
        // Input type:                                          //
        //   - vector<vector<int>> ref. (rooms vector)          //
        //   - map<int, bool> ref. (record dictionary, hashmap) //
        //   - int ref. (record node)                           //
        //   - int (result summary counter)                     //
        // Return type:                                         //
        //   - void (no return)                                 //
        //======================================================//
        if (record_map[record_node]) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        record_map[record_node] = true; //Update, Record

        (res_cnter++); //Update, Accumulate

        for (int & next_node: rooms[record_node]) //Whole
        {
            dfsTraversal(rooms, record_map, next_node, res_cnter); //Recursion function call

        } //Whole
    }
};

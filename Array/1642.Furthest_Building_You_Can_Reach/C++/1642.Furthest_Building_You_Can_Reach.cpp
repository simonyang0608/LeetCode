class Solution {
public:
    int furthestBuilding(vector<int> & heights, int bricks, int ladders) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (heights vector) //
        //   - int (bricks quantity)             //
        //   - int (ladders quantity)            //
        // Return type:                          //
        //   - int (result maximun index)        //
        //=======================================//

        /*Initialize*/
        ///// Length of heights vector /////
        int len_heights = heights.size();

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;


        /*Heap, Priority-queue based loop traversal*/
        for (int heights_idx = 1; (heights_idx < len_heights); (heights_idx++)) //Whole
        {
            ///// Check if the current heights difference matched conditions or not /////
            if (heights[heights_idx] <= heights[(heights_idx - 1)]) { continue; }

            record_pq.push((heights[heights_idx] - heights[(heights_idx - 1)])); //Keep updating, recording

            ///// Check if the current ladders enough or not /////
            if (record_pq.size() > ladders)
            {
                ///// Check if the current bricks enough or not /////
                if (record_pq.top() > bricks) { return (heights_idx - 1); }

                bricks -= record_pq.top(); //Keep updating, reducing

                record_pq.pop(); //Keep updating, popped
            }
            else { ; }

        } //Whole

        return (len_heights - 1);
    }
};

class Solution {
public:
    int minGroups(vector<vector<int>> & intervals) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<vector<int>> ref. (intervals vector) //
        // Return type:                                    //            
        //   - int (result minimun groups)                 //
        //=================================================//

        /*Initialize*/
        ///// Length of intervals vector /////
        int len_intervals = intervals.size();

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;


        /*Heap, Priority-queue based loop traversal with sorted-operations*/
        sort(intervals.begin(), intervals.end(), [&](const vector<int> & vect1, const vector<int> & vect2)
        {
            return (vect1[0] < vect2[0]);

        }); //Sorted-operations

        for (int intervals_idx = 0; (intervals_idx < len_intervals); (intervals_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((! record_pq.empty()) && ((intervals[intervals_idx])[0] > record_pq.top()))
            {
                record_pq.pop(); //Keep updating, popped
            }
            else { ; }

            record_pq.emplace((intervals[intervals_idx])[1]); //Keep updating, recording

        } //Whole

        return record_pq.size();
    }
};

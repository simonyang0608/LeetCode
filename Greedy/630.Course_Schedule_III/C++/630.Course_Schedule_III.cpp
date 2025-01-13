class Solution {
public:
    int scheduleCourse(vector<vector<int>> & courses) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<int>> ref. (courses vector) //
        // Return type:                                  //
        //   - int (result maximun summary counter)      //
        //===============================================//

        /*Initialize*/
        ///// Length of courses vector /////
        int len_courses = courses.size();

        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq;

        ///// Record summary value /////
        int record_sum_val = 0;


        /*Heap, Priority-queue based loop traversal with sorted vector*/
        sort(courses.begin(), courses.end(), [](const vector<int> & course_1, const vector<int> & course_2)
        {
            return (course_1[1] < course_2[1]);

        }); //Sorted operations

        for (int courses_idx = 0; (courses_idx < len_courses); (courses_idx++)) //Whole
        {
            ///// Check if the current summary value exceed boundary or not /////
            if ((record_sum_val + (courses[courses_idx])[0]) <= (courses[courses_idx])[1])
            {
                record_sum_val += (courses[courses_idx])[0]; //Keep updating, accumulating

                record_pq.push((courses[courses_idx])[0]); //Keep updating, recording
            }
            else
            {
                ///// Check if the previous maximun value matched conditions or not /////
                if ((! record_pq.empty()) && (record_pq.top() > (courses[courses_idx])[0]))
                {
                    record_sum_val -= record_pq.top(); record_pq.pop(); //Keep updating, popped

                    record_sum_val += (courses[courses_idx])[0]; record_pq.push((courses[courses_idx])[0]); //Keep updating, accumulating
                }
                else { ; }
            }

        } //Whole

        return record_pq.size();
    }
};

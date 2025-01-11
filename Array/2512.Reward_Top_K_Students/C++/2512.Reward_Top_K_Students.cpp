class Solution {
public:
    vector<int> topStudents(vector<string> & positive_feedback, vector<string> & negative_feedback, vector<string> & report, vector<int> & student_id, int k) 
    {
        //====================================================//
        // Iput type:                                         //
        //   - vector<string> ref. (positive_feedback vector) //
        //   - vector<string> ref. (negative_feedback vector) //
        //   - vector<string> ref. (report vector)            //
        //   - vector<int> ref. (student_id vector)           //
        //   - int (k-th order)                               //
        // Return type:                                       //
        //   - vector<int> (result vector)                    //
        //====================================================//

        /*Initialize*/
        ///// Length of vectors (i.e. positive, negative feedback) /////
        int len_pfb = positive_feedback.size(), len_nfb = negative_feedback.size();

        ///// Length of report vector /////
        int len_report = report.size();

        ///// Record dictionary, hashmaps (i.e. positive, negative feedback) /////
        map<string, int> record_pmap, record_nmap;

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        ///// Result vector /////
        vector<int> res_vect;


        /*Heap, Priority-queue based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-string with dictionary, hashmap /////
        for (int record_pidx = 0; (record_pidx < len_pfb); (record_pidx++)) //Whole
        {
            record_pmap[positive_feedback[record_pidx]] = 3; //Keep updating, recording

        } //Whole

        for (int record_nidx = 0; (record_nidx < len_nfb); (record_nidx++)) //Whole
        {
            record_nmap[negative_feedback[record_nidx]] = (-1); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int report_idx = 0; (report_idx < len_report); (report_idx++)) //Whole
        {
            string record_str; int record_score = 0; int len_str = (report[report_idx]).size(); //Record string informations

            for (int str_idx = 0; (str_idx < len_str); (str_idx++)) //Part
            {
                ///// Check if it's the end point of string or not /////
                if ((report[report_idx])[str_idx] == ' ')
                {
                    record_score += record_pmap[record_str]; //Keep updating, accumulating
                    record_score += record_nmap[record_str]; //Keep updating, accumulating

                    record_str.clear(); //Keep updating, reset

                    continue;
                }

                record_str += (report[report_idx])[str_idx]; //Keep updating, recording

            } //Part

            record_score += record_pmap[record_str]; //Keep updating, accumulating
            record_score += record_nmap[record_str]; //Keep updating, accumulating

            record_pq.push(make_pair(record_score, (student_id[report_idx] * (-1)))); //Keep updating, recording

        } //Whole

        ///// Step 3: Post-process, Final completions /////
        while ((k--)) //K-th times
        {
            res_vect.emplace_back((record_pq.top()).second * (-1)); //Keep updating, recording

            record_pq.pop(); //Keep updating, popped

        } //K-th times

        return res_vect;
    }
};

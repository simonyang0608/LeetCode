class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> & equations, vector<double> & values, vector<vector<string>> & queries) 
    {
        //====================================================//
        // Input type:                                        //
        //   - vector<vector<string>> ref. (equations vector) //
        //   - vector<double> ref. (values vector)            //
        //   - vector<vector<string>> ref. (queries vector)   //
        // Return type:                                       //
        //   - vector<double> (result vector)                 //
        //====================================================//

        /*Initialize*/
        ///// Length of equations, queries /////
        int len_equal = equations.size(), len_queries = queries.size();

        ///// Record, Traversal hashmap, dictionary /////
        unordered_map<string, vector<pair<string, double>>> record_map;
        unordered_map<string, bool> record_trav_map;

        ///// Record vector /////
        vector<string> record_vect;

        ///// Result vector /////
        vector<double> res_vect;


        /*DFS & BFS based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record indexed-string with hashmap, dictionary /////
        for (int equal_idx = 0; (equal_idx < len_equal); (equal_idx++)) //Whole
        {
            record_vect = equations[equal_idx]; //Record vector

            (record_map[record_vect[0]]).push_back(make_pair(record_vect[1], values[equal_idx])); //Keep updating, recording
            (record_map[record_vect[1]]).push_back(make_pair(record_vect[0], (1 / values[equal_idx]))); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded hashmap /////
        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            record_vect = queries[queries_idx]; //Record vector

            res_vect.emplace_back(dfsbfsTraversal(record_map, record_vect[0], record_vect[1], record_trav_map, 1.0)); //Recursion function call

            record_trav_map.clear(); //Reset

        } //Whole

        return res_vect;
    }


    double dfsbfsTraversal(unordered_map<string, vector<pair<string, double>>> & record_map, string start_query, string & end_query, unordered_map<string, bool> & record_trav_map, double res_scl)
    {
        //===========================================================================================//
        // Input type:                                                                               //
        //   - unordered_map<string, vector<pair<string, double>>> ref. (record hashmap, dictionary) //
        //   - string (start query-string)                                                           //
        //   - string ref. (end query-string)                                                        //
        //   - unordered_map<string, bool> ref. (record traversal hashmap, dictionary)               //
        //   - double (result scaling-factor)                                                        //
        // Return type:                                                                              //
        //   - double (result scaling-factor))                                                       //
        //===========================================================================================//
        if ((record_map.find(start_query) ==  record_map.end()) || ((record_map.find(end_query) ==  record_map.end()))) //Issue, Boundary-case handling
        {
            return (-1.0);
        }

        if (start_query == end_query) //Issue, Boundary-case handling
        {
            return res_scl;
        }

        /*Initialize*/
        ///// Result scaling-factor /////
        double res;

        /*Whole process, flow*/
        record_trav_map[start_query] = true; //Update, Record

        for (pair<string, double> sub_pair: record_map[start_query]) //Whole
        {
            ///// Check if the current indexed-element existed or not /////
            if (record_trav_map.find(sub_pair.first) == record_trav_map.end())
            {
                res = dfsbfsTraversal(record_map, sub_pair.first, end_query, record_trav_map, (res_scl * sub_pair.second)); //Recursion fucntion call

                ///// Check if the current scaling-factor matched conditions or not /////
                if (res != (-1.0)) { return res; }
            }

        } //Whole

        return (-1.0);
    }
};

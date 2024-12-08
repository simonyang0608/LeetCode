/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * cloneGraph(Node * node) 
    {
        //================================//
        // Input type:                    //
        //   - Node * (graph node)        //
        // Return type:                   //
        //   - Node * (result graph node) //
        //================================//
        if (! node) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<int, Node * > record_map;

        return dfsTraversal(node, record_map); //Recursion function call (i.e. whole graph node)
    }


    Node * dfsTraversal(Node * node, unordered_map<int, Node *> & record_map)
    {
        //==================================================================//
        // Input type:                                                      // 
        //   - Node * (graph node)                                          //
        //   - unordered_map<int, Node *> ref. (record dictionary, hashmap) //
        // Return type:                                                     //
        //   - Node * (result graph node)                                   //
        //==================================================================//
        if (record_map.find((node->val)) != record_map.end()) { return record_map[(node->val)]; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        Node * res_node = new Node((node->val)); //Result node

        record_map[(node->val)] = res_node; //Update, Record

        for (Node * record_node: (node->neighbors)) //Whole
        {
            (res_node->neighbors).push_back(dfsTraversal(record_node, record_map)); //Keep updating, recording

        } //Whole

        return res_node;
    }
};

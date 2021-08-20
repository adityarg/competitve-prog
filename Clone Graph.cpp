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
    Node* cloneGraph(Node* curr, map<int,Node*>& m)
    {
        if(curr==NULL) return NULL;
        if(m.find(curr->val)==m.end())
        {
            Node* curr_cln = new Node(curr->val);
            m[curr->val]=curr_cln;
            for(auto it:curr->neighbors)
            {
                Node* cln=cloneGraph(it,m);
                curr_cln->neighbors.push_back(cln);
            }
        }
        return m[curr->val];
    }
    Node* cloneGraph(Node* node)
    {
        map<int,Node*> m;
        return cloneGraph(node,m);
    }
};
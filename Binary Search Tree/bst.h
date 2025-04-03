#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

class BST {
public:
    BST();
    //~BST();
    bool insert(string str); 
    int size() const; 
    bool find(string str) const; 
    void print(vector<string> &values) const; 
    void breadth(vector<string> &values) const;
    double distance() const; 
    int balanced() const; 
    void rebalance(); 

private:
    struct Node {
        string data;
        Node *left;
        Node *right;
        Node(string str) : data(str), left(NULL), right(NULL) {}
    };
    Node *m_root;

    // Private helper functions
    bool insert(string str, Node *&cur_root);
    int size(Node *cur_root) const;
    bool find(string str, Node *cur_root) const;
    void print(Node *cur_root, vector<string> &values) const;
    double distance(Node *cur_root, int current_depth, double &total_distance, int &num_nodes) const;
    int balanced(Node *cur_root) const;
    void clear(Node *cur_root);
    void insert_from_vector(vector<string> &elements, int start_index, int end_index);
};

#endif
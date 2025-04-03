#include "bst.h"


BST::BST() : m_root(NULL) {}
/*

BST::~BST() {
    clear(m_root);
}
*/
//didnt use destruct
using namespace std;

void BST::clear(Node *cur_root) {
    if (cur_root != NULL) {

        clear(cur_root->left);
        clear(cur_root->right);

        delete cur_root;
    }
}

bool BST::insert(string str) {

    return insert(str, m_root);
}

bool BST::insert(string str, Node *&cur_root) {
    
    if (cur_root == NULL) {
        cur_root = new Node(str);
        //cout <<"Test";
        return true;

    } else if (str < cur_root->data) {

        return insert(str, cur_root->left);
    } else if (str > cur_root->data) {

        return insert(str, cur_root->right);
    } else {

        return false; // Duplicate string
    }
}

int BST::size() const {

    return size(m_root);
}

int BST::size(Node *cur_root) const {
    if (cur_root == NULL) {
        return 0;
    }
    return 1 + size(cur_root->left) + size(cur_root->right);
}

bool BST::find(string str) const {

    return find(str, m_root);
}

bool BST::find(string str, Node *cur_root) const {

    if (cur_root == NULL) {
        return false; 

    } else if (str < cur_root->data) {

        return find(str, cur_root->left);
    } else if (str > cur_root->data) {

        return find(str, cur_root->right);
    } else {

        return true; // Found the string
    }
}

void BST::print(vector<string> &values) const {

    print(m_root, values);
}

void BST::print(Node *cur_root, vector<string> &values) const {
    if (cur_root != NULL) {

        print(cur_root->left, values);

        values.push_back(cur_root->data);
        print(cur_root->right, values);
    }
}

void BST::breadth(vector<string> &values) const {
    if (m_root == NULL) {

        return;
    }

    queue<Node*> q;

    q.push(m_root);

    while (!q.empty()) {

        Node* cur = q.front();
        q.pop();

        values.push_back(cur->data);

        if (cur->left != NULL) {

            q.push(cur->left);
        }
        if (cur->right != NULL) {

            q.push(cur->right);
        }
    }
}

double BST::distance() const {
    double total_distance = 0;
    int num_nodes = 0;
    distance(m_root, 0, total_distance, num_nodes);
    return (num_nodes == 0) ? 0 : total_distance / num_nodes;
}

double BST::distance(Node *cur_root, int current_depth, double &total_distance, int &num_nodes) const {
    if (cur_root == NULL) {
        return 0; 
    }

    total_distance += current_depth;
    num_nodes++;

    distance(cur_root->left, current_depth + 1, total_distance, num_nodes);
    distance(cur_root->right, current_depth + 1, total_distance, num_nodes);

    return total_distance; 
}

int BST::balanced() const {
    return balanced(m_root);
}

int BST::balanced(Node *cur_root) const {
    if (cur_root == NULL) {
        return 0; // Empty subtree is balanced
    }

    int left_height = balanced(cur_root->left);
    int right_height = balanced(cur_root->right);

    if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1) {
        return -1; // Not balanced
    }

    return max(left_height, right_height) + 1; 
}

void BST::rebalance() {
    
    vector<string> values;
    print(values); // Get sorted values

    clear(m_root);  // Clear the existing tree
    m_root = NULL;

    insert_from_vector(values, 0, values.size() - 1);
}

void BST::insert_from_vector(vector<string> &elements, int start_index, int end_index) {
    if (start_index > end_index) {
        return; // Base case: empty range
    }

    if (start_index == end_index) {
        insert(elements[start_index]); // Base case: single element
        return;
    }

    int middle_index = start_index + (end_index - start_index) / 2; 
    insert(elements[middle_index]);

    insert_from_vector(elements, start_index, middle_index - 1);
    insert_from_vector(elements, middle_index + 1, end_index);
}
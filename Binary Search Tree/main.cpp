#include <iostream>
#include <vector>
#include "bst.h"
#include <limits>


using namespace std;

// Helper function to print vectors in the required format
void printVector(const vector<string> &v) {
    cout << "{";

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }

    }
    cout << "}\n";
}

int main() {
    BST tree;
    string command, argument;

    while (cin >> command) {
        if (command == "echo") {

            getline(cin, argument); // Read the rest of the linessss
            argument.erase(0,1);
            cout << argument << endl; 
            
            //insert da stuff and dont read cause noit ekko
        } else if (command == "insert") {
            getline(cin, argument);
            argument.erase(0,1);
            
            if (!tree.insert(argument)) {
                cerr << "insert <" << argument << "> failed. String already in tree.\n";
            }
        } else if (command == "size") {
            cout << tree.size() << endl;

        } else if (command == "find") {
            getline(cin, argument);
            argument.erase(0,1);
            if (tree.find(argument)) {
                cout << "<" << argument << "> is in tree.\n";
            } else {
                cout << "<" << argument << "> is not in tree.\n";
            }

        } else if (command == "print") {

            vector<string> values;
            tree.print(values);

            printVector(values);
        } else if (command == "breadth") {

            vector<string> values;
            tree.breadth(values);
            printVector(values);

        } else if (command == "distance") {

            cout << "Average distance of nodes to root = " << tree.distance() << endl;


        } else if (command == "balanced") {

            if (tree.balanced() != -1) {
                cout << "Tree is balanced.\n";
            } else {
                cout << "Tree is not balanced.\n";
            }


        } else if (command == "rebalance") {
            tree.rebalance();

        } else {
            cerr << "Illegal command <" << command << ">.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the rest of the line

        }
    }

    return 0;
}
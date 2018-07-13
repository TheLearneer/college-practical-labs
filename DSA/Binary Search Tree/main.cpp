/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: July 13, 2018
 */

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int n, Node *le, Node *ri) {data=n;left=le;right=ri;}
};

class BST {
private:
    Node *root;
    bool starting;

    Node* rightmostLeft(Node *pos) {
        Node *curr = pos;
        // going to the left side of the branch
        curr = curr->left;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        return curr;
    }

    Node* searchPreviousNode(int n) {
        Node *curr = root;
        Node *before;
        while (curr != NULL) {
            if (n == curr->data) return before;
            else {
                before = curr;
                if (n < curr->data) curr = curr->left;
                else curr = curr->right;
            }
        }
    }

public:
    BST() {root=NULL;starting=true;}

    Node* searchData(int n) {
        Node *curr = root;
        while (curr != NULL) {
            if (n == curr->data) return curr;
            else if (n < curr->data) curr = curr->left;
            else curr = curr->right;
        }
    }

    void insertData(int n) {
        Node *curr = root;
        Node *temp;
        if (starting) {
            root = new Node(n, NULL, NULL);
            starting = false;
            cout << "Inserterd " << n << " at root." << endl;
            return;
        }
        while (curr != NULL && !starting) {
            temp = curr;
            if (curr->data == n) {
                cout << "Oops tree can't have duplicate values." << endl;
                return;
            } else if(n < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        curr = new Node(n, NULL, NULL);
        if (n < temp->data) {
            cout << "Inserterd " << n << " at left of " << temp->data << "." << endl;
            temp->left = curr;
        } else {
            cout << "Inserterd " << n << " at right of " << temp->data << "." << endl;
            temp->right = curr;
        }
    }

    void removeData(int n) {
        Node *curr = searchData(n);
        Node *previous = searchPreviousNode(n);
        // condition for leaf node
        if (curr->right == NULL && curr->left == NULL ) {
            cout << "Removed " << curr->data << endl;
            if (previous->right && previous->right->data == curr->data) previous->right = NULL;
            else previous->left = NULL;
        } // condition for single branch node, more specifically for node which has only left branch
        else if (curr->right == NULL && curr->left != NULL) {
            cout << "Replaced " << curr->data << " with " << curr->left->data << endl;
            cout << "Removed " << curr->data << endl;
            if (previous->right && previous->right->data == curr->data) previous->right = curr->left;
            else previous->left = curr->left;
        } // condition for single branch node, more specifically for node which has only right branch
        else if(curr->left == NULL && curr->right != NULL) {
            cout << "Replaced " << curr->data << " with " << curr->right->data << endl;
            cout << "Removed " << curr->data << endl;
            if (previous->right && previous->right->data == curr->data) previous->right = curr->right;
            else previous->left = curr->right;
        } // condition for double branch node.
        else {
            Node *rmost = rightmostLeft(curr);
            removeData(rmost->data);
            cout << "Replaced " << curr->data << " with " << rmost->data << endl;
            cout << "Removed " << curr->data << endl;
            curr->data = rmost->data;
        }
    }
};

int main() {
    // declaring the class variable
    BST tree;
    // inserting all the required data
    tree.insertData(7);
    tree.insertData(15);
    tree.insertData(3);
    tree.insertData(9);
    tree.insertData(6);
    tree.insertData(8);
    tree.insertData(14);
    tree.insertData(16);
    tree.insertData(21);
    tree.insertData(18);
    tree.insertData(20);
    tree.insertData(22);
    tree.insertData(2);
    tree.insertData(1);
    tree.insertData(12);
    // removing the selected data
    //tree.removeData(7);
    tree.removeData(18);
    return 0;
}

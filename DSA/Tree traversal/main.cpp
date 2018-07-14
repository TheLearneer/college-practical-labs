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

class TreeParser {
private:
    Node *root;
    bool starting;

public:
    TreeParser() {root=NULL;starting=true;}

    Node* rootNode() {
        return root;
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

    // NLR i.e. Node-Left-Right
    void parsePreOrder(Node *node) {
        if (node == NULL) return;

        cout << node->data << ", ";
        parsePreOrder(node->left);
        parsePreOrder(node->right);
    }

    // LNR i.e Left-Node-Right
    void parseInOrder(Node *node) {
        if (node == NULL) return;

        parseInOrder(node->left);
        cout << node->data << ", ";
        parseInOrder(node->right);
    }

    // LRN i.e Left-Right-Node
    void parsePostOrder(Node *node) {
        if (node == NULL) return;

        parsePostOrder(node->left);
        parsePostOrder(node->right);
        cout << node->data << ", ";
    }
};

int main() {
    // declaring the class variable
    TreeParser tree;
    // inserting all the required data
    tree.insertData(10);
    tree.insertData(7);
    tree.insertData(25);
    tree.insertData(5);
    tree.insertData(8);
    tree.insertData(20);
    tree.insertData(50);
    tree.insertData(3);
    tree.insertData(15);
    tree.insertData(30);
    cout << "Parsing in pre order:" << endl;
    tree.parsePreOrder(tree.rootNode());
    cout << endl << "Parsing in In order:" << endl;
    tree.parseInOrder(tree.rootNode());
    cout << endl << "Parsing in Post order:" << endl;
    tree.parsePostOrder(tree.rootNode());
    return 0;
}

/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: July 4, 2018
 */
#include <iostream>

using namespace std;

class Node {
public:
    Node *previous;
    int data;
    Node *next;

    Node(Node *pre, int d, Node *nxt) {
        previous = pre;
        data = d;
        next = nxt;
    }
};

class DoubleLinkedList {
private:
    Node *start;

public:
    DoubleLinkedList() {
        start = NULL;
    }

    void insertAtBeginning(int n) {
        Node *_new = new Node(NULL, n, start);
        start = _new;
        if (_new->next != NULL) {
            Node *oldFirst = _new->next;
            oldFirst->previous = _new;
        }
    }

    void insertAtAnyPoint(int pos, int n) {
        Node *temp = start;
        // upto pos - 2 because loop starts from 0 index, and also because user enters position starting from index 1
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        Node *anyPos = new Node(temp, n, temp->next);
        temp->next = anyPos;
    }

    void insertAtEnd(int n) {
        Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node *_end = new Node(temp, n, NULL);
        temp->next = _end;
    }

    // This function is just to test if all the functions and functionality work as inteneded
    void display() {
        Node *node = start;
        while (node->next != NULL) {
            cout << "Address: " << node << ", Previous: " << node->previous << ", Data: " << node->data << ", Next: " << node->next << endl;
            node = node->next;
        }
        // This line below is needed to display the last node.
        cout << "Address: " << node << ", Previous: " << node->previous << ", Data: " << node->data << ", Next: " << node->next << endl;
    }
};

int main() {
    DoubleLinkedList mylist;
    mylist.insertAtBeginning(2);
    mylist.insertAtBeginning(1);
    mylist.insertAtAnyPoint(3,3);
    mylist.insertAtEnd(4);
    mylist.display();
    return 0;
}

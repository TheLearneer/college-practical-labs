/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: July 6, 2018
 */

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int n, Node *nextp) { data=n; next=nextp;}
};

class SingleLinkedList {
private:
    Node *start;

public:
    SingleLinkedList() {start=NULL;}

    void insertAtBeginning(int n) {
        Node *_first = new Node(n, start);
        start = _first;
    }

    void removeFromBeginning() {
        Node *newStart = start->next;
        start = newStart;
    }

    void insertAtAnyPoint(int loc, int data) {
        Node *temp = start;
        Node *before;
        for (int i=0; i<loc-1; i++) {
            before = temp;
            temp = temp->next;
        }
        Node *_mid = new Node(data, temp);
        before->next = _mid;
    }

    void removeFromAnyPoint(int pos) {
        Node *temp = start;
        Node *before;
        for (int i=0; i<pos-1; i++) {
            before = temp;
            temp = temp->next;
        }
        before->next = temp->next;
    }

    void insertAtEnd(int data) {
       Node *temp = start;
       Node *before;
       while (temp->next != NULL) {
           temp = temp->next;
       }
       // below two lines are to get to the last node.
       before = temp;
       temp = temp->next;
       Node *last = new Node(data, NULL);
       before->next = last;
    }

    void removeFromEnd() {
        Node *temp = start;
        Node *before;
        while (temp->next != NULL) {
            before = temp;
            temp = temp->next;
        }
        before->next = NULL;
    }

    void display() {
       Node *node = start;
       while (node->next != NULL) {
           cout << "Address: " << node << ", Data: " << node->data << ", Next: " << node->next << endl;
           node = node->next;
       }
       // This line below is needed to display the last node.
       cout << "Address: " << node << ", Data: " << node->data << ", Next: " << node->next << endl;
    }
};

int main() {
    SingleLinkedList sList;
    sList.insertAtBeginning(4);
    sList.insertAtBeginning(1);
    sList.insertAtAnyPoint(2,3);
    sList.insertAtAnyPoint(2,2);
    sList.insertAtEnd(5);
    sList.removeFromBeginning();
    sList.removeFromAnyPoint(2);
    sList.removeFromEnd();
    sList.display();
}

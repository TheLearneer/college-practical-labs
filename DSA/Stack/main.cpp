/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: June 27, 2018
 * NOTE:
 * This program uses custom implementation of statck and few other things, its done to learn how they work in actual and nothing else.
 */
 
#include <iostream>

using namespace std;

class Stack {
private:
    int values[2];
    int top;

public:
    Stack() {
        top = 0;
    }

    void push(int num) {
        if (top == 50) throw "Stack is full.";
        values[top] = num;
        top += 1;
    }

    int pop() {
        if (top == 0) throw "Stack is empty.";
        top -= 1;
        return values[top];
    }
};

int main() {
    try{
        Stack myStack;
        myStack.push(2);
        myStack.push(3);
        myStack.push(7);
        for (int i=0; i<2; i++) {
            cout << "The popped value is: " << myStack.pop() << endl;
        }
    } catch(...) {
        cout << "Error, please try again." << endl;
    }
    return 0;
}

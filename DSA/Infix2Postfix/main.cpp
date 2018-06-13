/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: June 16, 2018
 */
#include <iostream>
#include <string.h>

using namespace std;

class Stack {
private:
    char values[50];
    int top;

public:
    Stack(){top=0;}

    bool empty() {
        return top == 0 ? true : false;
    }

    void push(char c) {
        if (top >= 50) {
            cout << "[Error] Stack is FULL." << endl;
        }
        values[top] = c;
        top += 1;
    }

    char pop() {
        if (top <= 0) {
            cout << "[Error] stack is EMPTY." << endl;
        }
        top -= 1;
        return values[top];
    }

    char topStack() {
        if (top > 0) {
            return values[top-1];
        }
        cout << "[TOP Stack Error] stack is EMPTY." << endl;
    }

};

class Infix2Postfix {
private:
    char postStr[20];
    int pos;

public:
    Infix2Postfix(){pos=0;}

    void addToString(char c) {
        postStr[pos] = c;
        pos += 1;
    }

    int getType(char c) {
        if (c == '/' || c == '*' || c == '+' || c == '-' || c == '^') return 0;
        else if (c == '(' || c == ')') return 1;
        else return 2;
    }

    int getPrecedence(char c) {
        if (c == '-') return 1;
        else if (c == '+') return 2;
        else if (c == '*') return 3;
        else if (c == '/') return 4;
        else if (c == '^') return 5;
        else return -1;
    }

    void getAndConvert() {
        Stack _stack;
        char input[50];
        cout << "Enter the Infix string to convert: " << endl;
        cin >> input;

        for (int i=0; i< strlen(input); i++ ) {
            char c = input[i];

            // If the scanned character is operand adding it direct to postfix string.
            if (getType(c) == 2) addToString(c);

            // If the scanned character is operator then ...
            else if (getType(c) == 0) {

                // If the stack is empty push the scanned character
                if (_stack.empty()) _stack.push(c);
                // else ...
                else {
                    char topStack = _stack.topStack();
                    while (getPrecedence(topStack) > getPrecedence(c) && !_stack.empty()) {
                        addToString(_stack.pop());
                    }
                _stack.push(c);
                }
            }

            // If the scanned character is '(' push it into the stack.
            else if (c == '(') _stack.push(c);

            // If the scanned character is ')' pop all the operators and append them into postfix string until ')' is poped.
            else if (c == ')') {
                do {
                    char _pped = _stack.pop();
                    if (_pped != '(')addToString(_pped);
                } while (_stack.topStack() == '(');
            }
        }
        while (!_stack.empty()) {
            addToString(_stack.pop());
        }

        cout << endl << "The postfix expression is: ";
        for (int i=0; i<pos; i++) {
            cout << postStr[i];
        }
    }

};

// The main function which is executed.
int main() {
    Infix2Postfix myConv;
    myConv.getAndConvert();
    return 0;
}

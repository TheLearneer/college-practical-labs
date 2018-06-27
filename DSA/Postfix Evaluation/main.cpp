/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: June 27, 2018
 * NOTE:
 * This program uses custom implementation of statck and few other things, its done to learn how they work in actual and nothing else.
 */
 
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

class Stack {
private:
    int values[50];
    int top;

public:
    Stack(){top=0;}

    void push(int c) {
        if (top >= 50) {
            cout << "[Error] Stack is FULL." << endl;
        }
        values[top] = c;
        top += 1;
    }

    int pop() {
        if (top <= 0) {
            cout << "[Error] stack is EMPTY." << endl;
        }
        top -= 1;
        return values[top];
    }
};

class PostfixEvaluation {
private:
    int getType(char c) {
        if (c == '^' || c == '/' || c == '*' || c == '+' || c == '-') return 0;
        return 1;
    }

    int charToInt(char c) {
        switch(c) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
        }
    }
    /*
     * Perform the arithmetic calculation based on the operator on the two integers.
     */
    int performCalculation(char _operator, int first, int second) {
        switch(_operator) {
            case '/': return first / second;
            case '*': return first * second;
            case '+': return first + second;
            case '-': return first - second;
            case '^': return pow(first, second);
        }
    }

public:
    void convert() {
        char input[50];
        Stack _stack;

        cout << "Enter the mathematical expression to evaluate:";
        cin >> input;

        for (int i=0; i<strlen(input); i++) {
            char _ch = input[i];

            if (getType(_ch) == 1) _stack.push(charToInt(_ch));
            else {
                char _fir = _stack.pop();
                char _sec = _stack.pop();
                int res = performCalculation(_ch, _fir, _sec);
                _stack.push(res);
            }
        }
        cout << "Result is: " << _stack.pop() << endl;
    }
};

int main() {
    PostfixEvaluation Evaluator;
    Evaluator.convert();
    return 0;
}

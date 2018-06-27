/*
 * Copyright (C) 2018 Santosh Bhandari
 * Date Written: June 27, 2018
 * NOTE:
 * This program uses custom implementation of statck and few other things, its done to learn how they work in actual and nothing else.
 */
 
 #include <iostream>

using namespace std;

class Queue {
private:
    int values[50];
    int rear;
    int _front;

public:
    Queue() {rear=0; _front=0;}

    void enqueue(int n) {
        if (rear == 50) cout << "Queue is already full !!!" << endl;
        else {
            cout << "Enqueued: " << n << endl;
            values[rear] = n;
            rear += 1;
        }
    }

    int dequeue() {
        if (_front == rear) {
            cout << "Queue is empty !!!" << endl;
            return 0;
        } else {
            int res = values[_front];
            _front += 1;
            return res;
        }
    }
};

int main()
{
    Queue myQueue;
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    return 0;
}

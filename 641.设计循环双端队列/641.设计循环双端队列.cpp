#include <cstdio>

class MyCircularDeque {
    int *Q = NULL;
    int front;
    int rear;
    int size;
    int maxSize;
public:
    MyCircularDeque(int k) {
        Q = new int[k+1];
        front = 0;
        rear = 0;
        size = 0;
        maxSize = k + 1;

    }
    
    bool insertFront(int value) {
        if(size == maxSize - 1){
            return false;
        }
        else{
            if(front == rear){
                rear = (rear + 1 + maxSize) % maxSize;
                Q[front] = value;
                size++;
                return true;
            }
            else{
                front = (front + maxSize - 1) %  maxSize;
                Q[front] = value;
                size++;
                return true;
            }
        }
    }
    
    
    bool insertLast(int value) {
        if(size == maxSize - 1){
            return false;
        }
        else{
            if(front == rear){
                rear = (rear + 1 + maxSize) % maxSize;
                Q[front] = value;
                size++;
                return true;
            }
            else{
                Q[rear] = value;
                rear = (rear + 1 + maxSize) % maxSize;
                size++;
                return true;
            }



        }
    }
    
    bool deleteFront() {
        if(size > 0){
            size--;
            front = (front + 1 + maxSize) % maxSize;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteLast() {
        if(size > 0){
            size--;
            rear = (rear - 1 + maxSize) % maxSize;
            return true;
        }
        else{
            return false;
        }
    }
    
    int getFront() {
        if(size > 0){
            return Q[front];
        }
        else{
            return -1;
        }
    }
    
    int getRear() {
        if(size > 0){
            return Q[(rear - 1 + maxSize) % maxSize];
        }
        else{
            return -1;
        }
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(size == maxSize - 1){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
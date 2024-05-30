//Queue
//Author:Daniel Sameh
//@2024
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int SIZE=5;
template<typename T>
class Queue{
private:
    int first=0;
    int last=0;
    int size=0;
    T data[SIZE];
public:
    void enqueue(T element){
        if(size==SIZE){
            cerr<<"Queue is full!";
        }
        else {
            data[size] = element;
            size++;
            last=size-1;
        }
    }
    T dequeue(){
        if(size==0){
            cerr<<"The Queue is empty!";
        }
        else if(size==1){
            T x= data[first];
            first=0;
            size=0;
            last=0;
            return x;
        }
        else {
            T x = data[first];
            first++;
            size--;
            return x;
        }
    }
    T First(){
        if(size!=0) {
            return data[first];
        }
        else{
            cerr<<"Queue is empty!";
        }
    }
    bool isEmpty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
    int QueueSize(){
        return size;
    }
    void clear(){
        size=0;
        first=0;
        last=0;
    }
    void print(){
        if(size==0){
            cerr<<"Queue is empty!";
        }
        for (int i = first; i <size; ++i) {
            cout<<data[i]<<" ";
        }
    }

};
int main() {
    Queue<int> q;
//    q.dequeue();
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(53);
    q.enqueue(53);
    q.clear();
    if (q.isEmpty())
        cout<<"the queue is empty...\n";
    q.enqueue(23);
    q.enqueue(53);
    cout<<q.dequeue()<<'\n';
    cout<<q.First()<<'\n';
    cout<<q.QueueSize()<<'\n';


}
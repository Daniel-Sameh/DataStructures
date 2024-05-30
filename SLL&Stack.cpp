//Single Linked List & Stack
//Author: Daniel Sameh
//@2024
#include <iostream>
using namespace std;
template <typename T>
class node {
public:
    T data;
    node *link;

    node() {
        data = 0;
        link = nullptr;
    }
    node(T val){
        data=val;
        link= nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    node<T> *head, *tail;
    int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insert(T val){
        node<T>* newNode= new node(val);
        if (head==tail&&head== nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->link=newNode;
            tail=newNode;
        }
        ++size;
    }
    void pop_front(){
        if (size==0){
            cerr<<"the list is empty!\n";
        }else if (head==tail){
            node<T>* tmp=head;
            head= nullptr;
            tail= nullptr;
            --size;
            delete tmp;
        }else{
            node<T>* tmp=head;
            head=head->link;
            delete tmp;
            --size;
        }
    }
    void pop_back(){
        if (size==0){
            cerr<<"the list is empty!\n";
        }else if (head==tail){
            node<T>* tmp=head;
            head= nullptr;
            tail= nullptr;
            --size;
            delete tmp;
        }else{
            node<T>* cur=head;
            while (cur->link!=tail){
                cur=cur->link;
            }
            node<T>* tmp=tail;
            tail=cur;
            cur->link= nullptr;
            delete tmp;
            --size;
        }
    }
    int front(){
        if (size==0)
            cerr<<"the list is empty!\n";
        else
            return head->data;
        return 0;
    }
    int back(){
        if (size==0)
            cerr<<"the list is empty!\n";
        else
            return tail->data;
        return 0;
    }
    int listSize() const{
        return size;
    }
    void print(){
        node<T>* tmp=head;
        while (tmp){
            cout<<tmp->data<<' ';
            tmp=tmp->link;
        }
        delete tmp;
    }
    void clear(){
        node<T>*tmp= nullptr;
        tail= nullptr;
        while(head!= nullptr){
            tmp=head;
            head=head->link;
            delete tmp;
        }
        size=0;
    }
};
template<typename T>
class Stack{
private:
    LinkedList<T> list;
    int size;
    T front;
public:
    Stack(){
        size=0;
        front= T();
    }
    void push(T val){
        list.insert(val);
        ++size;
        front=val;
    }
    T pop(){
        if (this->isEmpty()) {
            cerr << "Stack Underflow!";
            return T();
        }else{
            T tmp= list.back();
            list.pop_back();
            --size;
            return tmp;
        }
    }
    T top(){
        if (size==0)
            cerr<<"Stack Underflow(Empty Stack)";
        return front;
    }
    bool isEmpty(){
        return size==0;
    }
    int stackSize(){
        return size;
    }
    void clear(){
        size=0;
        list.clear();
    }
    void print(){
        list.print();
    }
};



int main() {
    //Single Linked List Testing...
    LinkedList<int> list;
    list.insert(2);
    list.insert(4);
    list.insert(56);
    list.insert(12);
    list.insert(8);
//    list.clear();
    cout<<"SIZE="<<list.listSize()<<'\n';
    list.pop_back();
    cout<<"SIZE="<<list.listSize()<<'\n';
    list.pop_front();
    cout<<"SIZE="<<list.listSize()<<'\n';
    list.print();
    cout<<"\n--------------------------------\n";
    //Stack Testing...
    Stack<int>st;
    st.push(5);
    st.push(14);
    st.push(85);
    cout<<"Top= "<<st.top()<<'\n';
    cout<<"popped element:"<<st.pop()<<'\n';
    st.print();
    cout<<'\n';
    cout<<"popped element:"<<st.pop()<<'\n';
    st.print();
    cout<<'\n';
    cout<<"popped element:"<<st.pop()<<'\n';
    st.print();
//    cout<<st.pop()<<'\n';
    cout<<"Stack Size= "<<st.stackSize()<<'\n';
    st.print();
}
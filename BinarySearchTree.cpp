//Binary Search Tree
//Author: Daniel Sameh
//@27/4/2024
#include <bits/stdc++.h>
using namespace std;
#define dodo ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ll long long
template<typename T>
class node{
public:
    T data;
    node* left;
    node* right;
    node(){
        data=T();
        left= nullptr;
        right= nullptr;
    }
    node(T data){
        this->data=data;
        left= nullptr;
        right= nullptr;
    }

};

template<typename T>
class BST{
private:
    node<T>* head;
    int size;
public:
    BST(){
        size=0;
        head= nullptr;
    }
    node<T>* getHead(){
        return head;
    }
    void insert(T data){
        node<T>* p=head, *prev= nullptr;
        while (p!= nullptr){
            prev=p;
            if (p->data < data){
                p= p->right;
            }else{
                p= p->left;
            }
        }
        if (head == nullptr){
            head= new node<T>(data);
        }else if (prev->data < data){
            prev->right= new node<T>(data);
        }else{
            prev->left= new node<T>(data);
        }
        ++size;
    }
    bool search(T data){
        node<T>* p=head;
        while (p!= nullptr&& p->data!=data){
            if (p->data < data){
                p= p->right;
            }else{
                p= p->left;
            }
        }
        if (p!= nullptr&&p->data==data){
            return true;
        }else
            return false;
    }
    void deleteElement(T data){
        node<T>* p=head, *prev= nullptr;
        while (p!= nullptr&&p->data!=data){
            prev=p;
            if (p->data < data){
                p= p->right;
            }else{
                p= p->left;
            }
        }
        node<T>* tmp=p;
        if (p->right== nullptr&&p->left== nullptr){
            if (prev== nullptr){
                head= nullptr;
            }else if (prev->left==p){
                prev->left=nullptr;
            }else{
                prev->right=nullptr;
            }
        }
        else if (p->right== nullptr){
            p= p->left;
        }else if (p->left== nullptr){
            p= p->right;
        }else{
            node<T>* prev1=tmp;
            tmp=p->left;
            while (tmp->right!= nullptr){
                prev1=tmp;
                tmp=tmp->right;
            }
            p->data=tmp->data;
            if (prev1==p){
                prev1->left=tmp->left;
            }else
                prev1->right= tmp->left;
        }
        delete tmp;
    }

};
vector<int>inorder;
void inOrder(node<int>* p){
    if (p != nullptr){
        inOrder(p->left);
        inorder.push_back(p->data);
        inOrder(p->right);
    }
}
vector<int>preorderVec;
void preOrder(node<int>* p){
    if (p!= nullptr){
        preorderVec.push_back(p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}
vector<int>postorderVec;
void postOrder(node<int>* p){
    if (p!= nullptr){
        postOrder(p->left);
        postOrder(p->right);
        postorderVec.push_back(p->data);
    }
}
/*void traverseBST(node<int>* head){

    if(head->left){
        traverseBST(head->left);
    }else{
        inorder.push_back(head->data);
    }

    //bst.push_back(head);

    if(head->right){
        inorder.push_back(head->data);
        traverseBST(head->right);
    }else{
        return;
    }
}*/


int main() {
    dodo;
    //Testing...
    BST<int> bst;
    bst.insert(5);
    bst.insert(2);
    bst.insert(8);
    bst.insert(1);
    bst.insert(7);
    bst.insert(9);
    bst.insert(4);
    bst.insert(3);
    bst.deleteElement(9);
    inOrder(bst.getHead());
    for (auto i:inorder) {
        cout<<i<<' ';
    }
    cout<<'\n';

    preOrder(bst.getHead());
    for (auto i:preorderVec) {
        cout<<i<<' ';
    }
    cout<<'\n';

    postOrder(bst.getHead());
    for (auto i:postorderVec) {
        cout<<i<<' ';
    }
    cout<<'\n';
    if (bst.search(7)){
        cout<<"found 7!\n";
    }
    if (bst.search(15)){
        cout<<"found 15!\n";
    }
    if (bst.search(3)){
        cout<<"found 3!\n";
    }
//    inorder.clear();
//    traverseBST(bst.getHead());
//    for (auto i:inorder) {
//        cout<<i<<' ';
//    }
//    cout<<'\n';


}

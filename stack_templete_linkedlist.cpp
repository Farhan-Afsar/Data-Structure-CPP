#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T>* pre;
        Node<T>* next;

    Node<T>(T data){
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }

};

template<class T>
class doubly_linked_list{
    public:
        Node<T>* head;
        int size;
    doubly_linked_list(){
        head = NULL;
        size = 0;
    }
    void DeleteAtHead()
    {
        if(head== NULL)
        {
            return;
        }
        Node<T> *a = head;
        Node<T> *b = head->next;
        delete a;
        if(b!= NULL)
        {
            b->pre = NULL;
        }
        head= b;
        size--;
    }
    void insertHead(T data){
        Node<T>  * newNode = new Node<T>(data);
        size++;
        if(head == NULL){
            head = newNode;
            return;
        }
        head -> pre = newNode ;
        newNode -> next = head ;
        head = newNode;

    }
    T getSize(){
        return size;
    }

};

template<class T>
class Stack{
    public:
    doubly_linked_list<T> dl;

    T top(){
        if(dl.getSize() == 0){
            assert(false);
        }
        return dl.head -> data;
    }

    void push(T data){
        dl.insertHead(data);
    }
    void pop(){
        if(dl.getSize() == 0){
            return;
        }
        dl.DeleteAtHead();
    }
};
int main(){
    Stack<float> s;
    s.push(1.9);
    s.push(2.5);
    s.push(3.4);
    s.push(4.8);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    
}
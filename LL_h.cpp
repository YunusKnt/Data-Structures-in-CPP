#include <iostream>
#include "LL.h"
#include <cassert>
using namespace std;

template <class T>
struct node{
    T info;
    node <T> *link;
};
template <class T>
class LL{
    protected:
    node<T> *head,*last;
    int count;
    public:
    LL();//
    ~LL(); //
    bool emptyList(); //
    int lenght(){return count;}//
    T back(); //
    T front(); //
    void destroyList(); //
    node<T> *search(T&);//
    void insertFirst(T&); //
    void insertLast(T&); //
    void deleteNode(T&); //
    friend ostream& operator<<(ostream& os,LL<T>&);
};
template <class T>
LL<T> ::LL(){
    count=0;
    head=last=NULL;  
}
template <class T>
bool LL<T> :: emptyList(){return head==NULL;}

template <class T>
T LL<T> :: front(){ //first info of the Liinked List
    assert(head!=NULL);
    return head->info;
}

template <class T>
T LL<T> ::back(){//LAST INFO of the linked list
    assert(last!=NULL);
    return last->info;
}

template <class T>
void LL<T> :: insertFirst(T & item){
    node <T> * p = new node<T>;
    p-> info = item;
    p-> link = head;
    head = p;
    if(last == NULL) last = p;
    count++;
}

template <class T>
void LL<T> :: insertLast(T & item){
    node <T> * p = new node<T>;
    p -> info = item;
    p -> link = NULL;
    if(head != NULL){
        last -> link = p;
        last = p;
    }
    else
    head = last = p;
    count ++;
}

template <class T>
void LL<T> :: destroyList(){
    node<T> * p;
    while(head != NULL){
        p = head;
        head = head -> link;
        delete p;
    }
    count = 0;
    last = NULL;
}

template <class T>
LL<T> :: ~LL(){destroyList();}

template <class T>
node <T>* LL<T> :: search(T& item){
    node<T> *p=head;

    bool found=false;

    while(p!=NULL&&!found){//
        if(p->info==item)
        found=true;
        else
        p=p->link;
    }
    return p;
}

template <class T>
void LL<T> :: deleteNode(T & item){
    node<T> *p, *q;
    found = false;
    if(head -> info == item){
        p = head;
        head = head -> link;
        delete p;
        count--;
        if(head == NULL)    last = NULL;
    }
    else{
        p = head;
        q = head -> link;
        while(q != NULL && !found){
            if(q -> info == item)
                found = true;
            else{
                p = q;
                q = q -> link;
            }
        }

        if(found){
            p -> link = q -> link;
            delete q;
            count--;
            if(p -> link == NULL)   last = p;
        }
        else
        cerr << "There is no node with the entered item!" << endl;
    }
}

template <class T>
ostream & operator <<(ostream & os, LL<T> & lst){
    node<T> *p = head;
    while(p != NULL){
        os << p -> info << endl;
        p = p -> link;
    }
    return os;
}
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
int main(){
    Node *a=new Node;
    Node *b=new Node;
    Node *c=new Node;
    
    a->data=10;
    b->data=20;
    c->data=30;
    a->next=b;
    b->next=c;
    c->next=NULL;
    Node *p=a;
    while (p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
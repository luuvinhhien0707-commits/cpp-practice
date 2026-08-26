#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node* MakeNode(int x){
    Node *a=new Node;
    a->data=x;
    a->next=NULL;
    return a;
}
void add_last(Node *tmp, Node *a){
    while (tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=a;
    a->next=NULL;
}
int main(){
    int dataa=20;
    int datab=30;
    int datac=40;
    Node *a=MakeNode(dataa);
    Node *b=MakeNode(datab);
    Node *c=MakeNode(datac);
    
    a->next=b;
    b->next=c;
    c->next=NULL;

    Node *head=a;
    Node* tmp=head;

    while (tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
    tmp=head;
    int datad=50;
    Node* d=MakeNode(datad);
    add_last(tmp, d);
    while (tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    return 0;
}
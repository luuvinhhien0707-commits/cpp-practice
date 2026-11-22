#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int x;
    struct Node *L;
    struct Node *R;
}Node;

Node* createNode(int x){
    Node *p = (Node*)malloc(sizeof(struct Node));

    p->x=x;
    p->L=NULL;
    p->R=NULL;

    return p;
}

Node* createTree(){
    int x;
    scanf ("%d",&x);
    if (x==-1){
        return NULL;
    }
    Node *p=createNode(x);
    p->L=createTree();
    p->R=createTree();

    return p;
}
void preorder(Node *root){
    if (root==NULL) {
        return;
    }
    printf("%d ",root->x);
    preorder(root->L);
    preorder(root->R);
}
void inorder(Node *root){
    if (root==NULL){
        return;
    }
    inorder(root->L);
    printf("%d ",root->x);
    inorder(root->R);
}
void postorder(Node *root){
    if (root==NULL){
        return;
    }
    postorder(root->L);
    postorder(root->R);
    printf("%d ",root->x);
}
int search (Node *root, int x){
    if (root==NULL){
        return 0;
    }
    if(root->x==x){
        return 1;
    }
    if (search(root->L,x)||search(root->R,x)){
        return 1;
    }
    return 0;
}
int countNodes(Node *root){
    int cnt1,cnt2;
    if (root==NULL){
        return 0;
    }
    cnt1=countNodes(root->L);
    cnt2=countNodes(root->R);
    return 1+cnt1+cnt2;
}
int countLeaves(Node *root){
    int cntL, cntR;
    if(root==NULL){
        return 0;
    }
    if(root->L==NULL&&root->R==NULL){
        return 1;
    }
    cntL=countLeaves(root->L);
    cntR=countLeaves(root->R);
    return cntL+cntR;
}
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int max;
    max=height(root->L);
    if (height(root->R)>max){
        max=height(root->R);
    }
    return 1+max;
}
int sumNodes(Node *root){
    if (root==NULL){
        return 0;
    }
    int sumL,sumR;
    sumL=sumNodes(root->L);
    sumR=sumNodes(root->R);
    return root->x+sumL+sumR;
}
int countOneChild(Node* root){
    int cntL,cntR;
    if (root==NULL){
        return 0;
    }
    cntL=countOneChild(root->L);
    cntR=countOneChild(root->R);
    if((root->L!=NULL&&root->R==NULL)||(root->L==NULL&&root->R!=NULL)){
        return 1+cntL+cntR;
    }
    return 0+cntL+cntR;
}
int main(){
    Node *root = createTree();

    printf("So node co gia tri chan: %d\n", countEven(root));

    return 0;
}
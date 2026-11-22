#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct Student {
    char ID[10];
    char Name [50];
    float R1,R2,R3;
}Student;

typedef struct Node {
    struct Student x;
    struct Node* Next;
}Node;
typedef Node* List;

List getList(){
    List L = (List)malloc(sizeof(struct Node));
    L->Next=NULL;
    return L;
}

List locate (char ID[], List L){
    List pL=L;
    while (pL->Next!=NULL){
        if (strcmp(pL->x.ID,ID)==0){
            return pL;
        }
        pL=pL->Next;
    }
    return NULL;
}

int append(Student s, List *pL){
    if(locate(s.ID, *pL)!=NULL){
        return 0;
    }
    List L=*pL;
    while (L->Next!=NULL){
        L=L->Next;
    }
    List NewNode = (List)malloc(sizeof(struct Node));
    NewNode->x=s;
    NewNode->Next=NULL;
    L->Next=NewNode;

    return 1;
}
List readList(){
   List L=getList();
   int n,i;
   scanf ("%d",&n);
   for (i=0;i<n;i++){
    Student s;
    scanf ("%s",s.ID);
    scanf (" %[^\n]",s.Name);
    scanf ("%f%f%f",&s.R1,&s.R2,&s.R3);
    append (s,&L);
   }
   return L;
}
void printList(List L){
    List pL=L->Next;
    int cnt=1;
    while (pL!=NULL){
        float tb=(pL->x.R1+pL->x.R2+pL->x.R3)/3;
        printf ("%d -        %s -                                      %s - %f - %f - %f - %f\n",cnt,pL->x.ID,pL->x.Name,pL->x.R1,pL->x.R2,pL->x.R3,tb);
        cnt++;
        pL=pL->Next;
    }
}
List getFailedList(List L){
    List pL=getList();
    List p=L->Next;
    while (p!=NULL){
        float tb=(p->x.R1+p->x.R2+p->x.R3)/3;
        if (tb<4){
            Student s = p->x;
            append(s,&pL);
        }
        p=p->Next;
    }
    return pL;
}
int main(){
    List L = readList();
    printList(L);
    List pL=getFailedList(L);
    printList(pL);
    return 0;
}
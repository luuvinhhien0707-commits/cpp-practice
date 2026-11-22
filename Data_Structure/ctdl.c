#include <stdio.h>
#define MaxLength 100
typedef int ElementType;

typedef struct {
    ElementType Elements [MaxLength];
    int Last;
} List;

void makenullList (List *pL){
    pL->Last=0;
}
int member(ElementType x, List L){
    int i;
    for (i=0;i<=L.Last;i++){
        if (L.Elements[i]==x){
            return 1;
        }
    }
    return 0;
}
void insertSet(ElementType x, List *pL){
    if(pL->Last<MaxLength){
        pL->Elements[pL->Last]=x;
        pL->Last++;
    }
}
void readSet(List *pL){
    makenullList(pL);
    int n;
    scanf ("%d",&n);
    int i;
    for (i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(!member(x,*pL)){
            insertSet(x,pL);
        }
    }
}
int locate (ElementType x, List *pL){
    int i;
    int cnt=0;
    for(i=0;i<pL->Last;i++){
        if(x==pL->Elements[i]){
            return cnt;
        }
        cnt++;
    }
}
void deleteList(ElementType p, List *pL){
    int i;
    for (i=p+1;i<pL->Last;i++){
        pL->Elements[i-1]=pL->Elements[i];
    }
    pL->Last--;
}
void erase(int x, List *pL){
    int cnt=locate(x, pL);
    deleteList(cnt, pL);
}
void insertList(int x, ElementType p, List *pL){
    pL->Elements[p-1]=x;
    pL->Last++;
}
void intersection(List L1,List L2, List *pL){
    int i;
    makenullList (pL);
    for (i=0;i<L1.Last;i++){
        if(member(L1.Elements[i], L2)){
            pL->Elements[pL->Last]=L1.Elements[i];
            pL->Last++;
        }
    }
}
int main(){
List L1,L2,L;
int i;

makenullList(&L1);
makenullList(&L2);

for(i=5;i>=0;i--){
    insertSet(2*i, &L1);
}
for(i=9;i>=4;i--){
    insertSet(2*i, &L2);
}

for(i=0;i<L1.Last;i++){
    printf("%d ",L1.Elements[i]);
}
printf("\n");
for(i=0;i<L2.Last;i++){
    printf("%d ",L2.Elements[i]);
}
printf("\n");
intersection(L1,L2,&L);
for(i=0;i<L.Last;i++){
    printf("%d ",L.Elements[i]);
}
}
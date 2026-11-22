#include <stdio.h>
#include<string.h>
#define MaxLength 100
typedef int ElementType;

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};
typedef struct SinhVien SinhVien;

typedef struct DanhSach{
    struct SinhVien A[100];
    int n;
}DanhSach;

DanhSach dsRong(){
    DanhSach pL;
    pL.n=0;
}
void chenCuoi(SinhVien x, DanhSach* pL){
    if (pL->n<MaxLength){
        pL->A[pL->n]=x;
        pL->n++;
    }
}
DanhSach chepKhongDat(DanhSach L){
    DanhSach pL=dsRong();
    int i;
    for (i=0;i<L.n;i++){
        if ((L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2)<4){
            chenCuoi(L.A[i], &pL);
        }
    }
    return pL;
}
int tim(char x[8], DanhSach L){
    int i;
    for (i=0;i<L.n;i++){
        if (strcmp(L.A->MSSV,x)==0){
            return i+1;
        }
    }
    return i+1;
}
void xoaTai(int p, DanhSach* pL){
    int i;
    for (i=p;i<pL->n;i++){
        pL->A[i-1]=pL->A[i];
    }
    pL->n--;
}
DanhSach nhap(){
    DanhSach L = dsRong ();
    int n,i;
    scanf ("%d", &n);
    for (i=0;i<n;i++){
        struct SinhVien s;
        scanf ("%s",s.MSSV);
        while(getchar()!='\n');
        scanf ("%[^\n]",s.HoTen);
        scanf ("%f%f%f",&s.DiemLT,&s.DiemTH1,&s.DiemTH2);
        
        if(tim(s.MSSV,L)==L.n+1){
            chenCuoi(s,&L);
        }
    }
    return L;
}
void xoaSinhVien(char x[8],DanhSach* pL){
    int p=tim(x,*pL);
    if (p<=pL->n){
        xoaTai(p,pL);
    }
}
void hienthiDat(DanhSach L){
    DanhSach pL;
    pL.n=0;
    int i;
    for (i=0;i<=L.n;i++){
        if ((L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2)>=4.0){
            pL.A[pL.n]=L.A[i];
            pL.n++;
        }
    }
    for (i=0;i<pL.n;i++){
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",pL.A[i].MSSV, pL.A[i].HoTen, pL.A[i].DiemLT, pL.A[i].DiemTH1, pL.A[i].DiemTH2, (pL.A[i].DiemTH2+pL.A[i].DiemTH1+pL.A[i].DiemLT));
    }
}
int main (){
DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
L.A[1] = s1;
L.n++;
L.A[2] = s2;
L.n++;
hienthiDat(L);
}
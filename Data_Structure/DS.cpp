#include <iostream>
using namespace std;
void in(int a[], int n){
    int *ptr=a;
    while (ptr<a+n){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
} 
void delet_chan(int a[],int *n){
    int *read=a;
    int *write=a;
    while (read<a+*n){
        if(*read%2!=0){
            *write=*read;
            write++;
        }
        read++;
    }
    *n=write-a;
    cout<<*n<<endl;
    int *ptr=a;
    while (ptr<write){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
}
void hate_8(int a[],int n){
    int *read=a;
    int *write=a;
    while (read<a+n){
        if(*read!=8){
            *write=*read;
            write++;
        }
        read++;
    }
    int *ptr=a;
    while(ptr<write){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
}
int main(){
    int a[] = {12, 5, 8, 20, 3, 15, 7, 8, 10};
    int n = 9;
//in mảng bằng pointer
    in(a,n);
//bỏ các phần tử chẵn trong mảng
    delet_chan(a,&n);
//bỏ toàn bộ số 8 trong mảng
    int a1[] = {12, 5, 8, 20, 3, 15, 7, 8, 10};
    int n1 = 9;
    hate_8(a1,n1);
    return 0;
}
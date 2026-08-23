#include <iostream>
using namespace std;
void in(int a[],int n){
    int *ptr=a;
    for (int i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout <<endl;
    for (int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
    cout<<endl;
}
void gtln(int a[],int n){
    int *ptr=a;
    int max=*ptr;
    int x=0;
    for (int i=0;i<n;i++){
        if (*(ptr+i)>max){
            max=*(ptr+i);
            x=i;
        }
    }
    cout<<"Gia Tri Lon Nhat: "<<max<<endl
        <<"Vi Tri: "<<x<<endl;
}
void gtnn(int a[],int n){
    int *ptr=a;
    int min=*ptr;
    int x=0;
    for (int i=0;i<n;i++){
        if (*(ptr+i)<min){
            min=*(ptr+i);
            x=i;
        }
    }
    cout<<"Gia Tri Lon Nhat: "<<min<<endl
        <<"Vi Tri: "<<x<<endl;
}
void sum(int a[],int n){
    int *ptr=a;
    int sum=0;
    for (int i=0;i<n;i++){
        sum=sum+*(ptr+i);
    }
    cout<<"Tong: "<<sum<<endl;
}
void cnt_chan(int a[],int n){
    int *ptr=a;
    int cnt=0;
    for (int i=0;i<n;i++){
        if (*(ptr+i)%2==0){
            cnt++;
        }
    }
    cout<<"So luong so chan: "<<cnt<<endl;
}
void swap(int a[],int n){
    int *x=a;
    int *y=a+n-1;
    int n1=n;
    for (int i=0;i<n/2;i++){
        int temp=*x;
        *x=*y;
        *y=temp;
        x++;
        y--;
    }
    int *ptr=a;
    for (int i=0;i<n1;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
}
int main(){
    int a[]={12,5,8,20,3,15,7};
    int n=7;
//in toàn bộ chương trình của mảng bằng pointer
    in(a,n);
    cout<<endl;
//tìm giá trị lớn nhất và vị trí của nó
    gtln(a,n);
    cout<<endl;
//tìm giá trị nhỏ nhất và vị trí của nó
    gtnn(a,n);
    cout<<endl;
//tính tổng 
    sum(a,n);
    cout<<endl;
//đếm bao nhiu số chẵn
    cnt_chan(a,n);
    cout<<endl;
//Đảo ngược mảng
    swap(a,n);
    cout<<endl;
    return 0;
}
#include <iostream>
using namespace std;
void in(int *a,int n){
    int *ptr=a;
    while (ptr<a+n){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
}
void min_max(int *a,int n){
    int *ptr=a;
    int max=*ptr;
    int min=*ptr;
    while (ptr<a+n){
        if (*ptr>max){
            max=*ptr;
        }
        if(*ptr<min){
            min=*ptr;
        }
        ptr++;
    }
    cout<<"Max: "<<max<<endl
        <<"Min: "<<min<<endl;
}
void sum(int *a, int n){
    int *ptr=a;
    int sum=0;
    while (ptr<a+n){
        sum=sum+*ptr;
        ptr++;
    }
    cout<<"Tong: "<<sum<<endl;
}
void delete_chan(int *a, int n){
    int *read=a;
    int *write=a;
    while (read<a+n){
        if (*read%2!=0){
            *write=*read;
            write++;
        }
        read++;
    }
    int *ptr=a;
    while (ptr<write){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Nhap so: ";
    cin>>n;
    int *a=new int[n];
    int *ptr=a;
    while (ptr<a+n){
        cin>>*ptr;
        ptr++;
    }
    in(a,n);
    //min_max
    min_max(a,n);
    //sum
    sum(a,n);
    //Xoa so chan
    delete_chan(a,n);
    delete []a;
    return 0;
}
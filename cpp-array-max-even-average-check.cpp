#include <iostream>
#include <vector>
using namespace std;
int timmax(vector<int>a, int n){
    int max=a[0];
    for (int i=1;i<n;i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    return max;
}
float tbchan(vector<int>a, int n){
    int cnt=0;
    float tong=0;
    for (int i=0;i<n;i++){
        if (a[i]%2==0){
            tong=tong+a[i];
            cnt++;
        }
    }float tb;
    if (cnt==0){
        tb=0;
    }
    else{
        tb=tong/cnt;
    }
    return tb;
}
int ktr(vector<int>a, int n){
    for (int i=0;i<n-1;i++){
        if (a[i+1]<a[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    int x;
    vector<int>a;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int max=timmax(a,n);
    float tb=tbchan(a,n);
    cout<<"Max: "<<max<<endl
        <<"Trung binh cong chan: "<<tb<<endl;
    if (ktr(a,n)){
        cout<<"Tang dan: YES"<<endl;
    }else {
        cout<<"Tang dan: NO"<<endl;
    }
    return 0;
}
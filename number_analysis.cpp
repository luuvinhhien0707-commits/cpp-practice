#include <iostream>
#include <vector>
using namespace std;
int tongdemso (int so){
    int n;
    int tong=0;
    while (so>0){
        n=so%10;
        tong=tong+n;
        so=so/10;
    }
    return tong;
}
int chan (int so){
    vector<int>a;
    int c;
    while (so>0){
        c=so%10;
        a.push_back(c);
        so=so/10;
    }
    int cnt=0;
    for (int i=0;i<a.size();i++){
        if (a[i]%2==0){
            int so1=a[i];
            cnt++;
            for (int j=0;j<a.size();j++){
                if(a[j]==so1){
                    a.erase(a.begin()+j);
                    j--;
                }
            }
            i--;
        }
    }
    return cnt;
}
int doixung(int so){
    vector<int>a;
    while (so>0){
        int c=so%10;
        a.push_back(c);
        so=so/10;
    }
    int n=a.size();
    for (int i=0;i<n/2;i++){
        if (a[i]!=a[n-1-i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int so;
    cout<<"nhap so: ";
    cin>>so;
    int tong=tongdemso(so);
    int cnt=0;
    int temp=so;
    while (temp>0){        
        temp=temp/10;
        cnt++;
    }
    int sochan=chan(so);
    cout<<tong<<endl
        <<sochan<<endl;
    if (doixung(so)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
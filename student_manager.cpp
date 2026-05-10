#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct SinhVien{
    string ten;
    string mssv;
    float toan;
    float ly;
    float hoa;
};
float tb(SinhVien sv){
    float dtb=(sv.toan+sv.ly+sv.hoa)/3;
    return dtb;
}
int main(){
    int n; cin>>n;
    cin.ignore();
    vector<SinhVien>ds;
    for (int i=0;i<n;i++){
        SinhVien sv;
            cout<<"Nhap ten"<<endl;
            getline(cin,sv.ten);
            cout<<"Nhap mssv"<<endl;
            getline(cin,sv.mssv);
            cout<<"Nhap diem Toan"<<endl;
            cin>>sv.toan;
            cout<<"Nhap diem Ly"<<endl;
            cin>>sv.ly;
            cout<<"Nhap diem Hoa"<<endl;
            cin>>sv.hoa;
            ds.push_back(sv);
            cin.ignore();
    }

    cout<<endl<<"Danh Sach Sinh Vien:"<<endl;
    for (SinhVien sv:ds){
        cout<<endl<<"Ten: "<<sv.ten
            <<endl<<"MSSV: "<<sv.mssv
            <<endl<<"Diem Trung Binh: "<<tb(sv)<<endl;
    }float max=tb(ds[0]);
    for (int i=1;i<n;i++){
        if(tb(ds[i])>max){
            max=tb(ds[i]);
        }
    }
    cout<<"Diem Trung Binh Cao Nhat: "<<max<<endl;
    cout<<"Sinh Vien Co Diem Trung Binh Lon Hon 8: ";
    for(SinhVien sv:ds){
        if(tb(sv)>=8){
            cout<<sv.ten<<"-"<<tb(sv)<<"   ";
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        cout<<"Case "<<i+1<<": ";
        if(a>b && c>a)cout<<a<<"\n";
        else if(b>a && c>b)cout<<b<<"\n";
        else if(b>c && a>b)cout<<b<<"\n";
        else if(a>c && b>a)cout<<a<<"\n";
        else cout<<c<<"\n";
    }
}

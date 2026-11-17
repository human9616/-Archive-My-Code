#include<bits/stdc++.h>
using namespace std;
int main(){
    long long  s,d;
    while(cin>>s>>d){
        long long  total=s;
        while(total<d){
            s++;
            total+=s;
        }
        cout<<s<<"\n";
    }
}

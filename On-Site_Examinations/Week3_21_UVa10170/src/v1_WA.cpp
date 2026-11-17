#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,d;
    while(cin>>s>>d){
        int total=s;
        while(total<d){
            s++;
            total+=s;
        }
        cout<<s<<"\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
                int n;
                cin>>n;
                n=(((((n*567)/9)+7492)*235)/47)-498;
                string a=to_string(n);
                cout<<a[a.size()-2]<<"\n";
        }
}

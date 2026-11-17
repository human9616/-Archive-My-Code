#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        while(cin>>n && n!=-1){
                string s;
                while(n>0){
                        s+=to_string(n%3);
                        n/=3;
                }
                s.reserve();
                cout<<s<<"\n";
        }
}

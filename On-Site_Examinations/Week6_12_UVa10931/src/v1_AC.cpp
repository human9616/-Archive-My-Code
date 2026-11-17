#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        while(cin>>n){
                if(n==0)break;
                string s="",ans="";
                int count=0;
                while(n>0){
                        if(n%2==1)count++;
                        s+=to_string(n%2);
                        n/=2;
                }cout<<"The parity of ";
                for(int i=s.size()-1;i>=0;i--)
                cout<<s[i];
                cout<<" is "<<count<<" (mod 2).\n";
        }
}

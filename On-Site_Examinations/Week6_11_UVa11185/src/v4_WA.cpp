#include<bits/stdc++.h>
using namespace std;
int main(){
        long long n;
        int f=0;
        while(cin>>n){
                if(n==-1)break;
                if(f)cout<<"\n";
                string s="";
                while(n>0){
                        s+=to_string(n%3);
                        n/=3;
                }
                for(int i=s.size()-1;i>=0;i--)
                cout<<s[i];
                f=1;
        }
}

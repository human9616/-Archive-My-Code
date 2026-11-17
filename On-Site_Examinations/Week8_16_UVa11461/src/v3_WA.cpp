#include<bits/stdc++.h>
using namespace std;
int main(){
        long long a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                int n=sqrt(a),m=sqrt(b);
                if(a==b){
                        if(sqrt(a)!=n)cout<<0;
                        else cout<<m-n+1<<"\n";
                }
                else cout<<m-n+1<<"\n";
        }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
        long long a,b,h=0;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                else if(h)cout<<"\n";
                else h=1;
                long long ans=0;
                for(int i=sqrt(a);pow(i,2)<=b;i++){
                                ans++;
                }
                cout<<ans;
        }
}

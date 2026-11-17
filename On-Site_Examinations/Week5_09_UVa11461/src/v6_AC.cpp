#include<bits/stdc++.h>
using namespace std;
int main(){
        long long a,b,h=0;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                long long ans=0;
                for(int i=1;i*i<=b;i++){
                        if(i*i>=a){
                                ans++;
                        }
                }
                cout<<ans<<"\n";
        }
}

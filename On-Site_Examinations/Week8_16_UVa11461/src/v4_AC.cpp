#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                int ans=0;
                for(int i=sqrt(a);i<=sqrt(b);i++){
                        if(i<sqrt(a))continue;
                        ans++;
                }
                cout<<ans<<"\n";
        }
}

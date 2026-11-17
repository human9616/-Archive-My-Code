#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0)break;
        int ans=0;
        while(a>=1 && b>=1){
            int tmp1=a%10,tmp2=b%10;
            if((tmp1+tmp2)/10){
                ans++;
                a+=(tmp1+tmp2)/10;
            }
            a/=10;b/=10;
        }
        if(ans)cout<<ans<<" carry operation.\n";
        else cout<<"No carry operation.\n";
    }
}

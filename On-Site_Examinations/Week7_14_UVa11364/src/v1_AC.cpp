#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        for(int i=0;i<t;i++){
                int n,mn=INT_MAX,mx=0,ans=0,c;
                cin>>n;
                for(int i=0;i<n;i++){
                        cin>>c;
                        mx=max(mx,c);
                        mn=min(mn,c);
                }
                ans=(mx-mn)*2;
        cout<<ans<<"\n";
        }
}

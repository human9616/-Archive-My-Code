#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        for(int i=0;i<t;i++){
                int n,c,ans=0;
                cin>>n;
                for(int i=0;i<n;i++){
                        cin>>c;;
                        ans=max(ans,c);
                }
        cout<<"Case "<<i+1<<": "<<ans<<"\n";
        }
}

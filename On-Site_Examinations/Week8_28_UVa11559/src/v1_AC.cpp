#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,b,h,w;
        while(cin>>n>>b>>h>>w){
                int ans=INT_MAX;
                bool f=0;
                for(int i=0;i<h;i++){
                        int p,a;
                        cin>>p;
                        for(int j=0;j<w;j++){
                                cin>>a;
                                if(a>n && n*p<b){
                                        ans=min(ans,n*p);
                                        f=1;
                                }
                        }
                }
                if(f)cout<<ans<<"\n";
                else cout<<"stay home\n";
        }
}

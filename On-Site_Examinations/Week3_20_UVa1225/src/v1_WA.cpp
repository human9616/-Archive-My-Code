#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int ans[10]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i<10)ans[i]++;
            else{
                    int tmp=i;
                while(tmp>=1){
                    ans[tmp%10]++;
                    tmp/=10;
                }
            }
        }
        for(int i=0;i<10;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}

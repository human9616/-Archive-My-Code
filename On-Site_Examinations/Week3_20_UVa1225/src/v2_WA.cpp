#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        long long ans[10]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i<10)ans[i]++;
            else{
                    long long tmp=i;
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

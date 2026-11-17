#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==-1 && b==-1)break;
                int ans;
                if(a<b)ans=min(abs(b-a),abs((a+100)-b));
                else ans=min(abs(b-a),abs((b+100)-a));
                cout<<ans<<"\n";
        }
}

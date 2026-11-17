#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                a=sqrt(a);
                b=sqrt(b);
                cout<<b-a+1;
        }
}

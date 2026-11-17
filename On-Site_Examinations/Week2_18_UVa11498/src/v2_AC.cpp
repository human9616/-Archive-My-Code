#include<iostream>
using namespace std;
int main(){
    int n,a,b,x,y;
    while(cin>>n){
        cin>>a>>b;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(x>a){
                if(y>b)cout<<"NE\n";
                else if(y<b) cout<<"SE\n";
                else cout<<"divisa\n";
            }
            else if(x<a){
                if(y>b)cout<<"NO\n";
                else if(y<b) cout<<"SO\n";
                else cout<<"divisa\n";
            }
            else cout<<"divisa\n";
        }
    }
    return 0;
}

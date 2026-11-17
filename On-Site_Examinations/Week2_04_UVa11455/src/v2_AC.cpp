#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        int side[4] = {a, b, c, d};
        sort(side, side + 4);
        if(side[1]==side[2] && side[1]==side[3] && side[1]==side[0])cout<<"square\n";
        else if (side[0]==side[1] && side[2]==side[3])cout<<"rectangle\n";
        else if(side[3]<(side[1]+side[2]+side[0]))cout<<"quadrangle\n";
        else cout<<"banana\n";
    }
}

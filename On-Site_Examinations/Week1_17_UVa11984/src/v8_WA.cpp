#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    double c,d;
    cin>>t;
    for(int time=0;time<t;time++){
       cin >>c>>d;
       double ans=0;
       c=c*9/5+32+d;
       ans=(c-32)*5/9;
       cout<<"Case "<<time+1<<": "<< fixed << setprecision(2)<<ans;
       if(time+1!=1 || time+1!=t)cout<<"\n";
    }
}

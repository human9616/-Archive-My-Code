#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    double c,d;
    cin>>t;
    for(int time=0;time<t;time++){
       cin >>c>>d;
       double ans=c+((d-32)*5/9);
       cout<<"Case "<<time+1<<": "<< fixed << setprecision(2)<<ans<<"\n";
    }
}

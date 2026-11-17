#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    float c,d;
    while(cin>>t){for(int time=0;time<t;time++){
       cin>>c>>d;
      float ans;
       c=c*9/5+32+d;
       ans=(c-32)*5/9;
       cout<<"Case "<<time+1<<": "<< fixed << setprecision(2)<<ans<<"\n";
    }
    }
}

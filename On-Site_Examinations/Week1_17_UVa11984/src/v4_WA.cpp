#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    double c,d;
    for(int time=0;time<t;time++){
       cin >>c>>d;
       cout<<"Case "<<time+1<<": "<< fixed << setprecision(2)<<c+((d-32)*5/9)<<"\n";
    }
}

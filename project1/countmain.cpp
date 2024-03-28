#include <iostream>
#include "count.h"
//using namespace std;
int main(){
    cout<<"put your information:"<<endl;
    int x;char str[10];
    cin>>x>>str;

    count obj(str,x);

    int choice;
    while (true)
    {
        cout<<"1.deposite\n2.withdrow\n3.show\n0.return:"<<endl;
        cin>>choice;
        if(choice==0) break;
        if(choice==1) obj.deposite();
        else if(choice==2) obj.withdrow();
        else if(choice==3) obj.show();
    }

    return 0;
}
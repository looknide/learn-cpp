#include "iostream"
#include "count.h"
//using namespace std;

// 显示余额
void count::show(){
    cout<<"the "<<ID<<" "<<name<<"has "<<Ncount<<endl;
}

// 存款
void count::deposite(){
    cout<<"put the number you want to deposite:";
    float num;
    cin>>num;
    Ncount+=num;
    show();
}

// 取款
void count::withdrow(){
    cout<<"put the number you want to withdrow:";
    float num;
    cin>>num;
    if(Ncount<num){
        cout<<"there is no money!"<<endl;
    }
    else
        Ncount-=num;
    show();
}


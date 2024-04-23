#include "5_13main.h"
int h(X*hx){
    hx->i+=10;
    return hx->i;
}
int main(){
    X x(10);
    Y y;
    Z z;
    cout<<"use y:"<<y.g(&x)<<endl;//刚开始用‘’  warning
    cout<<"use z:"<<z.f(&x)<<endl;
    cout<<"use h:"<<h(&x)<<endl;
    return 0;
}
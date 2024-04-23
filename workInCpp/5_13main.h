#include "iostream"
using namespace std;
class X{
private:
    int i;
public:
    X(int I=0){
        i=I;
    }
    friend class Y;
    friend class Z;
    friend int h(X*hx);
    friend int g(X*gx);//友元函数所在的类也是友元，才能访问private成员变量
};
class Y{
public:
    int g(X*gx){
        (gx->i)++;
        return gx->i;
    }
};
class Z{
public:
    int f(X*zx){
        (zx->i)+=5;
        return zx->i;
    }
};
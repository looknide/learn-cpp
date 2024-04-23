//
// Created by qiu19 on 2024/4/18.
//
#include "iostream"
using namespace std;
class Complex{
private:
    double real;
    double imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){}
    void add(Complex c2){
        this->real+=c2.real;
        this->imag+=c2.imag;
    }
    void show(){
        cout<<"("<<real<<"+"<<imag<<"i)";
    }
};

int main(){
    Complex c1(3,5),c2(4.5);
    c1.add(c2);
    c1.show();
    return 0;
}

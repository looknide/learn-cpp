//编程实现小型公司的工资管理。该公司主要有4类人员：
//经理（manager）、兼职技术人员（technician）、销售员（salesman）和销售经理（salesmanager）。
//要求存储这些人员的编号、姓名和月工资，计算月工资并显示全部信息。
//月工资计算办法是：经理拿固定月薪8000元，兼职技术人员按每小时100元领取月薪，
//销售员按当月销售额的4%提成，销售经理既拿固定月工资也领取销售提成，
//固定月工资为5000元，销售提成为所管辖部门当月销售总额的千分之五。
//兼职技术人员一个月工作小时数、
//销售员一个月销售额、销售经理所管辖部门一个月销售总额由各个类的成员函数完成设置。
//（要求用抽象类和类继承）
#include "iostream"
using namespace std;
class Employee{
private:
    int num;
    string name;
    int salary;
protected:
    void setSalary(int s){
        salary=s;
    }
public:
    Employee(int n,string na,int s):num(n),name(na),salary(s){}
    virtual void getSalary()=0;
    void show(){
        cout<<num<<" "<<name<<" "<<salary<<endl;
    }
};

class manager:public Employee{
public:
    manager(int n,string na,int s):Employee(n,na,s){}
    void getSalary() override {
        setSalary(8000);
    }
};

class technician:public Employee{
private:
    int time;
public:
    technician(int n,string na,int s,int t):Employee(n,na,s),time(t){}
    void getSalary() override{
        setSalary(time*100);
    }
};

class salesman:public Employee{
private:
    int sales;
public:
    salesman(int n,string na,int s,int sa):Employee(n,na,s),sales(sa){}
    void getSalary() override{
        setSalary(sales*0.04);
    }
};

class salesManager:public Employee{
private:
    int sales;
public:
    salesManager(int n,string na,int s,int sa):Employee(n,na,s),sales(sa){}
    void getSalary() override{
        setSalary(5000+sales*0.005);
    }
};

int main(){
    manager m(1,"m",0);
    technician t(2,"t",0,100);
    salesman s(3,"s",0,1000);
    salesManager sm(4,"sm",0,10000);
    m.getSalary();
    t.getSalary();
    s.getSalary();
    sm.getSalary();
    m.show();
    t.show();
    s.show();
    sm.show();
    return 0;
}
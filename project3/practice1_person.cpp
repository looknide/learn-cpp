//
// Created by qiu19 on 2024/4/13.
//
//题目一：请设计一个描述杭电学校师生的抽象类 HDUPerson，
//要求有属性姓名、性别、年龄，有相应的构造函数与 Set、Get 方法，
//有成员函数 IntroduceSelf 实现自我介绍、纯虚函数GetCurrentNum，通过继承派生杭电学生类 Student和杭电教师类 Teacher,
//学生类中含在学的课程数，在教师类中含每周授课时数，在派生类中必须实现GetCurrentNum 获取学生的课程数或教师每周授课时数。
//在主程序中通过HDUPerson 类的指针动态构造学生对象（属性为 Tom、男、18岁，目前在学课程6门）与教师对象（属性为 Mary、女、31，目前每周授课8学时），
//通过指针调用基类方法IntroduceSelf（自我介绍时能表明是教师或学生） 与 GetCurrentNum，并写出你测试程序的输出结果。
#include "iostream"
using namespace std;
class person{
private:
    string name;
    bool gender;
    int age;
public:
    person(const string&n,bool g,int a){
        gender=g;
        age=a;
        name=n;
//        name=new char[strlen(n)+1];
//        ::strcpy(name,n);
    }
    virtual void IntroduceSelf(){
        cout<<"My name is "<<name<<".";
        cout<<"name:"<<name<<" ";
        if(gender){cout<<"male"<<" ";}
        else{cout<<"female"<<" ";}
        cout<<"age:"<<age<<endl;
    }
    virtual void getNum()=0;

};

class student:public person{
private:
    int classNum;
public:
    student(const string &n,bool g,int a,int num): person(n,g,a),classNum(num){}
    virtual void getNum();
};
void student::getNum(){//虚函数声明virtual定义不用写virtual
    cout<<"I'm a student.";
    person::IntroduceSelf();//虚函数被子类重写，调用父类虚函数原型时要写明作用域
    cout<<"I'm learning "<<classNum<<" courses."<<endl;
}

class teacher:public person{
private:
    int teachNum;
public:
    teacher(const string &n,bool g,int a,int num): person(n,g,a),teachNum(num){}
    virtual void getNum();
};

void teacher::getNum() {
    cout<<"I'm a teacher.";
    person::IntroduceSelf();
    cout<<"I teach "<<teachNum<<" hours per week."<<endl;
}


int main(){
    student std("qhl", false,18,20);
    teacher tea("chd", true,40,10);
    std.getNum();
    tea.getNum();
    return 0;
}
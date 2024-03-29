#include "iostream"
using namespace std;
//日期类，存放停机时间
class Data{
private:
    int year;
    int month;
    int day;
public:
    Data(int y,int m,int d);
    Data();//
    void print()const;
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;
};
Data::Data(int y, int m, int d) {
    year=y;
    month=m;
    day=d;
}
void Data::print()const {
    cout<<year<<"."<<month<<"."<<day;
}

int Data::GetYear() const {
    return year;
}

int Data::GetMonth() const {
    return month;
}

int Data::GetDay() const {
    return day;
}

class obj{
private:
    char type;//号码类型：用户类别，A机构，B企业，C个人
    char *number;//11位号码
    Data *OData=NULL;//停机日期指针,初始化
    int state;//状态：1.在用，2.未用，3.停用
public:
    obj(char t,char *num,int s);//Data *OD不是自己输入
    ~obj();
    obj(const obj& obj2);
    void print();//打印函数
    void stop(Data &a);//停机函数
};
obj::obj(char t, char *num, int s) {
    type=t;
    state=s;
    number=new char[12];
    for (int i = 0; i <12 ; i++) {
        number[i]=*num;
        num++;
    }
    number[12]='\0';
    cout<<"construct a new number:"<<number<<endl;
}

obj::~obj() {delete[]number;}
obj::obj(const obj &obj2){
    number=new char [13];
    number[0]='X';
    int j=0;
    for (int i = 1; i <=13 ; i++) {
        number[i]=obj2.number[j++];
    }
   state=obj2.state;
    type='D';
    if (obj2.OData!=NULL){
        OData=new Data(*obj2.OData);//名字=new 类型（初始化）
    }//类指针！=对象成员，不用在初始化列表中初始化
}
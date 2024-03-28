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
    Data();
    ~Data();
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
    Data * OData;//停机日期指针
    int state;//状态：1.在用，2.未用，3.停用
public:
    obj(char t,char *num,int s,Data OD);
    ~obj();
    obj(const Data& obj);

};
obj::obj(char t, char *num, int s,Data OD) {
    type=t;
    state=s;
    number=new char[12];
    for (int i = 0; i <11 ; i++) {
        number[i]=*num;
        num++;
    }
}
obj::~obj() {delete[]number;}
obj::obj(const Data &obj2){
    if (OData){

    }
}
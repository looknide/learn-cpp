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
//    Data();//
    int GetYear()const;//在对象中不能访问private成员，用函数在另一个类中访问
    int GetMonth()const;
    int GetDay()const;
    void print()const;
};
Data::Data(int y, int m, int d) {
    year=y;
    month=m;
    day=d;
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

void Data::print()const {
    cout<<"date:"<< this->GetYear()<<"."<< this->GetMonth()<< "."<<this->GetDay()<<endl;
}

class obj{
private:
    char type;//号码类型：用户类别，A机构，B企业，C个人
    char *number= nullptr;//11位号码
    Data *OData= nullptr;//停机日期指针,初始化
    char state;//状态：1.在用，2.未用，3.停用
public:
    obj(char t,char *num,char s);//Data *OD不是自己输入
    ~obj();
    obj(const obj& obj2);
    void print();//打印函数
    void stop(Data &a);//停机函数
};
obj::obj(char t, char *num, char s) {
    type=t;
    state=s;
    number=new char[15];
    for (int i = 0; i <12 ; i++) {
        number[i]=*num;
        num++;
    }
    number[12]='\0';
    cout<<"construct a new number:"<<number<<endl;
}

obj::~obj() {
    delete[]number;
    if (OData!= NULL){//delete 指针要判断指针是否为NULL
        delete OData;
    }
}
//拷贝构造函数，号码备份
obj::obj(const obj &obj2){
    cout<<"Construct a copy of phone "<<obj2.number<<endl;
    number=new char [15];
//    int j=0;
    for (int i = 0; i <11 ; i++) {
        number[i]=obj2.number[i];
    }
    number[11]='X';
    number[12]='\0';
   state=obj2.state;
    type='D';
    if (obj2.OData!= nullptr){
        OData=new Data(*obj2.OData);//名字=new 类型（初始化）
    }//类指针！=对象成员，不用在初始化列表中初始化
    //拷贝类指针->用指针的内容初始化
}

void obj::print() {
    cout<<"number:"<<number<<endl;
    cout<<"type:"<<type<<endl;
    cout<<"state:"<<state<<endl;
    this->OData->print();
}

void obj::stop(Data &a) {
    state='3';
    OData=new Data(a.GetYear(),a.GetMonth(),a.GetDay());//对类的new初始化
    cout<<"Stop the phone "<<number<<endl;
}
int main(){
    char n[12];char OT;char OS;
    int Oy,Om,Od,t;
    cin>>t;
    while (t--){
    cout<<"put your number:";
    cin>>n;
    cout<<"state:";
    cin>>OS;
    cout<<"type:";
    cin>>OT;
    cout<<"date:";
    cin>>Oy>>Om>>Od;
    Data D(Oy,Om,Od);
    obj phone(OT,n,OS);
    phone.print();
    obj phone2(phone);
    phone2.print();
    phone2.stop(D);
    phone.print();
    cout<<"---
    return 0;
}
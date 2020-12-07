#include <iostream>
#include<iomanip>
using namespace std;

class Book
{
protected:
    string code, name, author, press, number; //索取号、书名、作者、出版社、最大借阅量
    bool Is_lend;  //书是否借出

public:
    Book(string c, string n, string a, string p, string num) //构造函数
    {
        code = c; name = n; author = a;
        press = p; number = num;
        Is_lend = false;
    }
    Book(){Is_lend=false;}
    string Getcode(){return code;}      //获取图书的索引号
    string GetName(){return name;}      //获取图书的名字
    string GetAuthor(){return author;}  //获取图书的作者
    string GetPress(){return press;}    //获取图书的出版社
    string GetNumber(){return number;}  //获取图书的数量
    void SetCode(string c);             //设置图书的索引号
    void SetName(string n);             //设置图书的名字
    void SetAuthor(string a);           //设置图书的作者
    void SetPress(string p);            //设置图书的出版社
    void SetNumber(string num);         //设置图书的数量
    void Display();
};

void Book::SetCode(string c) {
    code = c;
}

void Book::SetName(string n) {
    name = n;
}

void Book::SetAuthor(string a){
    author = a;
}

void Book::SetPress(string p) {
    press = p;
}

void Book::SetNumber(string num) {
    number = num;
}

void Book::Display() {
    cout<<"索引号："<<setw(10)<<Getcode()<<"书名："<<setw(10)<<GetName()<<"作者："<<setw(10)<<GetAuthor()
    <<"出版社："<<setw(10)<<GetPress()<<"馆藏数量："<<setw(10)<<GetNumber()<<endl;
}

class User                     //用户类
{
protected:
    string name;               //用户姓名
    string ID;                 //用户账号
    string key;                //用户账号密码
    bool Is_Admin,Is_Student;  //用户类型

public:
    User(string n, string id, string k)  //构造函数
    {
        name = n; ID = id; key = k;
    }
    static int User_Number;
    void SetIdentity(bool ad,bool is)//设置用户类型
    {Is_Admin=ad;Is_Student=is;}
    int Judge();                   //判断用户类型
    void SetName(string n);        //设置用户姓名
    void SetID(string id);         //设置账号
    void SetKey(string k);         //设置密码
    string GetName(){return name;} //获取用户姓名
    string GetID(){return ID;}     //获取用户账号
    string GetKey(){return key;}   //获取用户密码
    bool GetIsAdmin(){return Is_Admin;}\
    bool GetIsStudent(){return Is_Student;}
};

int User::Judge() {
    if(Is_Admin==true) return 3;
    else return 4;
    //(Is_Student==true)
}

void User::SetName(string n) {
    name = n;
}

void User::SetID(string id) {
    ID = id;
}

void User::SetKey(string k) {
    key = k;
}

int User::User_Number=0;

class Log
{
public:
    User u;       //存储登录成功用户的信息
    void Login(User *p);   //登陆
    bool Is_Log;

};

void Log::Login(User *p) {
    string a,b;
    int flag=0;
    cout<<"请输入学号："<<endl;
    cin>>a;
    cout<<"请输入密码："<<endl;
    cin>>b;
    for(int i=0; i<User::User_Number;i++)
    {
        if(a==p[i].GetID()&&b==p[i].GetKey())
        {
            u.SetIdentity(p[i].GetIsAdmin(),p[i].GetIsStudent());
            u.SetID(a);u.SetKey(b);u.SetName(p[i].GetName());break;
            flag=1;
        }
    }
    if(flag==1)
    {
        if(u.Judge()==3)
        {
            cout<<"登录成功"<<endl;
            cout<<"尊敬的管理员"<<u.GetName()<<",您好！"<<endl;
            Is_Log=true;
        }
        if(u.Judge()==4)
        {
            cout<<"登录成功"<<endl;
            cout<<"亲爱的同学"<<u.GetName()<<",您好！"<<endl;
            Is_Log=true;
        }
    }
    else
    {
        cout<<"学号或密码错误"<<endl;
        Is_Log= false;
    }
}



class Admin: public User,public Log
{
public:
    static int Admin_Number;
    void log(User *U, Log a, Admin *A)
    {

    }
};

int main() {

}

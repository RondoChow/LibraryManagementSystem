#include <iostream>
#include<iomanip>
#include <fstream>
#include<string>
using namespace std;

class Book
{
protected:
    string code, Name, author, press, number; //索取号、书名、作者、出版社、最大借阅量
    bool Is_lend;  //书是否借出

public:
    Book(string c, string n, string a, string p, string num) //构造函数
    {
        code = c; Name = n; author = a;
        press = p; number = num;
        Is_lend = false;
    }
    static int Book_Number;             //图书的数量
    Book(){Is_lend=false;}
    string Getcode(){return code;}      //获取图书的索引号
    string GetName(){return Name;}      //获取图书的名字
    string GetAuthor(){return author;}  //获取图书的作者
    string GetPress(){return press;}    //获取图书的出版社
    string GetNumber(){return number;}  //获取图书的数量
    void SetCode(string c);             //设置图书的索引号
    void SetName(string n);             //设置图书的名字
    void SetAuthor(string a);           //设置图书的作者
    void SetPress(string p);            //设置图书的出版社
    void SetNumber(string num);         //设置图书的数量
    void Display();
    friend istream  &operator >> (istream &stream,Book &b);  //重载操作符>>
    friend ostream  &operator << (ostream &stream,Book &b);  //重载操作符<<
};

ostream &operator << (ostream &stream,Book &b)
{
    stream<<"索引号"<<setw(10)<<b.code<<" 书名:"<<setw(10)
          <<b.Name<<" 作者:"<<setw(10)<<b.author<<" 出版社:"
          <<setw(10)<<b.press<<endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)
{
    cout<<"请输入索引号:";
    stream>>b.code;
    cout<<"请输入书名:";
    stream>>b.Name;
    cout<<"请输入作者名:";
    stream>>b.author;
    cout<<"请输入出版社:";
    stream>>b.press;
    return stream;
}

void Book::SetCode(string c) {
    code = c;
}

void Book::SetName(string n) {
    Name = n;
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
int Book::Book_Number=0;


static string LogName;         //记录当前登陆用户的用户名
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
    User(){Is_Admin=0;Is_Student=1;};//默认读者类型
    int Judge();                   //判断用户类型
    void SetName(string n);        //设置用户姓名
    void SetID(string id);         //设置账号
    void SetKey(string k);         //设置密码
    string getName(){return name;} //获取用户姓名
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
            u.SetID(a);u.SetKey(b);u.SetName(p[i].getName());break;
            flag=1;
        }
    }
    if(flag==1)
    {
        if(u.Judge()==3)
        {
            LogName=u.getName();
            cout<<"登录成功"<<endl;
            cout<<"尊敬的管理员"<<u.getName()<<",您好！"<<endl;
            Is_Log=true;
        }
        if(u.Judge()==4)
        {
            LogName=u.getName();
            cout<<"登录成功"<<endl;
            cout<<"亲爱的同学"<<u.getName()<<",您好！"<<endl;
            Is_Log=true;
        }
    }
    else
    {
        cout<<"学号或密码错误"<<endl;
        Is_Log= false;
    }
}

//学生
class Student: public User, public Log, public Book
{
protected:
    string institute;

public:
    static int Student_Number;
    static int max_lent;

    Student(){SetIdentity(false, true);}
    //Student():User(){User::Is_Admin=false;User::Is_Student= true;}
    Student(string n, string id, string k,string in)//:User(n,id,k)
    {
        name=n;ID=id;key=k;institute=in;
    }

    void Book_Show(Book *B);   //图书展示
    void Book_Find(Book *B);   //查找图书
    void Book_LR();            //借阅情况
    void Book_Lent(Book *B);   //借书
};
int Student::max_lent=0;
int Student::Student_Number=0;

void Student::Book_Show(Book *B) {
    for(int i = 0 ; i< Book::Book_Number;i++)
    {
        cout<<B[i]<<endl;
    }
}

void Student::Book_Find(Book *B) {
    string a;

    cout<<"-------查找图书-------"<<endl;
    cout<<"请输入图书索引号或书名：";
    cin>>a;
    int flag=0,count=0;
    for( int i = 0 ; i < Book::Book_Number;i++)
    {
        if(a==B[i].Getcode()||a==B[i].GetName())
        {
            flag=1;
            count++;
            cout<<B[i];
        }
    }
    if(count==0)
    {
        cout<<"未找到此书"<<endl;
    }
    else
    {
        cout<<"共找到"<<count<<"本书。"<<endl;
    }
}

void Student::Book_LR() {
    cout<<"-------借阅信息-------"<<endl;
    cout<<"姓名："<<setw(10)<<getName()<<"学号："<<setw(10)<<GetID()<<"学院："<<setw(10)<<institute<<"最大借阅量"<<setw(10)<<max_lent<<endl;

}

void Student::Book_Lent(Book *B) {

}

//图书馆管理员
class Admin: public User,public Log
{
public:
    static int Admin_Number;

    Admin(){SetIdentity(true, false);}
    Admin(string n, string id, string k,User *U)
    {
        U[User_Number].SetName(n);
        U[User_Number].SetID(id);
        U[User_Number].SetKey(k);
        SetIdentity(true, false);
        U->User_Number++;
        name=n;
        key=k;
    }

    static void Book_Add(Book *B);     //添加图书
    void Book_Delete(Book *B);  //删除图书
    void Book_Alter(Book *B);   //修改图书信息
    void Book_Find(Book *B);    //查找图书
};

//添加图书
void Admin::Book_Add(Book *B) {
    string aa;
    cout<<"-------添加图书-------"<<endl;
    while(1)
    {
        cin>>B[Book::Book_Number];
        ofstream bookmessage("Bookmessage.txt",ios::app);
        if(bookmessage.is_open())
        {
            bookmessage << "操作:增加图书 "<<endl;
            bookmessage <<B[Book::Book_Number]<<endl;
            bookmessage.close();
        }
        Book::Book_Number++;
        cout<<"录入成功！"<<endl;
        aa=cin.get();
        cout<<"按任意键继续录入(输入'0'可返回主菜单)，";
        aa=cin.get();
        if(aa=="0")break;
    }
}

//删除图书
void Admin::Book_Delete(Book *B) {
    cout<<"-------删除图书-------"<<endl;
    string a;

    if(Book::Book_Number==0) cout<<"当前无图书，请先添加图书"<<endl;
    else
    {
        cout<<"请输入图书索引号或书名：";
        cin>>a;
        int flag=0,find=0;
        for( int i = 0 ; i < Book::Book_Number ; i++)
        {
            if(a==B[i].GetName()||a==B[i].Getcode())
            {
                find=i;flag=1;
                break;
            }
        }
        if(flag==1)
        {
            char b;
            cout<<"已找到图书，索引号为："<<setw(10)<<B[find].Getcode()<<"书名为："<<setw(10)<<B[find].GetName()<<endl;
            cout<<"是否删除？（y/n）："<<endl;
            cin>>a;
            if(b=='y')
            {
                for( int i=find; i < Book::Book_Number; i++)
                {
                    if(i==Book::Book_Number-1){Book::Book_Number--;break;}
                    B[i]=B[i+1];
                }
                ofstream bookmessage("Bookmessage.txt",ios::app);
                if(bookmessage.is_open())
                {
                    bookmessage << "操作:删除图书 "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }
                cout<<"删除成功！"<<endl;
            }
            else
            {
                cout<<"取消删除。"<<endl;
            }
        }
        else
        {
            cout<<"图书不存在！"<<endl;
        }
    }
}

//修改图书
void Admin::Book_Alter(Book *B) {
    cout<<"-------修改图书信息-------"<<endl;
    string a;
    if(Book::Book_Number==0) cout<<"当前无图书，请先添加图书"<<endl;
    else
    {
        cout<<"请输入图书索引号或书名：";
        cin>>a;
        int flag=0,find=0;
        for( int i = 0 ; i < Book::Book_Number ; i++)
        {
            if(a==B[i].GetName()||a==B[i].Getcode())
            {
                find=i;flag=1;
                break;
            }
        }
        if(flag==1)
        {
            char b;
            cout<<"已找到图书，索引号为："<<setw(10)<<B[find].Getcode()<<"书名为："<<setw(10)<<B[find].GetName()<<endl;
            cout<<"是否修改？（y/n）："<<endl;
            cin>>b;
            if(b=='y') {
                cout << "1-修改索引号" << endl;
                cout << "2-修改书名" << endl;
                cout << "3-修改作者" << endl;
                cout << "4-修改出版社" << endl;
                cout << "0-退出修改" << endl;

                int c;
                cin>>c;
                switch (c) {
                    case 1:
                    {
                        while(1)
                        {
                            cout<<"请输入修改后的索引号"<<endl;
                            int flag=1;
                            cin>>a;
                            for(int i=0;i<Book::Book_Number;i++)
                            {
                                if(B[i].Getcode()==a)
                                {
                                    flag=0;
                                    break;
                                }
                            }
                            if(flag)
                            {
                                B[find].SetCode(a);
                                cout<<"已修改！"<<endl;
                                break;
                            }
                            else
                            {
                                cout<<"已存在该索引号，请修改！"<<endl;
                            }
                        }
                    }break;

                    case 2:
                    {
                        cout<<"请输入修改后的书名："<<endl;
                        cin>>a;
                        B[find].SetName(a);
                        cout<<"已修改！"<<endl;
                        break;
                    }

                    case 3:
                    {
                        cout<<"请输入修改后的作者："<<endl;
                        cin>>a;
                        B[find].SetAuthor(a);
                        cout<<"已修改！"<<endl;
                        break;
                    }

                    case 4:
                    {
                        cout<<"请输入修改后的出版社："<<endl;
                        cin>>a;
                        B[find].SetPress(a);
                        cout<<"已修改！"<<endl;
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                }
                ofstream bookmessage("Bookmessage.txt",ios::app);
                if(bookmessage.is_open())
                {
                    bookmessage << "操作:修改图书 "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }


            }
        }
        else
        {
            cout<<"图书不存在！"<<endl;
        }

    }

}

//查找图书
void Admin::Book_Find(Book *B) {
    string a;

    cout<<"-------查找图书-------"<<endl;
    cout<<"请输入图书索引号或书名：";
    cin>>a;
    int flag=0,count=0;
    for( int i = 0 ; i < Book::Book_Number;i++)
    {
        if(a==B[i].Getcode()||a==B[i].GetName())
        {
            flag=1;
            count++;
            cout<<B[i];
        }
    }
    if(count==0)
    {
        cout<<"未找到此书"<<endl;
    }
    else
    {
        cout<<"共找到"<<count<<"本书。"<<endl;
    }
}

int main() {

}

#include <iostream>
#include<iomanip>
#include <fstream>
#include<string>
using namespace std;

class Book
{
protected:
    string code, Name, author, press;
    int number; //索取号、书名、作者、出版社、最大借阅量
    bool Is_lend;  //书是否借出

public:
    static int Book_Number;
    Book(string c, string n, string a, string p,int num) //构造函数
    {
        code = c; Name = n; author = a;
        press = p;number=num;
        Is_lend = false;
        Book_Number++;
    }
                //图书的数量
    Book(){Is_lend=false;}
    string Getcode(){return code;}      //获取图书的索引号
    string GetName(){return Name;}      //获取图书的名字
    string GetAuthor(){return author;}  //获取图书的作者
    string GetPress(){return press;}    //获取图书的出版社
    int GetNumber(){return number;}     //获取图书的数量
    void SetCode(string c);             //设置图书的索引号
    void SetName(string n);             //设置图书的名字
    bool GetIs_Lend(){return Is_lend;}; //获取书的借阅情况
    void SetIs_Lend(bool);              //设置书的借阅情况

    void SetAuthor(string a);           //设置图书的作者
    void SetPress(string p);            //设置图书的出版社
    void SetNumber(int num);            //设置图书的数量
    void Display();
    friend istream  &operator >> (istream &stream,Book &b);  //重载操作符>>
    friend ostream  &operator << (ostream &stream,Book &b);  //重载操作符<<
};
void Book::SetIs_Lend(bool a){Is_lend =a;}

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

void Book::SetNumber(int num) {
    number = num;
}

void Book::Display() {
    cout<<"索引号："<<Getcode()<<setw(-10)<<"书名："<<GetName()<<setw(10)<<"作者："<<GetAuthor()<<setw(10)
    <<"出版社："<<GetPress()<<setw(10)<<endl;
}
int Book::Book_Number=0;


static string LogName;         //记录当前登陆用户的用户名
class User                     //用户类
{
protected:
    string name;               //用户姓名
    string ID;                 //用户账号
    string key;                //用户账号密码
    string institute;          //用户学院
    bool Is_Admin,Is_Student;  //用户类型

public:
    User(string n, string id, string k, string i)  //构造函数
    {
        name = n; ID = id; key = k; institute = i;
    }
    static int User_Number;
    void SetIdentity(bool ad,bool is)//设置用户类型
    {Is_Admin=ad;Is_Student=is;}
    User(){Is_Admin=0;Is_Student=1;};//默认读者类型
    int Judge();                   //判断用户类型
    void Setname(string n);        //设置用户姓名
    void SetID(string id);         //设置账号
    void SetIs_Lend(bool);
    void SetKey(string k);         //设置密码
    void SetInstitute(string i);   //设置学院
    string getName(){return name;} //获取用户姓名
    string GetID(){return ID;}     //获取用户账号
    string GetKey(){return key;}   //获取用户密码
    string GetInstitute(){return institute;}
    bool GetIsAdmin(){return Is_Admin;}\
    bool GetIsStudent(){return Is_Student;}
};

int User::Judge() {
    if(Is_Admin==true) return 3;
    else return 4;
    //(Is_Student==true)
}

void User::Setname(string n) {
    name = n;
}

void User::SetID(string id) {
    ID = id;
}

void User::SetKey(string k) {
    key = k;
}

void User::SetInstitute(string i) {
    institute = i;
}

int User::User_Number=0;

class Log
{
public:
    User u;       //存储登录成功用户的信息
    int number;
    void SignIN(User *p);  //注册
    void Login(User *p);   //登陆
    bool Is_Log;
    Log(){number=0;};

};

void Log::SignIN(User *p) {
    string a;
    int f;
    while(1)
    {
        f=1;
        cout<<"请输入学号：";
        cin>>a;
        for(int i=0;i<=User::User_Number;i++)
        {
            if(p[i].GetID()==a)
            {
                cout<<"该学生已注册！"<<endl;
                f=0;
            }
        }
        if(f==1){break;}
    }

    string b,bb;
    string c, cc;
    while(1)
    {
        cout<<"请输入姓名："<<endl;
        cin>>b;
        cout<<"请输入学院："<<endl;
        cin>>bb;
        cout<<"请输入密码："<<endl;
        cin>>c;
        cout<<"请再次输入密码："<<endl;
        cin>>cc;
        if(cc!=c)
        {
            cout<<"两次输入密码不一致，请重新输入。"<<endl;
        }
        if(cc==c)
        {
            break;
        }
    }
    (p+User::User_Number)->Setname(b);
    (p+User::User_Number)->SetID(a);
    (p+User::User_Number)->SetKey(c);
    (p+User::User_Number)->SetIdentity(false,true);
    (p+User::User_Number)->SetInstitute(bb);
    u.Setname(b);
    u.SetID(a);
    u.SetKey(c);
    u.SetInstitute(bb);
    number=User::User_Number;
    User::User_Number++;

}

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
            u.SetID(a);u.SetKey(b);u.Setname(p[i].getName());flag=1;
            break;

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
        else if(u.Judge()==4)
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

    Book s[100];
public:
    static int Student_Number;
    static int max_lent;
    void zhuce(User *U, Log a, Student *S)
    {
        a.SignIN(U);
        Is_Student= true;
        cout<<"注册成功！"<<endl;
        U[a.number].SetIdentity(false, true);
        SetIdentity(false, true);
        User::Setname(a.u.getName());
        User::SetID(a.u.GetID());
        User::SetKey(a.u.GetKey());
        User::SetInstitute(a.u.GetInstitute());
        S[Student::Student_Number].Setname(a.u.getName());
        Student::Student_Number++;
    }
    Student():User(){User::Is_Admin= false;User::Is_Student= true;}


    void Book_Show(Book *B);   //图书展示
    void Book_Find(Book *B);   //查找图书
    void Book_LR();            //借阅情况
    void Book_Lent(Book *B);   //借书
    void Book_Ruturn(Book *B);
};
int Student::max_lent=10;
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
    cout<<"---------借阅信息---------"<<endl;
    int n=10;
    int flag=0;
    cout<<"姓名："<<setw(10)<<getName()<<"学号："<<setw(10)<<GetID()<<"学院："<<setw(10)<<institute<<"最大借阅量："<<setw(10)<<max_lent<<endl;
    cout<<"当前借书信息:"<<endl;
    for(int i=0;i<=s->Book_Number;i++)
    {
        if(s[i].GetIs_Lend()==true){flag=1;break;}
    }
    if(flag==0)cout<<"无借书记录\n";
    else
    {
        int LendBookNumber=0;
        for(int i=0;i<=Book::Book_Number;i++)
        {
            if(s[i].GetIs_Lend()==true)
            { s[i].Display();
                LendBookNumber++;
            }
        }

        cout<<"还可以借"<<n-LendBookNumber<<"本书."<<endl<<endl;
    }
}

void Student::Book_Lent(Book *B) {
    for(int i=0;i<Book_Number;i++)
    {
        (s+i)->SetCode((B+i)->Getcode());
        (s+i)->SetName((B+i)->GetName());
        (s+i)->SetAuthor((B+i)->GetAuthor());
        (s+i)->SetPress((B+i)->GetPress());
        (s+i)->Book_Number=(B+i)->Book_Number;
    }
    Book *b=B;
    string a;
    cout<<"---------借书---------"<<endl;
    cout<<"请输入需要借阅书籍的索引号或书名:";
    cin>>a;
    int Find=0,flag1=0;
    int LendBookNumber=0;
    for(int i=0;i<=Book::Book_Number;i++)
    {
        if((a==b[i].Getcode()||a==b[i].GetName())&&b[i].GetIs_Lend()==false)
        {
            flag1=1;Find =i;break;
        }
    }
    for(int i=0;i<=Book::Book_Number;i++)
    {
        if(s[i].GetIs_Lend()==true)
        {
            LendBookNumber++;
        }
    }
    if(!flag1)cout<<"图书不存在或已经被借出!"<<endl;
    else
    {
        if(LendBookNumber==10) {
            throw LendBookNumber;
        }
        cout<<"借阅成功!"<<endl;
        b[Find].SetIs_Lend(true);
        s[Find].SetIs_Lend(true);
        ofstream lendmessage("Lendmessage.txt",ios::app);
        if(lendmessage.is_open())
        {
            lendmessage << "姓名:"<<LogName<<endl;
            lendmessage << "    借书索引号:"<<s[Find].Getcode();
            lendmessage.close();
        }
    }
}

void Student::Book_Ruturn(Book *B)
{
    Book *b=B;int flag=0,Find=0;
    cout<<"---------还书---------"<<endl;
    string a;
    cout<<"请输入需要归还书籍的索引号或书名:";
    cin>>a;
    for(int j=0;j<Book::Book_Number;j++)
    {
        if(a==b[j].Getcode()||a==b[j].GetName())
        {
            flag=1;Find =j;break;
        }
    }
    if(flag==1){
        if(s[Find].GetIs_Lend()==true)
        {

               s[Find].SetIs_Lend(false);
                b[Find].SetIs_Lend(false);
                ofstream lendmessage("Lendmessage.txt",ios::app);
                if(lendmessage.is_open())
                {
                    lendmessage << "姓名:"<<LogName<<endl;
                    lendmessage << "    还书编号:"<<s[Find].Getcode();
                    lendmessage.close();
                }
                cout<<"归还成功！"<<endl;

        }
        else
        {
            cout<<"此书未被借阅"<<endl;
        }
    }
    else
    {
        cout<<"未找到此书！"<<endl;
    }
}

//图书馆管理员
class Admin: public User,public Log
{
public:
    static int Admin_Number;



    Admin(){SetIdentity(true, false);}
    Admin(string n, string id, string k,User *U)
    {
        U[U->User_Number].Setname(n);
        U[U->User_Number].SetKey(k);
        U[U->User_Number].SetID(id);
        Is_Admin=1;Is_Student=0;
        U[U->User_Number].SetIdentity(true,false);
        U->User_Number++;
        name=n;
        key=k;
    }
    //图书管理
    static void Book_Add(Book *B);     //添加图书
    void Book_Delete(Book *B);         //删除图书
    void Book_Alter(Book *B);          //修改图书信息
    void Book_Find(Book *B);           //查找图书
    //学生管理
    void Student_Add(User *U, Student *S);    //增加学生
    void Student_Delete(User *U, Student *S); //删除学生
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

//增加学生
void Admin::Student_Add(User *U, Student *S) {
    Log a;
    S[Student::Student_Number].zhuce(U,a,S);
}

void Admin::Student_Delete(User *U, Student *S) {
    string a;
    cout<<"请输入要删除学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].GetName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        for(int i=find;i<Student::Student_Number;i++)
        {
            S[i]=S[i+1];
            if(i==Student::Student_Number-1){Student::Student_Number--;break;}
        }
        for(int i=0;i<U->User_Number;i++)
        {
            if(U[i].getName()==a)
            {
                find1=i;
                break;
            }
        }
        for(int i=find1;i<U->User_Number;i++)
        {
            if(i==U->User_Number-1)
            {
                U->User_Number--;break;
            }
            U[i]=U[i+1];
        }

    }
}
int Admin::Admin_Number=1;

void main_interface()
{
    cout<<"I———————————————图书管理系统—————————————————I"<<endl;
    cout<<"I—————————————①------注册------————————————I"<<endl;
    cout<<"I—————————————②------登陆------————————————I"<<endl;
    cout<<"I—————————————③------退出------————————————I"<<endl;
}

void Student_interface()
{
    cout<<"①-------查看图书"<<endl;
    cout<<"②-------借书"<<endl;
    cout<<"③-------还书"<<endl;
    cout<<"④-------查询借还信息"<<endl;
    cout<<"⑤-------图书展示"<<endl;
    cout<<"⑥-------退出"<<endl;
}

void Admin_interface()
{
    cout<<"①-------增加图书"<<endl;
    cout<<"②-------修改图书"<<endl;
    cout<<"③-------删除图书"<<endl;
    cout<<"④-------查询图书"<<endl;
    cout<<"⑤-------增加学生"<<endl;
    cout<<"⑥-------删除学生"<<endl;
    cout<<"⑦-------退出"<<endl;
}

Book B[100]{Book("10000","C++","张三","A出版社",2),Book("10001","C","李四","777",3),Book("10002","C#","王五","888",1)};
User U[100];
Student S[100];
Admin A[100]{Admin("A","8","123",U)};
Log c;

int main() {
    while(1)
    {
        cout<<Book::Book_Number<<endl;
        main_interface();
        int a;
        string aa;cin>>aa;
        if( aa=="1" ) a=1;
        else if(aa=="2")a=2;
        else if(aa=="3")a=3;
        else{
            cout<<"请按要求输入！"<<endl;
            continue;
        }
        switch (a) {
            case 1:
            {
                cout<<"       学生注册"<<endl;
                S[Student::Student_Number].zhuce(U,c,S);
                break;
            }
            case 2:
            {
                cout<<"       登陆"<<endl;
                c.Login(U);
                if(c.Is_Log==false)break;

                if(c.u.Judge()==3)     //图书管理员
                {
                    int n=1;
                    while(n)
                    {
                        Admin_interface();
                        int b;
                        cin>>b;
                        switch(b)
                        {
                            case 1:
                            {
                                A[c.number].Book_Add(B);
                                break;
                            }
                            case 2:
                            {
                                A[c.number].Book_Alter(B);
                                break;
                            }
                            case 3:
                            {
                                A[c.number].Book_Delete(B);
                                break;
                            }
                            case 4:
                            {
                                A[c.number].Book_Find(B);
                                break;
                            }
                            case 5:
                            {
                                A[c.number].Student_Add(U,S);
                                break;
                            }
                            case 6:
                            {
                                A[c.number].Student_Delete(U,S);
                                break;
                            }
                            default:
                                n=0;
                        }
                    }
                }
                else if(c.u.Judge()==4)
                {
                    int n =1;
                    while(n)
                    {
                        Student_interface();
                        int b;cin>>b;
                        switch(b)
                        {
                            case 1:
                            {
                                S[c.number].Book_Find(B);
                                break;
                            }
                            case 2:
                            {

                                try{
                                    S[c.number].Book_Lent(B);
                                }
                                catch(int Num)
                                {
                                    cout<<"超出最大借书数量，借书失败。"<<endl;
                                }

                                break;
                            }
                            case 3:
                            {
                                S[c.number].Book_Ruturn(B);
                                break;
                            }
                            case 4:
                            {
                                S[c.number].Book_LR();
                                break;
                            }
                            case 5:
                            {
                                S[c.number].Book_Show(B);
                                break;
                            }
                            default:
                                n=0;
                        }

                    }
                }
                else break;

            }
            case 3:
            {
                cout<<"             系统已退出"<<endl;
                return 0;
                break;
            }
            default:
                break;

        }
        cin.get();//吸收回车符
        cout<<"按回车键返回主界面\n";
        cin.get();
    }
    return 0;
}

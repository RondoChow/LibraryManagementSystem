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
    void Display();                     //图书展示
    friend istream  &operator >> (istream &stream,Book &b);  //重载操作符>>
    friend ostream  &operator << (ostream &stream,Book &b);  //重载操作符<<
};
void Book::SetIs_Lend(bool a){Is_lend =a;}

ostream &operator << (ostream &stream,Book &b)  //重载操作符<<
{
    stream<<"索引号"<<setw(10)<<b.code<<" 书名:"<<setw(10)
          <<b.Name<<" 作者:"<<setw(10)<<b.author<<" 出版社:"
          <<setw(10)<<b.press<<endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)  //重载操作符>>
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

void Book::SetCode(string c) {  //设置图书的索引号
    code = c;
}

void Book::SetName(string n) {  //设置图书的名字
    Name = n;
}

void Book::SetAuthor(string a){  //设置图书的作者
    author = a;
}

void Book::SetPress(string p) {  //设置图书的出版社
    press = p;
}

void Book::SetNumber(int num) {  //设置图书的数量
    number = num;
}

void Book::Display() {    //图书展示
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
    bool Is_Librarian,Is_Admin,Is_Student;  //用户类型

public:
    User(string n, string id, string k, string i)  //构造函数
    {
        name = n; ID = id; key = k; institute = i;
    }
    static int User_Number;
    void SetIdentity(bool il,bool is,bool ia)//设置用户类型
    {Is_Librarian=il;Is_Student=is;Is_Admin=ia;}
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
    string GetInstitute(){return institute;}  //设置用户学院
    bool GetIsAdmin(){return Is_Admin;}
    bool GetIsStudent(){return Is_Student;}
    bool GetIsLibrarian(){return Is_Librarian;}
};

int User::Judge() {    //判断用户类型
    if(Is_Librarian==true) return 3;
    if(Is_Student) return 4;
    if(Is_Admin==true) return 5;
}

//设置用户姓名
void User::Setname(string n) {
    name = n;
}

//设置账号
void User::SetID(string id) {
    ID = id;
}

//设置用户姓名
void User::SetKey(string k) {
    key = k;
}

//设置用户学院
void User::SetInstitute(string i) {
    institute = i;
}

//初始化用户数量
int User::User_Number=0;

class Log
{
public:
    User u;       //存储登录成功用户的信息
    int number;
    void SignIN(User *p);  //注册
    void Login(User *p);   //登陆
    bool Is_Log;  //判断是否登陆成功
    Log(){number=0;}; //构造函数

};

//注册
void Log::SignIN(User *p) {
    string a;
    int f;
    while(1)
    {
        f=1;
        cout<<"请输入学号/工号：";
        cin>>a;
        //判断该学生是否注册
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
    (p+User::User_Number)->SetIdentity(false,true,false);
    (p+User::User_Number)->SetInstitute(bb);
    u.Setname(b);
    u.SetID(a);
    u.SetKey(c);
    u.SetInstitute(bb);
    number=User::User_Number;
    User::User_Number++;

}
//登陆
void Log::Login(User *p) {
    string a,b;
    int flag=0;
    cout<<"请输入学号/工号："<<endl;
    cin>>a;
    cout<<"请输入密码："<<endl;
    cin>>b;

    for(int i=0; i<User::User_Number;i++)
    {
        if(a==p[i].GetID()&&b==p[i].GetKey())
        {
            u.SetIdentity(p[i].GetIsLibrarian(),p[i].GetIsStudent(),p[i].GetIsAdmin());
            u.SetID(a);u.SetKey(b);u.Setname(p[i].getName());
            flag=1; //若账号与密码都正确，则flag=1，否则为0
            break;

        }
    }
    //登陆成功
    if(flag==1)
    {
        if(u.Judge()==3)
        {
            LogName=u.getName();
            cout<<"登录成功"<<endl;
            cout<<"尊敬的图书管理员"<<u.getName()<<",您好！"<<endl;
            Is_Log=true;
        }
        else if(u.Judge()==4)
        {
            LogName=u.getName();
            cout<<"登录成功"<<endl;
            cout<<"亲爱的同学"<<u.getName()<<",您好！"<<endl;
            Is_Log=true;
        }
        else if(u.Judge()==5)
        {
            LogName=u.getName();
            cout<<"登录成功"<<endl;
            cout<<"尊敬的系统管理员"<<u.getName()<<",您好！"<<endl;
            Is_Log=true;
        }
    }
    //登陆失败
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
        U[a.number].SetIdentity(false, true,false);
        SetIdentity(false, true,false);
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
    void Book_Ruturn(Book *B); //还书
};
int Student::max_lent=10; //学生最大借阅量为10本书
int Student::Student_Number=0; //初始化学生数量

//图书展示
void Student::Book_Show(Book *B) {
    for(int i = 0 ; i< Book::Book_Number;i++)
    {
        cout<<B[i]<<endl;
    }
}
//查找图书
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
//借阅信息
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
//借书
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
    //查找图书
    for(int i=0;i<=Book::Book_Number;i++)
    {
        if((a==b[i].Getcode()||a==b[i].GetName())&&b[i].GetIs_Lend()==false)
        {
            //若该图书存在且未被借出，flag=1，否则为0；find定位图书位置
            flag1=1;Find =i;break;
        }
    }

    for(int i=0;i<=Book::Book_Number;i++)
    {
        if(s[i].GetIs_Lend())
        {
            LendBookNumber++;
        }
    }
    //图书不存在或已经被借出
    if(!flag1)cout<<"图书不存在或已经被借出!"<<endl;
    //借书操作
    else
    {
        //若以达到最大借阅量，抛出异常
        if(LendBookNumber==10) {
            throw LendBookNumber;
        }
        cout<<"借阅成功!"<<endl;
        //设置图书为已借出
        b[Find].SetIs_Lend(true);
        s[Find].SetIs_Lend(true);
        //借书信息存入输出文件
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
    //查找图书
    for(int j=0;j<Book::Book_Number;j++)
    {
        if(a==b[j].Getcode()||a==b[j].GetName())
        {
            //若该图书存在，flag=1，否则为0；find定位图书位置
            flag=1;Find =j;break;
        }
    }
    //若图书存在，则判断图书是否接触
    if(flag==1){
        //图书被借出
        if(s[Find].GetIs_Lend()==true)
        {
                //设置图书为未被借出
               s[Find].SetIs_Lend(false);
                b[Find].SetIs_Lend(false);
                //借书信息从文件中删除
                ofstream lendmessage("Lendmessage.txt",ios::app);
                if(lendmessage.is_open())
                {
                    lendmessage << "姓名:"<<LogName<<endl;
                    lendmessage << "    还书编号:"<<s[Find].Getcode();
                    lendmessage.close();
                }
                cout<<"归还成功！"<<endl;

        }
        //图书为被借出
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
class Librarian: public User,public Log
{
public:
    static int Librarian_Number;
    //管理员注册
    void zhuce(User *U, Log a, Librarian *L)
    {
        a.SignIN(U);
        Is_Admin= true;
        cout<<"注册成功！"<<endl;
        U[a.number].SetIdentity(true, false,false);
        SetIdentity(true, false,false);
        User::Setname(a.u.getName());
        User::SetID(a.u.GetID());
        User::SetKey(a.u.GetKey());
        User::SetInstitute(a.u.GetInstitute());
        L[Librarian::Librarian_Number].Setname(a.u.getName());
        Librarian::Librarian_Number++;
    }

    Librarian(){SetIdentity(true, false,false);}
    Librarian(string n, string id, string k,User *U)
    {
        U[U->User_Number].Setname(n);
        U[U->User_Number].SetKey(k);
        U[U->User_Number].SetID(id);
        Is_Admin=1;Is_Student=0;
        U[U->User_Number].SetIdentity(true,false,false);
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
    void Student_Find(Student *S);            //学生的借阅情况
    void StudentLent(Student *S, Book *B);    //学生借书
    void StudentReturn(Student *S,Book *B);   //学生还书
};

void Librarian::StudentLent(Student *S,Book *B) { //学生
    //查找学生信息
    string a;
    cout<<"请输入学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    //学生借书
    S->Book_Lent(B);
}

void Librarian::StudentReturn(Student *S,Book *B) //学生还书
{
    //查找学生信息
    string a;
    cout<<"请输入学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    //学生还书
    S->Book_Ruturn(B);
}

//添加图书
void Librarian::Book_Add(Book *B) {
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
void Librarian::Book_Delete(Book *B) {
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
void Librarian::Book_Alter(Book *B) {
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

void Librarian::Student_Find(Student *S) {

    string a;
    cout<<"请输入要查询学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    S[find].Book_LR();
}

//查找图书
void Librarian::Book_Find(Book *B) {
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
void Librarian::Student_Add(User *U, Student *S) {
    Log a;
    S[Student::Student_Number].zhuce(U,a,S);
    cout<<Student::Student_Number<<endl;
}

void Librarian::Student_Delete(User *U, Student *S) {
    string a;
    cout<<"请输入要删除学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        char c;
        cout<<"已找到学生，索引号为："<<setw(10)<<S[find].getName()<<setw(10)<<S[find].GetInstitute()<<setw(10)<<S[find].GetID()<<setw(10)<<endl;
        cout<<"是否删除？（y/n）："<<endl;
        cin>>c;
        if(c=='y') {
            for (int i = find; i < Student::Student_Number; i++) {
                S[i] = S[i + 1];
                if (i == Student::Student_Number - 1) {
                    Student::Student_Number--;
                    break;
                }
            }
            for (int i = 0; i < U->User_Number; i++) {
                if (U[i].getName() == a) {
                    find1 = i;
                    break;
                }
            }
            for (int i = find1; i < U->User_Number; i++) {
                if (i == U->User_Number - 1) {
                    U->User_Number--;
                    break;
                }
                U[i] = U[i + 1];
            }
            cout<<"删除成功！"<<endl;
        }

    }
    else{
        cout<<"该学生不存在！请重新输入！"<<endl;
    }
}
int Librarian::Librarian_Number=1;

//图书馆管理系统管理员
class Admin: public User,public Log
{
public:
    //图书管理
    static void Book_Add(Book *B);     //添加图书
    void Book_Delete(Book *B);         //删除图书
    void Book_Alter(Book *B);          //修改图书信息
    void Book_Find(Book *B);           //查找图书
    //学生管理
    void Student_Add(User *U, Student *S);    //增加学生
    void Student_Delete(User *U, Student *S); //删除学生
    void Student_Find(Student *S);
    void StudentLent(Student *S,Book *B);     //学生借书
    void StudentReturn(Student *S,Book *B);   //学生还书
    //图书馆管理员管理
    void Librarian_Add(User *U, Librarian *L); //添加图书馆管理员
    void Librarian_Delete(User *U, Librarian *L); //删除图书馆管理员

    Admin(){Is_Librarian=false;Is_Student=false;Is_Admin=true;}
    Admin(string n, string id, string k,User *U)
    {
        U[U->User_Number].Setname(n);
        U[U->User_Number].SetKey(k);
        U[U->User_Number].SetID(id);
        Is_Admin=1;Is_Student=0;Is_Librarian=0;
        U[U->User_Number].SetIdentity(false,false,true);
        U->User_Number++;
        name=n;
        key=k;
    }
};

void Admin::Student_Find(Student *S) {

    string a;
    cout<<"请输入要查询学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    S[find].Book_LR();
}

void Admin::StudentLent(Student *S,Book *B) { //学生
    //查找学生信息
    string a;
    cout<<"请输入学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    //学生借书
    S->Book_Lent(B);
}

void Admin::StudentReturn(Student *S,Book *B) //学生还书
{
    //查找学生信息
    string a;
    cout<<"请输入学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i;
            flag=1;
            break;
        }
    }
    //学生还书
    S->Book_Ruturn(B);
}

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
    //查找图书
    for( int i = 0 ; i < Book::Book_Number;i++)
    {
        if(a==B[i].Getcode()||a==B[i].GetName())
        {
            //若图书存在，flag=1，否则为0；count为图书数量
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
    cout<<Student::Student_Number<<endl;
}

void Admin::Student_Delete(User *U, Student *S) {
    string a;
    cout<<"请输入要删除学生的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    //查找学生
    for(int i=0; i<Student::Student_Number;i++)
    {
        if(S[i].getName()==a)
        {
            find=i; //find定位学生位置
            flag=1; //若找到学生，flag=1，否则为0
            break;
        }
    }
    //学生存在，
    if(flag==1)
    {
        char c;
        //输出学生信息
        cout<<"已找到学生，索引号为："<<setw(10)<<S[find].getName()<<setw(10)<<S[find].GetInstitute()<<setw(10)<<S[find].GetID()<<setw(10)<<endl;
        //确认是否删除
        cout<<"是否删除？（y/n）："<<endl;
        cin>>c;
        //删除操作
        if(c=='y') {
            for (int i = find; i < Student::Student_Number; i++) {
                S[i] = S[i + 1];
                if (i == Student::Student_Number - 1) {
                    Student::Student_Number--;
                    break;
                }
            }
            for (int i = 0; i < U->User_Number; i++) {
                if (U[i].getName() == a) {
                    find1 = i;
                    break;
                }
            }
            for (int i = find1; i < U->User_Number; i++) {
                if (i == U->User_Number - 1) {
                    U->User_Number--;
                    break;
                }
                U[i] = U[i + 1];
            }
            cout<<"删除成功！"<<endl;
        }

    }
    //学生不存在
    else{
        cout<<"该学生不存在！请重新输入！"<<endl;
    }
}

void Admin::Librarian_Add(User *U, Librarian *L) {
    Log a;
    L[Librarian::Librarian_Number].zhuce(U,a,L); //注册图书馆管理员
}

void Admin::Librarian_Delete(User *U, Librarian *L) {
    string a;
    cout<<"请输入要删除管理员的姓名："<<endl;
    cin>>a;
    int flag=0,find=0,find1=0;
    //查找管理员
    for(int i=0; i<Librarian::Librarian_Number;i++)
    {
        if(L[i].getName()==a)
        {
            find=i; //find定位管理员位置
            flag=1; //若找到管理员，flag=1，否则为0
            break;
        }
    }
    //若管理员存在，则
    if(flag==1)
    {
        char c;
        //输出管理员信息
        cout<<"已找到管理员："<<setw(10)<<L[find].getName()<<setw(10)<<L[find].GetInstitute()<<setw(10)<<L[find].GetID()<<setw(10)<<endl;
        //确认是否删除
        cout<<"是否删除？（y/n）："<<endl;
        cin>>c;
        //删除操作
        if(c=='y') {
            for (int i = find; i < Librarian::Librarian_Number; i++) {
                L[i] = L[i + 1];
                if (i == Librarian::Librarian_Number - 1) {
                    Librarian::Librarian_Number--;
                    break;
                }
            }
            for (int i = 0; i < U->User_Number; i++) {
                if (U[i].getName() == a) {
                    find1 = i;
                    break;
                }
            }
            for (int i = find1; i < U->User_Number; i++) {
                if (i == U->User_Number - 1) {
                    U->User_Number--;
                    break;
                }
                U[i] = U[i + 1];
            }
        }

    }
    //若管理员不存在
    else{
        cout<<"该管理员不存在！请重新输入！"<<endl;
    }
}
//主界面
void main_interface()
{
    cout<<"I———————————————图书管理系统—————————————————I"<<endl;
    cout<<"I—————————————①------注册------————————————I"<<endl;
    cout<<"I—————————————②------登陆------————————————I"<<endl;
    cout<<"I—————————————③------退出------————————————I"<<endl;
}
//学生界面
void Student_interface()
{
    cout<<"①-------查找图书"<<endl;
    cout<<"②-------借书"<<endl;
    cout<<"③-------还书"<<endl;
    cout<<"④-------查询借还信息"<<endl;
    cout<<"⑤-------图书展示"<<endl;
    cout<<"任意键-------退出"<<endl;
}
//图书馆管理员界面
void Librarian_interface()
{
    cout<<"①-------增加图书"<<endl;
    cout<<"②-------修改图书"<<endl;
    cout<<"③-------删除图书"<<endl;
    cout<<"④-------查询图书"<<endl;
    cout<<"⑤-------增加学生"<<endl;
    cout<<"⑥-------删除学生"<<endl;
    cout<<"⑦-------查询学生"<<endl;
    cout<<"⑧-------学生借书"<<endl;
    cout<<"⑨-------学生还书"<<endl;
    cout<<"任意键-------退出"<<endl;
}
//系统管理员界面
void Admin_interface()
{
    cout<<"①-------增加图书"<<endl;
    cout<<"②-------修改图书"<<endl;
    cout<<"③-------删除图书"<<endl;
    cout<<"④-------查询图书"<<endl;
    cout<<"⑤-------添加学生"<<endl;
    cout<<"⑥-------删除学生"<<endl;
    cout<<"⑦-------查找学生"<<endl;
    cout<<"⑧-------添加管理员"<<endl;
    cout<<"⑨-------删除管理员"<<endl;
    cout<<"A-------学生借书"<<endl;
    cout<<"B-------学生还书"<<endl;
    cout<<"任意键-------退出"<<endl;
}

Book B[10000]{Book("10000","面向对象编程","吴乃陵","高等教育出版社",2),Book("10001","随机信号处理","罗鹏飞","清华大学出版社",3),Book("10002","数字信号处理","程佩清","清华大学出版社",1)};
User U[100];
Student S[100];
Librarian L[100]{Librarian("A","8","123",U)};
Admin A[100]{Admin("admin","123","123",U)};
Log c;

int main() {
    while(1)
    {
        //主界面
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
                        Librarian_interface();
                        char b;
                        cin>>b;
                        switch(b)
                        {
                            case '1':
                            {
                                L[c.number].Book_Add(B);
                                break;
                            }
                            case '2':
                            {
                                L[c.number].Book_Alter(B);
                                break;
                            }
                            case '3':
                            {
                                L[c.number].Book_Delete(B);
                                break;
                            }
                            case '4':
                            {
                                L[c.number].Book_Find(B);
                                break;
                            }
                            case '5':
                            {
                                L[c.number].Student_Add(U,S);
                                break;
                            }
                            case '6':
                            {
                                L[c.number].Student_Delete(U,S);
                                break;
                            }
                            case '7':
                            {
                                L[c.number].Student_Find(S);
                                break;
                            }
                            case '8':
                            {
                                L[c.number].StudentLent(S,B);
                                break;
                            }
                            case '9':
                                {
                                    L[c.number].StudentReturn(S,B);
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
                        char b;cin>>b;

                        switch(b)
                        {
                            case '1':
                            {
                                S[c.number].Book_Find(B);
                                break;
                            }
                            case '2':
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
                            case '3':
                            {
                                S[c.number].Book_Ruturn(B);
                                break;
                            }
                            case '4':
                            {
                                S[c.number].Book_LR();
                                break;
                            }
                            case '5':
                            {
                                S[c.number].Book_Show(B);
                                break;
                            }
                            default:
                                n=0;
                        }

                    }
                }
                else if(c.u.Judge()==5)
                {
                    int n=1;
                    while(n)
                    {
                        Admin_interface();
                        char b;
                        cin>>b;
                        switch(b)
                        {
                            case '1':
                            {
                                A[c.number].Book_Add(B);
                                break;
                            }
                            case '2':
                            {
                                A[c.number].Book_Alter(B);
                                break;
                            }
                            case '3':
                            {
                                A[c.number].Book_Delete(B);
                                break;
                            }
                            case '4':
                            {
                                A[c.number].Book_Find(B);
                                break;
                            }
                            case '5':
                            {
                                A[c.number].Student_Add(U,S);
                                break;
                            }
                            case '6':
                            {
                                A[c.number].Student_Delete(U,S);
                                break;
                            }
                            case '7':
                            {
                                A[c.number].Librarian_Add(U,L);
                            }
                            case '8':
                            {
                                A[c.number].Librarian_Delete(U,L);
                            }
                            case '9':
                            {
                                A[c.number].Student_Find(S);
                                break;
                            }
                            case 'A':
                            {
                                A[c.number].StudentLent(S,B);
                                break;
                            }
                            case 'B':
                            {
                                A[c.number].StudentReturn(S,B);
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
                //return 0;
                break;
            }
            default:
                break;

        }
        cin.get();//吸收回车符
        //cout<<"按回车键返回主界面\n";
        //cin.get();
    }
    return 0;
}

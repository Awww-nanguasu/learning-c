#include<iostream>
using namespace std;
class Student{
    private:
        int ID;
        string Name;
        string Sex;
    public:
        Student(int a,string name,string sex);
        ~Student();
        void ChangeID(int a);
        void Display();
};
Student::~Student(){
    cout<<"HelloWorld"<<endl;
}
Student::Student(int Id,string name,string sex){
    ID=Id;
    Name=name;
    Sex=sex;
}
void Student::ChangeID(int a){
    ID=a;
}
void Student::Display(){
    cout<<"ѧ��:"<<ID<<endl;
    cout<<"����:"<<Name<<endl;
    cout<<"�Ա�:"<<Sex<<endl;
}
int main(){
    Student stu1(100,"����","��");
    stu1.ChangeID(200);
    stu1.Display();
}
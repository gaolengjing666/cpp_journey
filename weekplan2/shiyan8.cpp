#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
string id;
string name;

public:
person(string a,string b):id(a),name(b){

}
};
class stud
{
protected:
    string addr;
    string tel;
public:
    stud(string a,string b):addr(a),tel(b){

    }
    void print(){
        cout<<addr<<","<<tel<<endl;
    }
};

class teacher:public person
{
private:
    string degree;
    string dep;
public:
    teacher(string a,string b,string c,string d):person(a,b),degree(c),dep(d){

    }
    void print(){
        cout<<name<<","<<id<<","<<degree<<","<<dep<<endl;
    }
};

class student:public person
{
protected:
    int old;
    string sno;
public:
    student(string a,string b,int c,string d):person(a,b),old(c),sno(d){

    }
    void print(){
        cout<<name<<","<<id<<","<<old<<","<<sno<<endl;
    }
};

class score: public stud,public student
{
private:
    float math;
    float eng;
public:
    score(string a,string b,int c,string d,string e,string f,float g,float h):student(a,b,c,d),stud(e,f),math(g),eng(h){

    }
    void print(){
        student::print();
        stud::print();
        cout<<math<<","<<eng<<endl;
    }
};

int main(){
    score c1("jack","100085",16,"202577130999","郑州","110",90,90);
    teacher t1("dawn","100086","doctor","math");
    c1.print();
    t1.print();
}
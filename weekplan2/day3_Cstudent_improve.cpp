#include "day3_Cstudent_improve.h"
#include <iostream>
#include <memory>
#include <string>

vector<string> Cstudent::subject;
vector<Cstudent*> Cstudent::classmates;
int Cstudent::count=0;

void Cstudent::Setsubjects(){
    cout<<"请按顺序输入学科名称（输入-1时停止）"<<endl;
    while(true){
        string subjects;
        string back="-1";
        cin>>subjects;
        cin.ignore();//防止空格隔开
        if(!(subjects.compare(back))){
            break;

        }
        subject.push_back(subjects);
        count++;
    }

}

Cstudent::Cstudent(string name1,long long number1):name(name1),number(number1){
    classmates.push_back(this);//每个对象初始化后均加入列表

}

void Cstudent::Setscores(){
    scores.resize(count);
    cout<<"请按学科顺序输入学生成绩"<<endl;
    for(int i=0;i<count;i++){
        cout<<subject[i]<<"的成绩为:"<<endl;
        cin>>scores[i];
    }
    cout<<"输入完毕"<<endl;
} 



void Cstudent::average(){
    int sum=0;
    for(int i=0;i<count;i++){  //循环输入时可用 getline(cin,s2,','),输入给s2，逗号为换行符
       sum+=scores[i];          //cin不读入空格，此时可用getline，或cin.ignore()清空输入缓冲区
    }
    
    aver = static_cast<double>(sum) / count;//类型转换，避免整数除法导致的精度丢失
    cout << "平均成绩为" << aver << endl;
}

void Cstudent::Print(){
    cout<<"姓名："<<name<<",学号："<<number<<endl;
    cout<<"成绩："<<endl;
    for(int i=0;i<count;i++){
        cout<<subject[i]<<":"<<scores[i]<<","<<endl;
    }
    average(); 
}

void Cstudent::Isfall(){
    int count=0;
    for(Cstudent* s:classmates){//静态函数只能访问静态成员，所以只能通过同学列表访问每个对象 
        if(s->aver<60){
            cout<<"不及格学生："<<s->name<<endl;
            count++;

        }
    }
    cout<<"不及格总人数为:"<<count<<endl;
}

int main(){
    //test
    Cstudent::Setsubjects();
    Cstudent s1("张三",20230001);
    s1.Setscores();
    s1.Print();
    Cstudent::Isfall();
}
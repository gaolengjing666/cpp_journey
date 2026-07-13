#include "Cstudent.h"
#include <iostream>
#include <memory>
#include <string>

size_t Cstudent::length=0;
unique_ptr<string[]> Cstudent::subject=nullptr;
vector<Cstudent*> Cstudent::classmates;

void Cstudent::Setsubjects(){
    cout<<"请输入总共有多少学科:"<<endl;
    cin>>length;
    subject=make_unique<string[]>(length);
    cout<<"请按顺序输入学科名称"<<endl;
    for(int i=0;i<length;i++){
        cout<<"第"<<i+1<<"门:";
        cin>>subject[i];
    }
}

Cstudent::Cstudent(string name1,long long number1):name(name1),number(number1){
    classmates.push_back(this);//每个对象初始化后均加入列表

}

void Cstudent::Setscores(){
    scores=make_unique<int[]>(length);
    cout<<"请按学科顺序输入学生成绩"<<endl;
    for(int i=0;i<length;i++){
        cout<<"第"<<i+1<<"科成绩为:"<<endl;
        cin>>scores[i];
    }
    cout<<"输入完毕"<<endl;
} 



void Cstudent::average(){
    int sum=0;
    for(int i=0;i<length;i++){  //循环输入时可用 getline(cin,s2,','),输入给s2，逗号为换行符
       sum+=scores[i];          //cin不读入空格，此时可用getline，或cin.ignore()清空输入缓冲区
    }
    
    aver = static_cast<double>(sum) / length;//类型转换，避免整数除法导致的精度丢失
    cout << "平均成绩为" << aver << endl;
}

void Cstudent::Print(){
    cout<<"姓名："<<name<<",学号："<<number<<endl;
    cout<<"成绩：";
    for(int i=0;i<length;i++){
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
//动态数组学习
//智能指针学习
//静态变量实际应用
//
//




#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Cstudent{
private:
   string name;
   long long number;
   unique_ptr<int[]> scores;
   double aver;
   static vector<Cstudent*> classmates;//同学列表，存储指向同学对象的指针
   void average();

   static size_t length;
   static unique_ptr<string[]> subject;//用unique智能指针，禁止拷贝，自动释放内存   
public:
   static void Setsubjects();
   Cstudent(string name1,long long number1);
   void Setscores();
   
   void Print();
   static void Isfall();
};

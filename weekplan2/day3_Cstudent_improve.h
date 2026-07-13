#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Cstudent{
private:
   string name;
   long long number;
   //unique_ptr<int[]> scores;
   vector<int> scores;
   double aver;
   static vector<Cstudent*> classmates;//同学列表，存储指向同学对象的指针
   void average();
   static int count;//记录学科数目
   //static unique_ptr<string[]> subject;
   static vector<string> subject;//用vector实现动态数组  
public:
   static void Setsubjects();
   Cstudent(string name1,long long number1);
   void Setscores();
   
   void Print();
   static void Isfall();
};

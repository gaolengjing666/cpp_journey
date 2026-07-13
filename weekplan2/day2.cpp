#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
   vector<int> scores; //空数组，用push-back填入数组
   int sum=0;
   double average;
   cout<<"请输入学生成绩（输入-1时停止）"<<endl;
   while(true){
       int score;
       cin>>score;
       if(score==-1){
           break;
       }
       scores.push_back(score);

   }
   cout<<"共录入"<<scores.size()<<"个成绩:"<<endl;
   for(auto it=scores.begin()/*   vector<int>::iterator it   */;it!=scores.end();++it){//迭代器遍历，传入为指针
      cout<<*it<<' ';
      
   }
    
   cout<<endl;
   for(int& x:scores){//范围for，&引用该值,可改值
    x+=5;
    if(x>100){
        x=100;
    }
    sum+=x;
   }

   cout<<"加分后成绩为"<<endl;
   for(int x:scores){
    cout<<x<<endl;
   }

   
   average=static_cast<double>(sum)/scores.size();
   cout<<"\n平均数为"<<average;

}
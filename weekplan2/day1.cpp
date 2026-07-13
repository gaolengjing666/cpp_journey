#include <iostream>
#include <vector>
using namespace std;
int main(){
   vector<int> scores; //空数组，用push-back填入数组
   int sum=0;
   double average;
   /*
   此方法越界访问，scores[0]不存在
   for(size_t n=0;scores[n]!=-1;n++){

   }*/
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
   for(int i=0;i<scores.size();i++){
      cout<<scores[i]<<' ';
      sum+=scores[i];
   }
   
   average=static_cast<double>(sum)/scores.size();
   cout<<"\n平均数为"<<average;

}
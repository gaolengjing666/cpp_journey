//双向链表使用 
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main(){
    list<string> name={"Alice","Bob","Charlie"};
    for(auto x:name){
        cout<<x<<",";
    }
    cout<<endl;
    list<string>::iterator it;// 指针
    for(it=name.begin();it!=name.end();++it){
        
        if(*it=="Bob"){
            it++;
            
            name.insert(it,"David");
            break;
        }
    }
    for(auto x:name){
        cout<<x<<",";
    }
    cout<<endl;
    for(it=name.begin();it!=name.end();++it){
        if(*it=="Charlie"){
            name.erase(it);//迭代器已失效，无法自增，必须break，否则后续无法编译
            break;
        }
    }
    for(auto x:name){
        cout<<x<<",";
    }
    cout<<endl;
    name.push_front("Eva");
    for(auto x:name){
        cout<<x<<",";
    }
}
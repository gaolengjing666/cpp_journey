#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

//包含动态指针的知识，动态指针使用前必先分配内存
class SecureByteArray
{
private:
unique_ptr<char[]> data;
size_t length;
public:
SecureByteArray(const char* str);//传指针就用const(无需修改时)
SecureByteArray(const SecureByteArray &other);

/*拷贝运算符重载*/
SecureByteArray& operator=(const SecureByteArray& p);//用于已赋值对象的再赋值
SecureByteArray(SecureByteArray &&other);
/*移动运算符重载*/
SecureByteArray& operator=(SecureByteArray&& p);//用于已赋值对象的再赋值
~SecureByteArray();//对象销毁时调用

};

SecureByteArray::SecureByteArray(const char* str){
    length=strlen(str);
    data=make_unique<char[]>(length+1);//分配内存
    strcpy(data.get(),str);
}


/*SecureByteArray::SecureByteArray(const SecureByteArray &other){
    length=other.length;

    data=new char[length+1];//给data分配新空间，避免double free

    strcpy(data,other.data);


}*/


//拷贝运算符重载实现

/*SecureByteArray& SecureByteArray::operator=(const SecureByteArray& p){
    if(this==&p){
        return *this;//return后自动跳出函数，因为已有返回值
    }
    delete[]data;
    length=p.length;
    data=make_unique<char[]>(length+1);
    strcpy(data,p.data);
    return *this;
}*/


//禁用拷贝构造函数，与拷贝运算符重载(智能指针unique_ptr)
SecureByteArray::SecureByteArray(const SecureByteArray &other)=delete;
SecureByteArray& SecureByteArray::operator=(const SecureByteArray& other)=delete;


SecureByteArray::SecureByteArray(SecureByteArray &&other){
    //unique支持被移动
    data=move(other.data);//不能出现指针同指，所以用move

    length=other.length;

   // other.data=nullptr;           //使原对象data指针指向空指针，避免double free，本质上是指针的转移
   //不在需要，指针自动被unique置空
    other.length=0;

}



SecureByteArray& SecureByteArray::operator=(SecureByteArray&& p){
    if(this==&p){
        return *this;
    }
    //delete[] data;
    data=move(p.data);
    length=p.length;
   // p.data=nullptr;
    p.length=0;
    return *this;

}


//析构函数
/*SecureByteArray::~SecureByteArray(){
    
    delete[] data;      //释放内存
    cout<<"Destructor called for:"<<(data?data:"empty")<<endl;
}  */





int main(){
   std::cout << "进入 main" << std::endl;

{
std::cout << "进入内层作用域" << std::endl;
SecureByteArray tmp("temporary");
std::cout << "即将离开内层作用域" << std::endl;
} // <- 这里 tmp 析构函数应该被调用

std::cout << "离开内层作用域后" << std::endl;
return 0;
}

//执行析构函数，清除对象


#include <iostream>
using namespace std;

// 自定义异常类
class CException
{
public:
    // 显示异常原因
    void Reason() const
    {
        cout << "发生异常：这是一个自定义异常" << endl;
    }
};


void fn1()
{
    cout << "进入 fn1() 函数..." << endl;
    
    // 创建异常对象并抛出
    CException e;
    throw e;

}

int main()
{
    cout << "程序开始..." << endl;
    cout << "即将调用 fn1()..." << endl;

    try
    {
        // 尝试调用可能抛出异常的函数
        fn1();
        cout << "fn1() 正常返回（如果异常被抛出，这行不会执行）" << endl;
    }
    catch (CException& e)
    {
        // 捕获 CException 类型的异常
        cout << "捕获到异常！" << endl;
        e.Reason();  // 调用成员函数显示异常信息
    }
    catch (...)
    {
        // 捕获所有其他类型的异常（可选）
        cout << "捕获到未知异常！" << endl;
    }

    cout << "程序正常结束..." << endl;
    return 0;
}
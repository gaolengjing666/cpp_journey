#include <iostream>
#include <string>
using namespace std;

// 自定义异常类：范围错误
class RangeError
{
private:
    string message;  // 存储错误信息
public:
    // 构造函数，接收错误描述
    RangeError(const string& msg) : message(msg) {}
    
    // 获取错误信息
    string getMessage() const
    {
        return message;
    }
};

// 函数：检查数字是否在 [min, max] 范围内
void checkRange(int value, int min, int max)
{
    if (value < min || value > max)
    {
        // 超出范围，抛出异常
        throw RangeError("输入的数字 " + to_string(value) + " 不在 [" + to_string(min) + ", " + to_string(max) + "] 范围内！");
    }
    else
    {
        cout << "输入合法：" << value << " 在范围内" << endl;
    }
}

int main()
{
    int num;
    int minVal = 1;
    int maxVal = 100;

    cout << "请输入一个数字（范围 " << minVal << " ~ " << maxVal << "）：";
    cin >> num;

    try
    {
        // 尝试检查数字
        checkRange(num, minVal, maxVal);
    }
    catch (RangeError& e)
    {
        // 捕获并处理异常
        cout << "捕获异常：" << e.getMessage() << endl;
    }

    cout << "程序继续执行..." << endl;
    return 0;
}
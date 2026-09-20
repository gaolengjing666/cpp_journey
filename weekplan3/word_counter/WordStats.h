//设计文章单词计数器，含总单词和对应字母单词
//思路：加载文件函数一键查询，其余函数输出



#include <iostream>
#include <string>
class WordStats
{
public:
    
    void loadFile(const std::string& path);
    std::size_t totalWords();//为什么用sizet
    std::size_t countByInitial(char c);
private:
    std::size_t total=0;
    std::size_t counts[26]={0};//存储各首字母单词数
    static bool isAlpha(char c);//判断英文字母，排除标点
    static char ToLower(char c);//转小写
};
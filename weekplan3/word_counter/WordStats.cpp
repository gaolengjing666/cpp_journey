#include "WordStats.h"
#include <fstream>


bool WordStats::isAlpha(char c){
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

char WordStats::ToLower(char c){
    if(c>='A'&&c<='Z'){
        return c-'A'+'a';
    }
    return c;
}

void WordStats::loadFile(const std::string& path){
    std::ifstream n(path);
    if(!n){//隐式转换，类里定义了bool的隐式转换（比如浮点转整型）
        std::cout<<"文件打开失败"<<std::endl;
        return;
    }
    std::string word;
    while(n>>word){//遇到空格时判断为输入完毕，进入循环体(不计入空格)
        std::size_t begin=0;
        while(begin<word.size()&&!isAlpha(word[begin])){//排除单词前标点
            begin++;
        }
        std::size_t end=word.size()-1;
        while(end>=begin&&!isAlpha(word[end])){
            end--;
        }
        if(end>=begin){
            total++;
            word[begin]=ToLower(word[begin]);
            counts[word[begin]-'a']++;//自动转换
        }
    }
}
//需除去标点符号和空白
std::size_t WordStats::countByInitial(char c){
    return counts[c-'a'];
}

std::size_t WordStats::totalWords(){
    return total;
}
#ifndef PARSELINE_H
#define PARSELINE_H
#include <iostream>
#include <string>
inline/*避免多个文件编译该函数是报错（多重定义）*/ void parseline(const std::string& line,std::string& eng,std::string& chn){
    size_t pos=line.find(" ");
    eng=line.substr(0,pos);
    chn=line.substr(pos+1,line.length());
} 
#endif
#include "word.h"
#include <fstream>
#include <vector>
int main(){

    std::ifstream infile;
    infile.open("word.txt");
    std::string en,cn;
    while(infile>>en>>cn){
        word w(en,cn);
        w.getter();
        std::cout<<std::endl;
    }
    infile.close();
}
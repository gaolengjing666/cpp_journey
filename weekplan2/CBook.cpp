#include "CBook.h"
#include <iterator>

std::list<std::string> CBook::inventory;
std::list<CBook> CBook::book;
CBook::CBook(std::string bookname,std::string writorname,std::string ISBN1):name(bookname),writor(writorname),ISBN(ISBN1),isStay(true){
    inventory.push_back(ISBN);
    book.push_back(*this);
}




void CBook::print() const{
    std::cout<<isStay<<std::endl;
}

std::string CBook::getISBN() const{
    return ISBN;
}

bool findbook(const std::string &Isbn){
    for(auto it=CBook::book.begin();it!=CBook::book.end();++it){
        if((*it).ISBN==Isbn){
            return (*it).isStay; 
        }
    }
    return false;
}
void CBook::borrowBook(const std::string &Isbn){
    auto itt=book.begin();
    for(;itt!=book.end();itt++){
        if(itt->ISBN==Isbn){
            if(itt->isStay){
                (*itt).isStay=false;
                return;
            }else {
                std::cout<<"此书不在馆中"<<std::endl;
                return;
            }
            
            
            
        }
    }
    std::cout<<"此书不在馆中"<<std::endl;
}

void CBook::returnBook(){
    if(isStay){
        std::cout<<"此书已存在馆中"<<std::endl;
    } else {
        isStay=true;
        
    }
}


#include <iostream>
#include <list>

class CBook{
private:
    std::string name;
    std::string writor;
    std::string ISBN;
    static std::list<std::string> inventory;
    static std::list<CBook> book;
    bool isStay;
public:
    CBook(std::string bookname,std::string writorname,std::string ISBN1);
    
    void print() const;
    std::string getISBN() const;
    
   friend bool findbook(const std::string &Isbn);
    static void borrowBook(const std::string &Isbn);
    void returnBook();
};


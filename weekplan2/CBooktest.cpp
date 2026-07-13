#include "CBook.cpp"
using namespace std;

int main(){
    CBook book1("dickor","Mr.dick","20250509");
    CBook::borrowBook(book1.getISBN());
    CBook::borrowBook(book1.getISBN());
    book1.returnBook();
}
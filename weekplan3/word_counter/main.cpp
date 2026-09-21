#include "WordStats.h"
using namespace std;
int main(){
    WordStats book;
    book.loadFile("D:\\edgedown\\pg7256.txt");
    cout<<book.countByInitial('a')<<endl;
    cout<<book.totalWords();
    book.WordsFrequency();
}
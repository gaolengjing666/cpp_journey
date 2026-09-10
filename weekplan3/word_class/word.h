#include <iostream>
#include <string>

class word
{
private:
    std::string eng;
    std::string chn;
public:
    word(std::string en="",std::string cn=nullptr);
    void getter();
    ~word();
};
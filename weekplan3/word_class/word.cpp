#include "word.h"

word::word(std::string en,std::string cn):eng(en),chn(cn){

}

void word::getter(){
    std::cout<<eng<<","<<chn<<std::endl;
}
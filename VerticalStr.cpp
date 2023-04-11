#include "VerticalStr.h"

list VerticalStr::getList(){
    return this->lst;
}

VerticalStr* VerticalStr::getVerticalStr(){
    return this->vStr;
}

void VerticalStr::setList(const list& l){
    this->lst = l;
}

void VerticalStr::setVerticalStr(VerticalStr* vs){
    this->vStr = vs;
}
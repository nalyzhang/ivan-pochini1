#ifndef UNTITLED_VERTICALSTR_H
#define UNTITLED_VERTICALSTR_H

#include "list.h"

class VerticalStr {
protected:
    list lst;
    VerticalStr* vStr;
public:
    explicit VerticalStr(list l){
        this->vStr = nullptr;
        for (StrL* node = l.getHead(); node != nullptr; node = node->getNext()) this->lst.push_back(node->getData(), node->getSize());
    }

    ~VerticalStr() {
        free(vStr);
    }

    list getList();

    VerticalStr* getVerticalStr();

    void setList(const list& l);

    void setVerticalStr(VerticalStr* vs);
};


#endif

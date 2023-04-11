#ifndef UNTITLED_VERTICALLIST_H
#define UNTITLED_VERTICALLIST_H

#include "VerticalStr.h"

class VerticalList {
private:
    VerticalStr *head, *tail;
public:
    VerticalList(){
        this->head = nullptr;
        this->tail = nullptr;
        std::cout << "Вертикальный список создан\n";
    }

    ~VerticalList(){
        while (this->head != nullptr) pop_front();
        if((this->head == nullptr)&&(this->tail == nullptr)) std::cout << "Вертикальный список удален\n";
    }

    void pop_front();

    VerticalStr *getHead();

    void setHead(VerticalStr *h);

    VerticalStr *getTail();

    void setTail(VerticalStr *t);

    void push_back(const list& l);

    VerticalStr *getAt(int k);

    void insert(int k, const list& l);

    void earse(int k);
};


#endif

#ifndef L2_3_LIST_H
#define L2_3_LIST_H
#include "StrL.h"
#include <iostream>

class list {
private:
    StrL* head;
    StrL* tail;

public:
    list(){
        this->head = this->tail = nullptr;
        std::cout << "Список создан\n";
    }

    ~list(){
        while (this->head != nullptr) pop_front();
        if((this->head == nullptr)&&(this->tail == nullptr)) std::cout << "Список удален\n";
    }

    void pop_front();

    StrL *getHead();

    void setHead(StrL *h);

    StrL *getTail();

    void setTail(StrL *t);

    void push_back(char *data, int s);

    StrL *getAt(int k);

    void insert(int k, char *text, int s);

    void earse(int k);

    StrL* read(std::ifstream in);
};

#endif

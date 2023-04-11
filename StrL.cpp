#include "StrL.h"

int StrL::getSize() {
    return this->size;
}

void StrL::setSize(int s) {
    this->size = s;
}

char *StrL::getData(){
    return this->data;
}

void StrL::setData(char *d) {
    this->data = d;
}

StrL *StrL::getNext() {
    return this->next;
}

void StrL::setNext(StrL *n) {
    this->next = n;
}
#include "VerticalList.h"
#include <cstdlib>

void VerticalList::setTail(VerticalStr *t) {
    this->tail = t;
}

VerticalStr *VerticalList::getTail(){
    return this->tail;
}

VerticalStr *VerticalList::getHead() {
    return this->head;
}

void VerticalList::setHead(VerticalStr *h) {
    this->head = h;
}

void VerticalList::pop_front() { //удаление с начала
    if (this->head == nullptr) return;
    if (this->head == this->tail) {
        free(this->tail);
        this->head = this->tail = nullptr;
        return;
    }
    free(head);

}

void VerticalList::push_back(StrL* data) { //добавление в конец
    auto* node = new VerticalStr(data);
    if (this->getHead() == nullptr) this->setHead(node);
    if (this->getTail() != nullptr) this->getTail()->setVerticalStr(node);
    this->setTail(node);
    delete node;
}

VerticalStr* VerticalList::getAt(int k) { //доступ к элементу
    if (k < 0) return nullptr;
    VerticalStr* node = this->getHead();
    int n = 0;
    while (node && n != k && node->getVerticalStr()) {
        node = node->getVerticalStr();
        n++;
    }
    return (n == k) ? node : nullptr;
}

//вствка элемента
void VerticalList::insert(int k, StrL* l){ //индекс k - индекс элемента, после которого нужно вставить объект
    VerticalStr* left = getAt(k);
    if (left == nullptr) return;
    VerticalStr* right = left->getVerticalStr();
    auto* node = new VerticalStr(l);
    left->setVerticalStr(node);
    node->setVerticalStr(right);
    if (right == nullptr) this->setTail(node);
}

//удаление промежуточного элемента
void VerticalList::earse(int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front();
        return;
    }
    VerticalStr* left = this->getAt(k-1);
    VerticalStr* node = left->getVerticalStr();
    if (node == nullptr) return;
    VerticalStr* right = node->getVerticalStr();
    left->setVerticalStr(right);
    if (node == this->getTail()) this->setTail(left);
    delete node;
}

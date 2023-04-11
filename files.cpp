#include "files.h"
#include <iostream>

void files::printList(StrL* lst) {
    if (lst == nullptr) return;
    for (StrL *node = lst; node != nullptr; node = node->getNext()) {
        for (int j = 0; j < node->getSize(); j++)
            this->out << node->getData()[j];
        this->out << "->";
        if (node->getNext() == nullptr) this->out << "NULL";
    }
}

VerticalList files::read() {
    VerticalList verticalList;
    if (this->in.is_open()) {
        while (!this->in.eof()) {
            list l;
            if (this->in.is_open() == 1) {
                char w;
                this->in.unsetf(std::ios::skipws);
                while (true) {
                    int i = 0;
                    char *text = new char[10];
                    while (i < 10) {
                        this->in >> w;
                        if (this->in.eof() || (w == '\n')) break;
                        text[i++] = w;
                    }
                    l.push_back(text, i);
                    delete[] text;
                    if (this->in.eof() || w == '\n') break;
                }
                for (StrL *node = l.getHead(); node != nullptr; node = node->getNext()) {
                    for (int j = 0; j < node->getSize(); j++)
                        std::cout << node->getData()[j];
                    std::cout << "->";
                    if (node->getNext() == nullptr) std::cout << "NULL\n";
                }
                verticalList.push_back(l.getHead());
                while (l.getHead() != nullptr) l.pop_front();
                if (this->in.eof()) break;
            }
        }
    } else verticalList.setHead(nullptr);
    return verticalList;
}

void files::result() {
    VerticalList verticalList = this->read();
    for (VerticalStr *node = verticalList.getHead(); node != nullptr; node = node->getVerticalStr()) {
        this->printList(node->getList().getHead());
        this->out << "\n->";
        if (node->getVerticalStr() == nullptr) this->out << "NULL";
    }
}
#ifndef LAB2_2_FILES_H
#define LAB2_2_FILES_H
#include <fstream>
#include "StrL.h"
#include "list.h"
#include "VerticalList.h"

class files {

public:

    std::ifstream in;
    std::ofstream out;

    explicit files(const char ouT[] = "out.txt", const char w[] = "in.txt") {
        this->out.open(ouT);
        this->in.open(w);
    }

    ~files() {
        this->out.close();
        this->in.close();
    }

    void result();

    VerticalList read();

    void printList(StrL* lst);
};

#endif

#ifndef L2_3_STRL_H
#define L2_3_STRL_H


class StrL {
private:
    char* data;
    int size{};
    StrL* next;

public:
    StrL(char* text, int s) {
        this->data = new char[s];
        for (int i = 0; i < s; i++) this->data[i] = text[i];
        this->setSize(s);
        this->next = nullptr;
    }

    ~StrL() {
        delete this->data;
    }

    int getSize();

    void setSize(int s);

    char *getData();

    void setData(char *d);

    StrL *getNext();

    void setNext(StrL *n);
};

#endif

#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
    void setBrand(const char*);
    void setPrice(float);
    void print();

private:
    char _brand[20];
    float _price;
};
#endif

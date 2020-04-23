#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void example()
{
    XMLDocument doc;
    doc.LoadFile("test1.xml");
    const char* content=doc.FirstChildElement("Hello")->GetText();  //获取第一个值为"Hello"的子节点
    printf("Hello,%s\n",content);
}

int main()
{
    example();

    return 0;
}

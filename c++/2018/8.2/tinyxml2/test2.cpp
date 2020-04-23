#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void example()
{
    XMLDocument doc;
    doc.LoadFile("test2.xml");

    XMLElement *scene=doc.RootElement();    //获取根节点
    XMLElement *surface=scene->FirstChildElement("node");   //获取scene节点的第一个名为node的子节点

    //遍历所有node节点
    while(surface)
    {
        XMLElement *surfaceChild=surface->FirstChildElement();  //获取node节点的第一个子节点
        const XMLAttribute *attributeOfSurface=surface->FirstAttribute();   //获取node节点的第一个属性
        cout<<attributeOfSurface->Name()<<":"<<attributeOfSurface->Value()<<endl;   //打印node节点属性

        const char *content;
        //遍历node节点的子节点
        while(surfaceChild)
        {
            content=surfaceChild->GetText();    //获取node子节点的内容
            cout<<content<<endl;
            surfaceChild=surfaceChild->NextSiblingElement();
        }

        surface=surface->NextSiblingElement();
    }
}

int main()
{
    example();

    return 0;
}

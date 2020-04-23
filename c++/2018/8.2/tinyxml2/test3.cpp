#include <string>
#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class User
{
public:
    User()
    :gender(0)
    {
        cout<<"User()"<<endl;
    }

    User(const string &userName,const string &password,int gender,const string &mobile,const string &email)
    {
        cout<<"User(stirng,string,int,string,string)"<<endl;
        this->userName=userName;
        this->password=password;
        this->gender=gender;
        this->mobile=mobile;
        this->email=email;
    }

    string userName;
    string password;
    int gender;
    string mobile;
    string email;
};

int createXML(const char *xmlPath)
{
    XMLDocument doc;

    XMLDeclaration *declaration=doc.NewDeclaration();   //建立声明
    doc.InsertFirstChild(declaration);  //添加声明

    XMLElement *root=doc.NewElement("DBUSER");  //建立根节点
    doc.InsertEndChild(root);   //添加根节点

    return doc.SaveFile(xmlPath);
}

int insertXMLNode(const char *xmlPath,const User &user)
{
    XMLDocument doc;
    int res=doc.LoadFile(xmlPath);  //加载xml文件
    if(res!=0)
    {
        cout<<"load xml file failed"<<endl;
        return res;
    }

    XMLElement *root=doc.RootElement(); //获取根节点

    XMLElement *userNode=doc.NewElement("User");    //新建子节点User
    userNode->SetAttribute("Name",user.userName.c_str());
    userNode->SetAttribute("Password",user.password.c_str());
    root->InsertEndChild(userNode); //添加子节点

    XMLElement *gender=doc.NewElement("Gender");    //新建子节点Gender
    XMLText *genderText=doc.NewText(to_string(user.gender).c_str());  //新建Gender节点的内容
    gender->InsertEndChild(genderText);
    userNode->InsertEndChild(gender);

    XMLElement *mobile=doc.NewElement("Mobile");
    XMLText *mobileText=doc.NewText(user.mobile.c_str());
    mobile->InsertEndChild(mobileText);
    userNode->InsertEndChild(mobile);

    XMLElement *email=doc.NewElement("Email");
    email->InsertEndChild(doc.NewText(user.email.c_str()));
    userNode->InsertEndChild(email);

    return doc.SaveFile(xmlPath);
}

//根据用户名获取用户节点
XMLElement *queryUserNodeByName(XMLElement *root,const string &userName)
{
    XMLElement *userNode=root->FirstChildElement("User");
    while(userNode != NULL)
    {
        if(userNode->Attribute("Name")==userName)
        {
            break;
        }
        userNode=userNode->NextSiblingElement();
    }

    return userNode;
}

//根据用户名获取用户信息
User *queryUserByName(const char *xmlPath,const string &userName)
{
    XMLDocument doc;
    if(doc.LoadFile(xmlPath)!=0)
    {
        cout<<"load xml file failed"<<endl;
        return NULL;
    }

    XMLElement *root=doc.RootElement();
    XMLElement *userNode=queryUserNodeByName(root,userName);

    if(userNode!=NULL)
    {
        User *user=new User();
        user->userName=userName;
        user->password=userNode->Attribute("Password");

        XMLElement *genderNode=userNode->FirstChildElement("Gender");
        user->gender=atoi(genderNode->GetText());

        XMLElement *mobileNode=userNode->FirstChildElement("Mobile");
        user->mobile=mobileNode->GetText();

        XMLElement *emailNode=userNode->FirstChildElement("Email");
        user->email=emailNode->GetText();

        return user;
    }

    return NULL;
}

//修改指定节点的内容
bool updateUser(const char *xmlPath,User *user)
{
    XMLDocument doc;
    if(doc.LoadFile(xmlPath)!=0)
    {
        cout<<"load xml file failed"<<endl;
        return false;
    }

    XMLElement *root=doc.RootElement();
    XMLElement *userNode=queryUserNodeByName(root,user->userName);

    if(userNode!=NULL)
    {
        if(user->password!=userNode->Attribute("Password"))
        {
            userNode->SetAttribute("Password",user->password.c_str());
        }

        XMLElement *genderNode=userNode->FirstChildElement("Gender");
        if(user->gender!=atoi(genderNode->GetText()))
        {
            genderNode->SetText(to_string(user->gender).c_str());
        }

        XMLElement *mobileNode=userNode->FirstChildElement("Mobile");
        if(user->mobile!=mobileNode->GetText())
        {
            mobileNode->SetText(user->mobile.c_str());
        }

        XMLElement *emailNode=userNode->FirstChildElement("Email");
        if(user->email!=emailNode->GetText())
        {
            emailNode->SetText(user->email.c_str());
        }

        if(doc.SaveFile(xmlPath)==0)
        {
            return true;
        }
    }

    return false;
}

bool deleteUserByName(const char *xmlPath,const string &userName)
{
    XMLDocument doc;
    if(doc.LoadFile(xmlPath)!=0)
    {
        cout<<"load xml file failed"<<endl;
        return false;
    }

    XMLElement *root=doc.RootElement();
    XMLElement *userNode=queryUserNodeByName(root,userName);

    if(userNode!=NULL)
    {
        userNode->DeleteAttribute("Password");

        XMLElement *emailNode=userNode->FirstChildElement("Email");
        userNode->DeleteChild(emailNode);

        if(doc.SaveFile(xmlPath)==0)
        {
            return true;
        }
    }

    return false;
}

void print(const char *xmlPath)
{
    XMLDocument doc;
    if(doc.LoadFile(xmlPath)!=0)
    {
        cout<<"load xml file failed"<<endl;
        return;
    }

    doc.Print();
}

int main()
{
    createXML("test3.xml");

    User user("wang","123",1,"159","244");
    insertXMLNode("test3.xml",user);

#if 0
    User *user1;
    user1=queryUserByName("test3.xml","wang");
    cout<<user1->userName<<endl;
    cout<<user1->password<<endl;
    cout<<user1->gender<<endl;
    cout<<user1->mobile<<endl;
    cout<<user1->email<<endl;
#endif

    User user2("wang","234",0,"180","899");
    if(updateUser("test3.xml",&user2))
    {
        cout<<"update successfully"<<endl;
    }
    else
    {
        cout<<"update failed"<<endl;
    }

    if(deleteUserByName("test3.xml","wang"))
    {
        cout<<"delete successfully"<<endl;
    }
    else
    {
        cout<<"delete failed"<<endl;
    }

    print("test3.xml");

    return 0;
}

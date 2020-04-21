#ifndef __NESTCLASS_H__
#define __NESTCLASS_H__

//嵌套类的高级用法：
//PIMPL设计模式：
//（1）实现信息隐藏；
//（2）接口与实现进行分离；
//（3）减小编译依赖；
//（4）能够以最小代价，实现库的平滑升级。
class Line
{
class LineImpl;

public:
    Line(int,int,int,int);
    ~Line();
    void printLine() const;

private:
    LineImpl *_pimpl;
};

#endif

#ifndef __INLINE_H__
#define __INLINE_H__

//inline函数可以解决多次重复定义的问题
//在一个函数内多次定义的问题
inline int add(int x,int y)
{
    return x+y;
}
#endif

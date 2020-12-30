/*关于c++里 引用的用法 取别名 但引用不是对象*/
#include <iostream>
int main()
{
    int i, &ri = i; // 引用必须初始化
    i = 5;
    ri = 10;
    std::cout<<i <<" "<<ri << std::endl; // 10 10 
    return 0;
}
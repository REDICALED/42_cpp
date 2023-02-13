#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
int easyfind(T &one, int second)
{
    typename T::iterator iter = one.begin();
    
    while (iter != one.end())
    {
        if (second == *iter)
        {
            std::cout<<"\"I found it!\"";
            std::cout<<" input: "<<second <<", iter: "<<*iter<<std::endl;
            break;
        }
        ++iter;
    }
    if (iter == one.end())
    {
        std::cout<<"I can't found it.."<<std::endl;
        return (1);
    }
    return (0);
}

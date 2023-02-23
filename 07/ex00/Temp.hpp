#pragma once

template <typename T>
void swap(T &n1, T &n2)
{
    T tmp = n1;
    n1 = n2;
    n2 = tmp;
}

template <typename T>
T min(T n1, T n2)
{
    if (n1 < n2)
        return n1;
    else
        return n2;
}

template <typename T>
T max(T n1, T n2)
{
    if (n1 > n2)
        return n1;
    else
        return n2;
}
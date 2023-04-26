#include <iostream>

template <typename T>
long double sum(const T &val)
{
    return val;
}

template <typename T, typename... Args>
long double sum(const T &val, const Args &...args)
{
    long double result = val;
    result += sum(args...);
    return result;
}

int main()
{
    long double result;
    result = sum(123, 123.41231, 3153125, 'A', 1231231);
    std::cout.precision(10);
    std::cout << std::ios_base::fixed
              << result << std::endl;

    return 0;
}
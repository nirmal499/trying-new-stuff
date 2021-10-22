#include <iostream>

using namespace std;

template <class T>
class MyClass
{
public:
    MyClass() { cout << "My class generic" << endl; }
};

template <>
class MyClass<int>
{
public:
    MyClass() { cout << "My class int specialization" << endl; }
};

template <typename T>
bool compare(T t1, T t2)
{
    return t1 == t2;
}

const char *TRUE_STR = "TRUE";
const char *FALSE_STR = "FALSE";

int main()
{
    MyClass<float> floatClass;
    MyClass<int> intClass;

    cout << (compare(1, 1) ? TRUE_STR : FALSE_STR) << endl;
    cout << (compare("hello", "hello") ? TRUE_STR : FALSE_STR) << endl;
    cout << (compare(1, 2) ? TRUE_STR : FALSE_STR) << endl;
    cout << (compare("hello", "goodbye") ? TRUE_STR : FALSE_STR) << endl;

    return 0;
}
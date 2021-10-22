#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    string getName() const
    {
        return m_name;
    }
    int getAge() const
    {
        return m_age;
    }

private:
    string m_name;
    int m_age;
};

/*  a set will sort elements in ascending order, so if we were to create a set of
integers, they would be sorted in ascending order. This is fine for built-in types such as
int, but if we have our own custom type, then we must define how the elements are
sorted. We can define which property of that type is used for sorting and even change
the default sorting from ascending to descending */
struct customComparator
{
    bool operator()(const Person &a, const Person &b) const
    {
        return (a.getAge() > b.getAge());
    }
};
int main()
{
    set<Person, customComparator> personSet;
    Person a("bob", 35);
    Person b("bob", 25);
    Person c("bob", 125);
    Person d("bob", 78);
    personSet.insert(a);
    personSet.insert(b);
    personSet.insert(c);
    personSet.insert(d);

    for (auto person : personSet)
    {
        cout << person.getAge() << endl;
    }
}
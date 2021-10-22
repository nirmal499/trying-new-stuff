#include <iostream>
#include <set>

using namespace std;

int main()
{
    /* a set does not allow non-unique elements but a multiset does, we can use a set
        to get the number of unique elements in a multiset by inserting each element in the
        multiset 
    */
    set<int> intSet;
    multiset<int> intMultiset;

    srand(time(0)); // Initialize random number generator.

    for (unsigned int i = 0; i < 100; i++)
    {
        /* rand() function generates random number and when you use rand()%10, 
            it will give you last digit of the number.
            Random we are generating is between 1 and 101
        */
        intMultiset.insert(1 + rand() % 100);
    }
    for (auto i : intMultiset)
    {
        intSet.insert(i);
    }
    cout << "there are " << intSet.size() << " unique elements in the multiset\n";
}
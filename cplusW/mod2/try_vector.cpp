#include <iostream>
#include <string>
#include <vector>
#include <array>

void printVector(std::vector<int> &myVector)
{
    for (int i = 0; i < myVector.size(); ++i)
    {
        std::cout << myVector[i];
        if (i == myVector.size() - 1)
        {
            /* When comes to the last element */
            continue;
        }
        std::cout << ", ";
    }
    std::cout << "\n\n";
}

int main()
{
    std::cout << "\n***************** Vector 1**********************\n";
    std::vector<int> myVector{1, 2, 3, 4, 5};
    printVector(myVector);

    myVector.pop_back();
    printVector(myVector);

    myVector.push_back(6);
    printVector(myVector);

    myVector.erase(myVector.begin() + 1);
    printVector(myVector);

    myVector.insert(myVector.begin() + 3, 8);
    printVector(myVector);

    std::cout << "\n***************** Vector 2**********************\n";
    std::vector<int> myVector2(5, 45);
    printVector(myVector2);

    std::cout << "\n***************** Vector 3**********************\n";
    std::vector<int> myVector3(myVector.begin(), myVector.end());
    printVector(myVector3);

    std::cout << "\n***************** Vector 4**********************\n";

    int myArr[6]{9, 8, 7, 6, 5, 4};
    /* This will not work with -> std::array<int, 6> myArr{9, 8, 7, 6, 5, 4}; */
    std::vector<int> myVector4(myArr, myArr + 6);
    printVector(myVector4);

    return 0;
}
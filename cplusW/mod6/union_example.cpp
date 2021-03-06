#include <iostream>

/*  union types only allocate enough memory to store the largest data member. All members of
    a union share the same memory location; consequently, one chunk of allocated memory
    can be used to access different data types if they were to be laid out the same in
    memory.  */

using namespace std;

/* As demonstrated, unions can allow data to be stored and accessed in different ways.
This isn't always the best idea, as we cannot guarantee that the size of a struct of
integers is the same as that of an array of integers. Keep this in mind if unions crop up
in some work you need to do */
union Backpack
{
    int contents[4];
    struct
    {
        int food, water, key, flashlight;
    } data;
    /* Here both data and contents array are sharing same memory locations */
};

void DisplayContents(Backpack &backpack)
{
    cout << "Has Food = " << backpack.data.food << endl;
    cout << "Has Water = " << backpack.data.water << endl;
    cout << "Has Key = " << backpack.data.key << endl;
    cout << "Has Flashlight = " << backpack.data.flashlight << endl;
}

void UpdateBackpack(Backpack &backpack, int contents[4])
{
    /* Here we are taking the reference of the backpack so,
        we will be playing with the original data of backpack passed
     */
    for (int i = 0; i < 4; i++)
    {
        /* Highest value will be stored in Backpack contents */
        backpack.contents[i] = contents[i] > backpack.contents[i]
                                   ? contents[i]
                                   : backpack.contents[i];
    }
}

void RemoveFromBackpack(Backpack &backpack, int idx)
{
    backpack.contents[idx] = 0;
}

int main()
{
    Backpack backpack;

    int defaultContents[4] = {1, 1, 0, 0};
    int firstRoomContents[4] = {0, 0, 0, 1};
    int secondRoomContents[4] = {0, 0, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        backpack.contents[i] = defaultContents[i];
    }

    DisplayContents(backpack);

    cout << "*********You enter the first room***********" << endl;

    UpdateBackpack(backpack, firstRoomContents);

    DisplayContents(backpack);

    cout << "*************You eat some food before continuing***********" << endl;

    RemoveFromBackpack(backpack, 0); // food is index 0

    DisplayContents(backpack);

    cout << "**********You enter the second room***********************" << endl;

    UpdateBackpack(backpack, secondRoomContents);

    DisplayContents(backpack);

    return 0;
}
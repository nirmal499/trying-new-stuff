#include <iostream>

/* In C++ the only difference between a class and a struct is that members and base classes are private by default in classes,
    whereas they are public by default in structs.
    So structs can have constructors, and the syntax is the same as for classes. */
struct mydata
{
    char const *name_;
    bool darkside_;
    /* Why do the member variables of struct mydata have an underscore appended to their name?
        It's to make the constructor on line 8 work. If the constructor had an argument
        called name, and the struct had a member called name, you wouldn't be able to
        set that member inside the constructor because its name would be hidden by the
        argument's name */
    mydata(char const *name, bool dark)
    {
        name_ = name;
        darkside_ = dark;
    }
};

/* Here the we are playing with the original data which is in cast
    since in the for loop also we used reference
 */
void printname(mydata &data)
{
    std::cout << "Hello. I am " << data.name_ << std::endl;
    if (data.darkside_)
    {
        std::cout << "I was seduced by the dark side" << std::endl;
    }
}

int main()
{
    mydata cast[3]{

        {"Darth Vader", true},
        {"Luke Skywalker", false},
        {"Han Solo", false}

    };
    for (mydata &data : cast)
    {
        /* The & operator tells the for loop that each time through the
        loop it should initialize a reference to the array element rather than copying the array
        element into an instance variable. */
        printname(data);
    }
    return 0;
}
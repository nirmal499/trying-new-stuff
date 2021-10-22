// Casting example.
#include <iostream>
#include <string>
class Shape
{
    /* This is an abstract class since it has atleast one
        virtual function. So, this class cannot be instantiated
     */
public:
    virtual int CalculateArea() = 0;

protected:
    int area = 0;
};

class Square : public Shape
{
public:
    int height = 0;
    int CalculateArea() override
    {
        area = height * height;
        return area;
    }
};

class Circle : public Shape
{
public:
    int radius = 0;
    int CalculateArea() override
    {
        area = 3.14 * (radius * radius);
        return area;
    }
};

int main()
{
    Shape *square = new Square();
    Shape *circle = new Circle();

    Square *square2 = static_cast<Square *>(square);
    square2->height = 10;

    /* For dynamic_cast to work when down-casting, the base class must contain at least
        one virtual function. If we were to try to down-cast Shape to Circle as is, we
        would get a compiler error if Shape is not an abstract class. This is not the case 
        with static_cast, it has no conditions, so use it caarefully.
        If we try a dynamic cast and it fails, nullptr is returned. We can then
        check if our object is valid
    */
    Circle *circle2 = dynamic_cast<Circle *>(circle);
    if (circle2 != nullptr)
    {
        circle2->radius = 10;
    }
    std::cout << "Square Area: " << square->CalculateArea() << std::endl;
    std::cout << "Circle Area: " << circle->CalculateArea() << std::endl;
    delete square;
    square = nullptr;
    delete circle;
    circle = nullptr;

    /* dynamic_cast is safer than static_cast */

    return 0;
}
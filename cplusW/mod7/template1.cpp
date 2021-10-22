#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T, typename U>
class Position
{
private:
    T m_x;
    T m_y;
    U m_z;

public:
    Position(T x, T y, U z) : m_x(x), m_y(y), m_z(z)
    {
    }

    T getX() { return m_x; }
    T getY() { return m_y; }
    U getZ() { return m_z; }
};

template <typename T>
T getLargest(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

int main()
{
    Position<int, float> intPosition(1, 3, 80.5f);
    Position<float, int> floatPosition(2.5f, 3.14f, 80);
    Position<long, float> longPosition(5, 3, 200);

    cout << "*****************First Position*************************\n";
    cout << "Type: " << typeid(intPosition.getX()).name() << " X: " << intPosition.getX() << endl;
    cout << "Type: " << typeid(intPosition.getY()).name() << " Y: " << intPosition.getY() << endl;
    cout << "Type: " << typeid(intPosition.getZ()).name() << " Z: " << intPosition.getZ() << endl;

    cout << "*****************Second Position************************\n";
    cout << "Type: " << typeid(floatPosition.getX()).name() << " X: " << floatPosition.getX() << endl;
    cout << "Type: " << typeid(floatPosition.getY()).name() << " Y: " << floatPosition.getY() << endl;
    cout << "Type: " << typeid(floatPosition.getZ()).name() << " Z: " << floatPosition.getZ() << endl;

    cout << "*****************Third Position**************************\n";
    cout << "Type: " << typeid(longPosition.getX()).name() << " X: " << longPosition.getX() << endl;
    cout << "Type: " << typeid(longPosition.getY()).name() << " Y: " << longPosition.getY() << endl;
    cout << "Type: " << typeid(longPosition.getZ()).name() << " Z: " << longPosition.getZ() << endl;

    cout << "*****************Largest between X and Y [becoz they both are of same type]***********\n";
    cout << "First Position: " << getLargest(intPosition.getX(), intPosition.getY()) << endl;
    cout << "Second Position: " << getLargest(floatPosition.getX(), floatPosition.getY()) << endl;
    cout << "Third Position: " << getLargest(longPosition.getX(), longPosition.getY()) << endl;

    return 0;
}
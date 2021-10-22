#include <iostream>

using namespace std;

template <typename T>
class Position
{
private:
    T m_x;
    T m_y;

public:
    Position(T x, T y) : m_x(x), m_y(y)
    {
    }

    Position(const T &t)
    {
        m_x = t.m_x;
        m_y = t.m_y;
    }

    T getX() { return m_x; }
    T getY() { return m_y; }
};

/* PositionHolder is a new template class that will be used to wrap Position<T> types */
template <class T>
class PositionHolder
{
private:
    T m_position;

public:
    template <typename U>
    PositionHolder(U x, U y) : m_position(x, y) {}

    PositionHolder(const T &t) : m_position(t) {}
};

/*  Note that in the preceding case, the copy constructor would not need to be defined, as a shallow copy would
suffice, but this is not always the case and should be kept in mind */

int main()
{
    PositionHolder<Position<float>> positionHolder(Position<float>(20.0f, 30.0f));
    return 0;
}
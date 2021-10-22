#include <iostream>
#include <cstring>
using namespace std;

class VideoClip
{
public:
    float m_videoLength;
    string m_videoName;

    int m_dataLength;
    char *m_data;

    /* Default Constructor */
    VideoClip()
    {
        m_videoName = "NOT SET";
        m_videoLength = 0;
        m_dataLength = 0;
        m_data = 0; /* 0 means NULL */
    }

    /* Parameterized Constructor */
    VideoClip(float videoLength, string videoName, const char *data)
    {
        m_videoLength = videoLength;
        m_videoName = videoName;

        m_dataLength = strlen(data);
        m_data = new char[m_dataLength + 1];
        strcpy(m_data, data);
    }

    /* Copy Constructor */
    VideoClip(const VideoClip &vc)
    {
        /* shallow copy */
        m_videoLength = vc.m_videoLength;
        m_videoName = vc.m_videoName;
        m_dataLength = vc.m_dataLength;

        /* Deep copy */
        m_data = new char[m_dataLength + 1];
        strcpy(m_data, vc.m_data);
    }

    /* Copy assignment operator */
    VideoClip &operator=(const VideoClip &rhs)
    {
        /* Here addressed are check */
        if (this != &rhs)
        {
            m_videoLength = rhs.m_videoLength;
            m_videoName = rhs.m_videoName;
            m_dataLength = rhs.m_dataLength;

            /* Here we are adding 1 becoz to make space for the null character */
            char *newData = new char[m_dataLength + 1];
            strcpy(newData, rhs.m_data);

            delete[] m_data;
            m_data = newData;
        }

        return *this;
    }

    /* Destructor */
    ~VideoClip()
    {
        delete[] m_data;
    }
};

int main()
{
    VideoClip vc1(10.0f, "Halloween (2019)", "dfhdhfidghirhgkhrfkghfkg");
    VideoClip vc2(20.0f, "Halloween (1978)", "jkghdfjkhgjhgfjdfg");
    VideoClip vc3(50.0f, "The Shining", "kotriothgrngirgr");

    cout << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
    cout << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
    cout << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;

    VideoClip vc4 = vc1; /* Here Copy constructor is called */

    vc2 = vc4; /* Here Cop assignment operator is called*/

    cout << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
    cout << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
    cout << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;
    cout << vc4.m_videoLength << " " << vc4.m_videoName << " " << vc4.m_data << endl;

    return 0;
}
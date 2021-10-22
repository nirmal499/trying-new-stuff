#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/* A general rule to follow, known as the Rule of Three is that if a destructor, copy constructor, or assignment operator is
explicitly defined, then all three should probably be explicitly defined
 */
class Track
{
public:
    // m_ prefix added to member variables, to avoid naming conflicts with parameter names
    float m_lengthInSeconds;
    string m_trackName;

    // additional artist name string member variable
    string m_artistName;

    // sample clip data
    int m_dataSize;
    char *m_data;

    // added additional artist name constructor parameter
    Track(float lengthInSeconds = 0.0f, string trackName = "not set", string artistName = "not set", const char *data = NULL)
    {
        m_lengthInSeconds = lengthInSeconds;
        m_trackName = trackName;
        m_artistName = artistName;

        // create the sample clip from data
        m_dataSize = strlen(data);
        m_data = new char[m_dataSize + 1];
        strcpy(m_data, data);
    }

    ~Track()
    {
        delete[] m_data;
    }

    /* Copy constructor */
    /*  It takes a reference to a const parameter. Making the parameter const ensures that the
        copy constructor will not alter the passed-in parameter. A reference to a parameter is
        used in the case of a copy constructor as a result of one of the situations where a copy
        constructor would be called; a copy constructor is called when an object is passed to a
        function by a value. Consequently, if the parameter is not a reference, then passing it 
        into the copy constructor would require calling the copy constructor to make a copy. This copy
        constructor would make a copy which would continue to invoke the copy constructor,
        and so on and so on (an infinite loop) 
    */
    Track(const Track &track)
    {
        /* The copy constructor copies any members that are value types directly, but, in the
            case of the char array that was dynamically created to hold our data, it has to create a
            new char array for the new class and then copy the data from the other instance. We
            now know that this is required as we want a copy of the data, not a pointer to the other
            instance's data 
        */

        // these can be shallow copied
        m_lengthInSeconds = track.m_lengthInSeconds;
        m_trackName = track.m_trackName;
        m_artistName = track.m_artistName;
        m_dataSize = track.m_dataSize;

        /* Now, we cannot just assign the data array to the track data array because, as we
            have discussed, this will only copy the pointer address and lead to both data arrays
            pointing to the same place. So, we must initialize the data array using new[] (we
            already know the size from the stored value in m_dataSize)
         */
        // allocate memory for the copied pointer
        m_data = new char[m_dataSize + 1];
        strcpy(m_data, track.m_data);
    }

    /* Copy Assignment Operator */
    Track &operator=(const Track &track)
    {
        /* An important check with an assignment operator is to verify that we are not
            attempting to assign an object to itself. This is known as self-assignment, and we
            do not need to execute our copying if this is the case 
        */
        // check for self assignment
        if (this != &track)
        {
            // these can be shallow copied
            m_lengthInSeconds = track.m_lengthInSeconds;
            m_trackName = track.m_trackName;
            m_artistName = track.m_artistName;
            m_dataSize = track.m_dataSize;

            /* We do deep copy for the dynamically allocated variables */
            /* Since we are assigning to an existing object, we need to delete the dynamically
                allocated array so that we can copy our new values over to it. First, we create a
                new char* array and copy the passed-in track reference objects data into it
            */
            // allocate new memory and copy the existing data from the passed in object
            char *newData = new char[m_dataSize + 1];
            strcpy(newData, track.m_data);

            // since this is an already existing object we must deallocate existing memory
            delete[] m_data;

            // assign the new data
            m_data = newData;
            /* Finally, we can assign the newData array to the now-deleted m_data array. Note
                that we could not just assign the passed-in track reference m_data to the existing
                m_data array, because then we would just be making them point to the same place,
                which we know is not the behavior we want. To remedy this, we create a new array
                and make the m_data array point to that instead 
            */
        }
        return *this;
        /* And now, we can return a reference to the track we are assigning to; using the
            this keyword 
        */
    }

    void SetData(float lengthInSeconds = 0.0f, string trackName = "not set", const char *newData = NULL)
    {
        m_lengthInSeconds = lengthInSeconds;
        m_trackName = trackName;

        // delete the array so it can be recreated
        delete[] m_data;

        // create the sample clip from data
        m_dataSize = strlen(newData);
        m_data = new char[m_dataSize + 1];
        strcpy(m_data, newData);
    }
};

/* What happens when an object is passed by value to a function?
    A copy constructor is called. When this function is called, the Track object whose value
    is printed is actually a local variable that is a copy of the passed-in Track object, and
    once this local variable goes out of scope, its destructor will be called. The Track class
    deletes the m_data array in its destructor, and, since the Track class does not have a
    user-defined copy constructor that correctly executes a deep copy, it deletes the same
    m_data variable used by the passed-in object 
*/
void PrintTrackName(Track track)
{
    cout << "Track Name = " << track.m_trackName << endl;
}

int main()
{
    Track track(200.0f, "Still Alive", "GlaDos", "f651270d6011098375db09912b03e5e7");
    PrintTrackName(track);

    /* If we have done
        Track track2 = track; // copy constructor is called
     */

    // Construct another track with new values
    Track track2(300.0f, "Want You Gone", "GlaDos", "db6fd7d74393b375344010a0c9cc4535");

    // Here the assignment operator is called
    track2 = track;

    // Set the new needed data
    track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");
    cout << "Track 1" << endl;
    cout << "Artist = " << track.m_artistName << endl;
    cout << "Track Name = " << track.m_trackName << endl;
    cout << "Track Length = " << track.m_lengthInSeconds << endl;
    cout << "Track Data = " << track.m_data << endl;
    cout << endl;
    cout << "Track 2" << endl;
    cout << "Artist = " << track2.m_artistName << endl;
    cout << "Track Name = " << track2.m_trackName << endl;
    cout << "Track Length = " << track2.m_lengthInSeconds << endl;
    cout << "Track Data = " << track2.m_data << endl;

    return 0;
}
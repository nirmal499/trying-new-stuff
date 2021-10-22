#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void SCRAM()
{
    cout << "SCRAM! I mean it. Get away from here!" << endl;
}

bool reactor_safety_check()
{
    static int count = 0;
    ++count;
    if (count % 17 == 0)
    {
        throw runtime_error("Sensor glitch");
    }
    else if (count % 69 == 0)
    {
        throw 123;
    }
    else if (count % 199 == 0)
    {
        return false;
    }

    return true;
}

int main()
{
    bool continue_flag;
    do
    {
        try
        {
            continue_flag = reactor_safety_check();
        }
        catch (runtime_error &e)
        {
            /* This is for the runtime error at count % 17 == 0  */
            cout << "caught runtime error " << e.what() << endl;
        }
        catch (exception &e)
        {
            cout << "caught exception " << e.what() << endl;
            SCRAM();
            break;
        }
        catch (...)
        {
            /* This is for throw 123 error at count % 69 == 0*/
            cout << "caught unknown exception type" << endl;
            SCRAM();
            break;
        }
    } while (continue_flag == true);
    cout << "main() exiting" << endl;
    return 0;
}
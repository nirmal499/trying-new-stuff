/* Unwinding the stack is the process of destroying the local variables of each scope on
the stack and looking for a try/catch block */

#include <iostream>
#include <exception>
#include <memory>

using namespace std;

class noisy
{
    char const *s_;

public:
    noisy(char const *s) { cout << "constructing " << (s_ = s) << endl; }
    ~noisy() { cout << "destroying " << s_ << endl; }
};

int deeply_nested()
{
    auto n = make_unique<noisy>("deeply_nested");
    throw logic_error("totally illogical");
    return 0;
}

int intermediate()
{
    noisy n("intermediate");
    int rc = deeply_nested();
    cout << "after calling deeply_nested()" << endl;
    return rc;
}

/* deeply_nested() threw an exception. We know that happened because the
    noisy instance in deeply_nested() was destroyed, but the output
    statement in intermediate() wasn't executed. There was no try/catch block
    in intermediate(), so the noisy instance in intermediate() was destroyed
    There is a try/catch block in main(). The dynamic instance of noisy
    in the try/catch block is destroyed. The type of the exception is
    std::logic_error, which is derived from std::exception. There is a catch
    clause for exception, so the catch clause was executed. Execution
    continues with the output statement after the try/catch block 
*/

int main()
{
    try
    {
        auto n = make_unique<noisy>("try in main");
        int rc = intermediate();
        cout << "intermediate() returned " << rc << endl;
    }
    catch (exception &e)
    {
        cout << "in catch: exception: " << e.what() << endl;
    }

    cout << "ending main" << endl;

    return 0;
}

/* C++ standard permits the implementation not to unwind the stack when an
    exception is uncaught.
    Every program that uses exception handling should put at least a minimal try/
    catch block around the contents of main(), so that an unexpected exception
    unwinds the stack
 */
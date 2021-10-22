#include <iostream>
#include <memory>
#include <cstring>

struct Noise
{
    Noise()
    {
        std::cout << "Default Constructing Noise\n";
    }
    Noise(int i)
    {
        std::cout << "Constructing Noise with arg " << i << "\n";
    }
    // ~Noise()
    // {
    //     std::cout << "Destructing Noise\n";
    // }
};

int main()
{
    /* declare a unique_ptr<noisy> instance called u1 and initialize it to a new noisy instance
        This new-expression calls noisy's default constructor
    */
    std::unique_ptr<Noise> u1(new Noise);
    /* Declare a unique_ptr<noisy> instance called u2. The default constructor for unique_ptr<> sets this pointer to nullptr. Then, set u2 to a new noisy instance
        initialized to 100. using the Noise constructor that takes an int argument. The
        member function unique_ptr::reset() deletes any dynamic variable the
        unique_ptr currently refers to, and then sets the unique_ptr to point to the
        argument of reset() */
    std::unique_ptr<Noise> u2;
    u2.reset(new Noise(100));

    std::unique_ptr<Noise> u3(new Noise[3]);
    std::unique_ptr<Noise> u4(new Noise[2]{1});
    std::unique_ptr<Noise> u8(new Noise(5));
    std::unique_ptr<Noise> u5;
    /* Just as unique_ptr<> hides the delete expression in its definition, make_unique() does the
    same for the new expression */
    std::unique_ptr<Noise> u6 = std::make_unique<Noise>();
    /* It is same as std::unique_ptr<Noise> u1(new Noise); */
    auto u7 = std::make_unique<Noise>(500);
    /* It is same as std::unique_ptr<Noise> u8(new Noise(500)); */
    std::cout << "**************Indicator*****************************\n";
    auto u9 = std::make_unique<Noise[]>(3);

    std::cout
        << "Before transfer of ownership u1 = " << u1.get()
        << ", u5 = " << u5.get() << "\n";

    /* Transfer ownership of the dynamic variable in u1 to u5. Use the release()
    member function to release ownership of the dynamic variable of u1 and return
    an owned raw pointer. This becomes the argument to reset(), which deletes
    the dynamic variable owned by u5 and then accepts ownership of the owned
    raw pointer from u1. Since u5 was constructed by default, its previous value
    was nullptr */
    u5.reset(u1.release());
    std::cout << "Ater  transfer of ownership u1 = " << u1.get()
              << ", u5 = " << u5.get() << "\n";
    /* Transfer ownership of u5 back to u1 by a different method. Use the function
    std::move() to move u5 to u1 using move semantics. At the end of this statement, u5 is nullptr:
     */
    u1 = std::move(u5);
    std::cout << "Ater second transfer u1 = " << u1.get()
              << ", u5 = " << u5.get() << "\n";

    std::unique_ptr<char[]> buf(new char[20]);
    strcpy(buf.get(), "xyzzy");
    std::cout << "buf = " << buf.get() << "\n";

    return 0;
}
#include <exception>
#include <iostream>
using namespace std;

class A
{
public:
    A(int n) : i(n) { cout << i; }

    ~A() { cout << i; }

private:
    int i;
};

int f(int n)
{
    if (n == 1) {
        throw std::logic_error("0");
        cout << "7" << endl;
    }
    A a(n);
    return f(n - 1);
}

int main()
{
    try {
        int ret = f(3);
        A a(ret);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {

    // define a lambda function named 'add'
    // that takes two integers  and returns their sum
    auto add = [] (int a, int b) {
        return a + b;
    };

    // call the lambda with arguments 3 and 4
    int result = add(3, 4);

    // print the result.
    cout << "Result: " << result << endl;

    return 0;
}

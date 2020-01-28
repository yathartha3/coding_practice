#include <iostream>
using namespace std;

void function()
{
    static int count{};
    count ++;
    cout<<count<<endl;
}

int main() {
    // insert code here...
    std::cout << "Test static\n";
    function();
    function();
    function();

    /*
    You cannot do the following:
    count++;
    It is true that the count object's lifetime is till the end of this program. However, it still remains local.
    This is something I was confused when reading the Crash Course C++ book.
    */
    return 0;
}

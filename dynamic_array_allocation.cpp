/* Modified from Tutorials point example on "return array from functions"
The probem with that tutorial is that it defines a static array and returns a pointer to that array; which is not a good practive in my opinion

My approach dynamically allocates memory using 'new' keyword, and return pointer to the newly allocated array

*/
#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom(int n)
{
   int *ptr_ = new int[n];
  
   // set the seed
   srand( (unsigned)time( NULL ) );
  
   for (int i = 0; i < n; ++i) {
      ptr_[i] = rand();
      cout << ptr_[i] << endl;
   }

   return ptr_;
}

int main () {
   int n = 10; // how many random numbers
   auto p = getRandom(n);
   
   for ( int i = 0; i < n; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }

   return 0;
}

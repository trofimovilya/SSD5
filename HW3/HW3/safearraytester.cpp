#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "safearray.h"

int main1 (int argc, char *argv[]) {
  safearray<int> A(5);

  int index = 0;

  for (index = 0; index < 5; index++) {
    A[index] = index;
  }

  for (index = 0; index < 5; index++) {
    cout << A[index] << endl;
  }

  /*!Begin Snippet*/
  try {
    cout << A[-1] << endl; // attempt to read
  }
  catch (out_of_range& e) {
    cerr << e.what() << endl; // "Index is below 0"
  }

  try {
    A[100] = 1;  // attempt to write
  }
  catch (out_of_range& e) {
    cerr << e.what() << endl; // "Index is too high"
  }
  /*!End Snippet*/
  return EXIT_SUCCESS;
}

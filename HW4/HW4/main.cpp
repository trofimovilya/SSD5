#include   <iostream>
#include   <string>
#include   <cstdlib>
#include   <stdexcept>

using namespace std;

#include "enhancedsafearray.h"

void test_copy_constructor(EnhancedSafeArray<int> i);
void test_assignment(void);
void test_equality(void);

int main(int argc, char* argv[]) {

    try {

        EnhancedSafeArray<int> arr(100);

        for (int i = 0; i < 100; i++) {
            arr[i] = i;
        }

        test_copy_constructor(arr);
        test_assignment();
        test_equality();

        return EXIT_SUCCESS;

    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught!\n";
    }
    return EXIT_FAILURE;
}

void test_copy_constructor(EnhancedSafeArray<int> arr) {

    try {

        for (int i = 0; i < 100; i++) {
            if (arr[i] != i) {
                throw runtime_error("test_copy_constructor");
            }
        }
        if (arr.size() != 100) {
            throw runtime_error("test_copy_constructor");
        }
        cout << "Copy constructor implementation looks correct.\n";
    }
    catch (...) {
        cout << "Copy constructor implementation is not correct.\n";
    }
}

void test_assignment(void) {

    try {

        EnhancedSafeArray<string> s1(10);
        EnhancedSafeArray<string> s2(100);
        for (int i = 0; i < 100; i++) {
            s2[i] = "test";
        }

        s1 = s2;
        for (int i = 0; i < 100; i++) {
            if (s1[i] != "test") {
                throw runtime_error("test_assignment");
            }
        }
        if (s1.size() != 100) {
            throw runtime_error("test_assignment");
        }
        cout << "Assignment operator looks correct.\n";
    }
    catch (...) {
        cout << "Assignment operator is not correct.\n";
    }

}

void test_equality(void) {

    try {

        EnhancedSafeArray<int> i1(5);
        EnhancedSafeArray<int> i2(4);
        EnhancedSafeArray<int> i3(4);

        for (int i = 0; i < 4; i++) {
            i1[i] = i;
            i2[i] = i;
            i3[i] = i;
        }
        i1[4] = 4;

        if (i1 == i2) {
            throw runtime_error("test_equality");
        }

        if (!(i2 == i3)) {
            throw runtime_error("test_equality");
        }
        i2[3] = 0;

        if (i2 == i3) {
            throw runtime_error("test_equality");
        }

        cout << "Equality operator looks correct.\n";
    }
    catch (...) {
        cout << "Equality operator is not correct.\n";
    }
}

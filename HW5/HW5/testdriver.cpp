#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>

#include "EnhancedLinkedList.h"

using namespace std;

int main (int argc, char* argv[]) {

    EnhancedLinkedList<string> master;
    master.push_back ("one");
    master.push_back ("two");
    master.push_back ("three");
    master.push_back ("four");
    master.push_back ("five");


  {
    cout << "Find with empty list: This test should indicate not found exception" << endl;
    EnhancedLinkedList<string> l;

    try {
      l.find_first("not there");
    }
    catch (logic_error& e) {
      cout << e.what() << endl;
    }
    cout << endl;
  }

  {
    cout << "Looking for non existent item: This test should indicate not found exception" << endl;
    EnhancedLinkedList<string> l(master);
   
    try {
      l.find_first("not there");
    }
    catch (logic_error& e) {
      cout << e.what() << endl;
    }
    cout << endl;
  }

  {
    cout << "Looking for first item: This test should indicate found" << endl;
     EnhancedLinkedList<string> l(master);

    try {
      string got = l.find_first("one");
      cout << "found" << endl;
    }
    catch (logic_error& e) {
      cout << e.what() << endl;
    }
    cout << endl;
  }

  /*
   * find last: find last item
   */
  {
    cout << "Looking for last item: This test should indicate found" << endl;
    EnhancedLinkedList<string> l(master);
    
    try {
      string got = l.find_first("five");
      cout << "found" << endl;
    }
    catch (logic_error& e) {
      cout << e.what() << endl;
    }
    cout << endl;
  }

  /*
   * find in middle: find an item in middle
   */
  {
    cout << "Looking for middle item: This test should indicate found" << endl;
    EnhancedLinkedList<string> l(master);

    try {
      string got = l.find_first("three");
        cout << "found" << endl;
    }
    catch (logic_error& e) {
      cout << e.what() << endl;
    }
    cout << endl;
  }

  /*
   * find all, including head and tail
   */
  {
    cout << "Looking for three 'magic' items: Should print 'magic' three times" << endl;
    EnhancedLinkedList<string> l;
    
    l.push_back ("magic");
    l.push_back ("one");
    l.push_back ("two");
    l.push_back ("three");
    l.push_back ("magic");
    l.push_back ("four");
    l.push_back ("five");
    l.push_back ("magic");
   
    LinkedList<string> got = l.find_all("magic");
    got.dump();
    cout << endl;
  }

  /*
   * remove first on empty list
   */
 {
    cout << "Removing item from empty list: " << endl;
    EnhancedLinkedList<string> l;

    l.remove_first("not in list");
    if (0 == l.size()) {
    	   cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }


  /*
   * remove first, including head and tail
   */
 {
    cout << "Removing item from list that does not contain item: " << endl;
    EnhancedLinkedList<string> l(master);

    l.remove_first("not in list");
    if (5 == l.size()) {
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }

  /*
   * remove first item from list
   */
 {
    cout << "Removing first item from list: " << endl;
    EnhancedLinkedList<string> l(master);

  		l.remove_first("one");
    if (4 == l.size()) {
        cout << "Should be (two, three, four, five):" << endl;
        l.dump();
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }

  /*
   * remove last item from list
   */
 {
    cout << "Removing last item from list: " << endl;
    EnhancedLinkedList<string> l(master);

   	l.remove_first("five");
    if (4 == l.size()) {
        cout << "Should be (one, two, three, four):" << endl;
        l.dump();
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }

  /*
   * remove last item from list
   */
 {
    cout << "Removing middle item from list: " << endl;
    EnhancedLinkedList<string> l(master);

    l.remove_first("three");
    if (4 == l.size()) {
        cout << "Should be (one, two, four, five):" << endl;
        l.dump();
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }

 /*
   * remove last item from list
   */
 {
    cout << "Removing all on empty list: " << endl;
    EnhancedLinkedList<string> l;

    l.remove_all("three");
    if (0 == l.size()) {
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }
    cout << endl;
  }

 /*
   * remove last item from list
   */
 {
    cout << "Removing all on list, should print (one, two, three, four, five): " << endl;
    EnhancedLinkedList<string> l;

    l.push_back ("magic");
    l.push_back ("one");
    l.push_back ("two");
    l.push_back ("three");
    l.push_back ("magic");
    l.push_back ("four");
    l.push_back ("five");
    l.push_back ("magic");
   
    l.remove_all("magic");
    l.dump();
  }


  return EXIT_SUCCESS;
 
}

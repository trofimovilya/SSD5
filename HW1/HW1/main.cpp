#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#include "date.h"
#include "homework.h"
#include "homeworklist.h"

using namespace std;

// Constants
const int EMPTY = 0;
const int ADD = 1;
const int LIST = 2;
const int DUE_ON = 3;
const int DUE_BEFORE = 4;
const int DUE_AFTER = 5;
const int QUIT = 6;


// Function declarations
date string_to_date (string);
void display_menu (void);
int read_menu_selection (void);
void display_due(homeworklist, int);
date read_date(string);


// Function definitions
int main (int argc, char *argv[]) {

    string hw_name;
    date hw_asg_date;
    date hw_due_date;
    homework new_asg;

    homeworklist hl;

    int choice = EMPTY;

    while (choice != QUIT) {

        display_menu();
        choice = read_menu_selection();

        switch (choice) {

        case ADD:

            // read in the name, date assigned, and due date
            cout << endl << "Homework name: ";
            cin >> hw_name;

            hw_asg_date = read_date("Date assigned: ");
            hw_due_date = read_date("Date due: ");

            // create and store the homework object
            new_asg = homework(hw_name, hw_asg_date, hw_due_date);
            hl.add(new_asg);
            break;

        case LIST:
            cout << hl << endl;
            break;

        case DUE_AFTER:   // falls through
        case DUE_BEFORE:  // falls through
        case DUE_ON:
            // Due after, before, and on are all
            // handled by this case. Since there
            display_due(hl, choice);
            break;

        case QUIT:
            break;

        default:
            choice = EMPTY;
            break;

        } // end switch (choice)

    } // end main work loop (while)

    return EXIT_SUCCESS;
}

void display_menu(void) {

    cout << "\n1. Add\n";
    cout << "2. List all assignments\n";
    cout << "3. List all assignments \"due on\" a particular date\n";
    cout << "4. List all assignments \"due before\" a particular date\n";
    cout << "5. List all assignments \"due after\" a particular date\n";
    cout << "6. Quit\n";
}

int read_menu_selection(void) {

    int choice = 0;
    cout << "Enter selection:  ";
    cin >> choice;
    cout << endl;

    return choice;
}

void display_due(homeworklist hl, int choice) {

    date d = read_date("Enter a date: ");

    if (DUE_AFTER == choice) {
        cout << endl << hl.dueafter (d);

    } else if (DUE_ON == choice) {
        cout << endl << hl.dueon (d);

    } else if (DUE_BEFORE == choice) {
        cout << endl << hl.duebefore (d);

    }

}

date read_date(string prompt) {

    // display prompt, read input, convert to date

    cout << prompt;

    string date_whole;
    cin >> date_whole;

    return string_to_date(date_whole);
}

date string_to_date (string date_string) {

    // convert from a string to a date

    int day, month, year;
    int posn;

    posn = date_string.find_first_of ("/", 0);
    month = atoi(date_string.substr(0, posn).c_str());

    day = atoi(date_string.substr(posn + 1,
                                  date_string.find_last_of("/", 0)).c_str());

    posn = date_string.find_first_of("/", posn + 1) + 1;
    year = atoi(date_string.substr(posn, date_string.length()).c_str());

    return date (day, month, year);
}

// eof

// Author: Ilya Trofimov
// Group: 272(2)
// Date: 28 Jan 2014

#include "homeworklist.h"

using namespace std;

homeworklist::homeworklist() : current_size(0) {}

bool homeworklist::add(homework h) {
    if (current_size < LIST_MAX) {
        list[current_size++] = h;
        return true;
    }

    return false;
}

homeworklist homeworklist::dueafter(date d) {
    homeworklist dueAfterList;

    for (int i = 0; i < current_size; ++i) {
        if (list[i].compareTo(homework("", date(), d)) > 0) {
            dueAfterList.add(list[i]);
        }
    }

    return dueAfterList;
}

homeworklist homeworklist::duebefore(date d) {
    homeworklist dueBeforeList;

    for (int i = 0; i < current_size; ++i) {
        if (list[i].compareTo(homework("", date(), d)) < 0) {
            dueBeforeList.add(list[i]);
        }
    }

    return dueBeforeList;
}


homeworklist homeworklist::dueon(date d) {
    homeworklist dueOnList;

    for (int i = 0; i < current_size; ++i) {
        if (list[i].compareTo(homework("", date(), d)) == 0) {
            dueOnList.add(list[i]);
        }
    }

    return dueOnList;
}

ostream& operator<< (ostream& stream, homeworklist hl) {
    for (int i = 0; i < hl.current_size; ++i) {
        stream << hl.list[i];
    }

    return stream;
}
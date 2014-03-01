// Author: Ilya Trofimov
// Group: 272(2)
// Date: 28 Jan 2014

#include "homework.h";

using namespace std;

homework::homework() : name(), assigned_date(), due_date() {}

homework::homework(string name_value, date a_date_value, date d_date_value) : name(name_value), assigned_date(a_date_value), due_date(d_date_value) {}

int homework::compareTo(homework another_homework) {
    return due_date.compareTo(another_homework.due_date);
}

ostream &operator<< (ostream &stream, homework h) {
    stream << h.name << ": " << h.assigned_date << " - " << h.due_date;
    return stream;
}
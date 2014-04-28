/*
* @Author: Ilya Trofimov
* @Date:   2014-04-08 11:28:32
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-04-08 11:30:35
*/

#include <iostream>
#include <fstream>

using namespace std;

#include "grid.h"

int grid::indexof (int row, int col) const {
    return row * cols + col;
}

bool grid::infected(int row, int col) const {
    return (area->operator[](indexof(row, col)) == INFECTED);
}

bool grid::isMarked(int row, int col) const {
    return (marked->operator[](indexof(row, col)) == INFECTED);
}

grid::grid (string file) {
    ifstream grid_file;

    grid_file.open (file.c_str());

    grid_file >> rows;
    grid_file >> cols;

    enumerator = 0;
    area = new vector<bool>(rows * cols, NOT_INFECTED);
    marked = new vector<bool>(rows * cols, NOT_INFECTED);

    while (true) {

        int blob_row;
        int blob_col;

        grid_file >> blob_row;
        grid_file >> blob_col;

        if (grid_file.eof()) {
            break;
        }

        area->operator[](indexof(blob_row, blob_col)) = INFECTED;
    }

    grid_file.close();
}

grid::~grid () {
    delete area;
    delete marked;
}

ostream& operator<<(ostream& stream, const grid& ob) {
    for (int row = 0; row < ob.rows; row++) {
        for (int col = 0; col < ob.cols; col++) {
            stream << ob.area->operator[](ob.indexof(row, col));

            if (ob.marked->operator[](ob.indexof(row, col))) {
                stream << "+   ";
            } else {
                stream << "    ";
            }
        }

        stream << endl;
    }

    stream << endl;
    return stream;
}

int grid::count (int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
            infected(row, col) && !isMarked(row, col)) {

        enumerator++;
        marked->operator[](indexof(row, col)) = INFECTED;

        count(row, col - 1);
        count(row, col + 1);
        count(row - 1, col);
        count(row - 1, col - 1);
        count(row - 1, col + 1);
        count(row + 1, col);
        count(row + 1, col - 1);
        count(row + 1, col + 1);
    }

    return enumerator;
}
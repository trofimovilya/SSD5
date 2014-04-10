/*
* @Author: Ilya Trofimov
* @Date:   2014-04-08 11:25:18
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-04-08 11:31:22
*/

#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>

using namespace std;

/*
 * IMPORTANT NOTE:
 *
 * For this assignment, you might need to add state to the
 * class and/or augment existing methods, and/or create private helper
 * methods, but you should not delare new public methods
 */

const bool INFECTED = true;
const bool NOT_INFECTED = false;

class grid;

class grid {

private:
    int rows;
    int cols;
    int enumerator;
    vector<bool>* area;
    vector<bool>* marked;

    int recoursiveCount(int row, int col);
    int indexof (int row, int col) const;
    bool infected(int row, int col) const;
    bool isMarked(int row, int col) const;

public:
    grid (string file);
    ~grid ();

    int count (int row, int col);

    friend ostream& operator<<(ostream& stream, const grid& ob);

};

#endif

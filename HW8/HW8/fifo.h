/*
* @Author: Ilya Trofimov
* @Date:   2014-03-30 01:49:00
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-03-30 20:38:24
*/

#ifndef FIFO_H
#define FIFO_H

#include <fstream>
#include "simulator.h"

class fifo : public simulator {
private:
    void print(string action, const event& ev, int time, ostream& out);
    void printStat(int totalJobs, int aggLatency, ostream& out);
    string generateFileName(const string& fileName);

protected:
    queue<event> waiting;

public:
    fifo(int seconds_per_page);
    void simulate(string file);
};

#endif
/*
* @Author: Ilya Trofimov
* @Date:   2014-03-30 01:49:00
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-03-30 04:57:09
*/

#ifndef FIFO_H
#define FIFO_H

#include "simulator.h"

class fifo : public simulator {

protected:
    queue<event> waiting;

public:
    fifo(int spp);
    void simulate(string file);

};

#endif
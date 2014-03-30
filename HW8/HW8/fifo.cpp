/*
* @Author: Ilya Trofimov
* @Date:   2014-03-30 04:57:42
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-03-30 04:57:51
*/

#include "fifo.h"

fifo::fifo(int seconds_per_page) : simulator(seconds_per_page) {}

void print(event& ev, string action) {
    cout << "\t" << action << ": ";
    cout << ev.getjob().getnumpages() << " pages ";
    cout << "from " << ev.getjob().getuser();
    cout << " at " << ev.arrival_time() << " seconds" << endl;
}

void fifo::simulate(string file) {
    loadworkload(file);

    for (int currentTime = 0; !workload.empty(); ++currentTime) {

        if (workload.front().arrival_time() == currentTime) {
            --currentTime;
            print(workload.front(), "Arriving");
            waiting.push(workload.front());
            workload.pop();
        }







   }
}
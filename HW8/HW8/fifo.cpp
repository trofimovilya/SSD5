/*
* @Author: Ilya Trofimov
* @Date:   2014-03-30 04:57:42
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-03-30 21:20:26
*/

#include "fifo.h"

fifo::fifo(int seconds_per_page) : simulator(seconds_per_page) {}

void fifo::simulate(string file) {
    loadworkload(file);

    if (workload.empty()) {
        cerr << "Nothing to print :(" << endl;
        return;
    }
    
    ofstream fout;
    fout.open(generateFileName(file));

    fout << "FIFO Simulation" << endl << endl;
    clog << "FIFO Simulation" << endl << endl;

    bool wasArrived; // Flag that shows is any job was added in workload at particular sec
    int currentTime = 0; // Time counter
    int readyTime = 0; // Time when the printer is ready to print
    int aggLatency = 0; // Aggregate latency
    int totalJobs = workload.size(); // Total arrived jobs

    while (true) {
        wasArrived = false;

        if (!workload.empty() && workload.front().arrival_time() == currentTime) {
            wasArrived = true;
            print("Arriving", workload.front(), workload.front().arrival_time(), fout);
            print("Arriving", workload.front(), workload.front().arrival_time(), clog);
            aggLatency -= workload.front().arrival_time();
            waiting.push(workload.front());
            workload.pop();
        }

        if (!waiting.empty() && currentTime >= readyTime) {
            print("Servicing", waiting.front(), currentTime, fout);
            print("Servicing", waiting.front(), currentTime, clog);
            readyTime = currentTime + waiting.front().getjob().getnumpages() * seconds_per_page;
            aggLatency += currentTime;
            waiting.pop();
        }

        if (!wasArrived) {
            ++currentTime;
        }

        if (workload.empty() & waiting.empty()) {
            break;
        }
    }

    printStat(totalJobs, aggLatency, fout);
    printStat(totalJobs, aggLatency, clog);
    
    fout.close();
}

void fifo::print(string action, const event& ev, int time, ostream& out) {
    out << "\t" << action << ": ";
    out << ev.getjob().getnumpages() << " pages ";
    out << "from " << ev.getjob().getuser();
    out << " at " << time << " seconds" << endl;
}

void fifo::printStat(int totalJobs, int aggLatency, ostream& out) {
    out << endl << "\tTotal jobs: " << totalJobs << endl;
    out << "\tAggregate latency: " << aggLatency << endl;
    out << "\tMean latency: " << aggLatency / (double) totalJobs << endl;
}

string fifo::generateFileName(const string& fileName) {
    int dotPosition = fileName.find_last_of(".");

    if (dotPosition == string::npos) {
        return fileName + ".out";
    }

    return fileName.substr(0, dotPosition) + ".out";
}
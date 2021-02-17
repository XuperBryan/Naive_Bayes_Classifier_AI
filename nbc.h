#ifndef NBC_H
#define NBC_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <cmath>
using namespace std;


class NaiveBayes {
    public:
        // counts all of the variables
        void countAllVariables(string filename);
        void printInfo();
        // returns 0 if survived, returns 1 if dead
        bool willDie(int tubed, int age);

        // calculates all possibilities and prints 0 or 1
        void printAllTestCases(string filename);
        double checkTestCases(string filename);
    private:
        // d stands for dead
        // a stands for alive
        // 1 in place for 1
        // 2 in place for 2
        // 3 in place for unknown
        double ageBound = 50;
        double totalCount = 10;
        double dPercent = 0;
        double aPercent = 0;
        double tPercent = 0;
        double dCount = 5;
        double aCount = 5;        

        double dtubed1 = 1;
        double dtubed2 = 1;
        double dtubed3 = 1;
        double atubed1 = 1;
        double atubed2 = 1;
        double atubed3 = 1;

        double dbelowAge = 1;
        double abelowAge = 1;
        double daboveAge = 1;
        double aaboveAge = 1;

};


#endif
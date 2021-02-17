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

// age, 1.5, 50 = .8714
// age, 2.0, 50 = .8719
// age, 3.0, 50 = .8742
// age, 3.3, 50 = .8733
// age, 3.5, 50 = .8734
// age, 4.0, 50 = .8725
// diabete, 1.5 = .8703
// diabete, 2.0 = .8706
// diabete, 3.0 = .8711
// diabete, 4.0 = .8735
// diabete, 4.5 = .8734
// diabete, 5.0 = .8741
// diabete, 6.0 = .8719
// copd, 1.5 = .8700
// copd, 2.0 = .8702
// copd, 3.0 = .8700
// copd, 4.0 = .8700
// hyper, 1.2 = .8703
// hyper, 1.5 = .8704
// hyper, 2.0 = .8703
// cardio, 1.5 = .8701
// cardio, 2.0 = .8699
// obese, 1.5 = .8701
// obese, 2.0 = .8701
// obese, 3.0 = .8697
// renal, 1.5 = .8702
// renal, 2.0 = .8703
// renal, 2.5 = .8703
// renal, 3.0 = .8703
// renal, 4.0 = .8702
// tobacco --
// contact, 1.5 = .8708
// contact, 2.0 = .8705
// contact, 3.0 = .8685
// covres --
// icu --

// age = 3, diabete = 2: .8746
// age = 3, diabete = 3: .8753
// age = 3, diabete = 4: .8735
// age = 3, diabete = 5: .8680

// age = 2, diabete = 5: .8743
// age = 3, diabete = 5: .8680
// age = 4, diabete = 5: .8598

// ageBound = 45, age = 3, diabete = 3: .8753
// ageBound = 50, age = 3, diabete = 3: .8753
// ageBound = 60, age = 3, diabete = 3: .8753
// ageBound = 65, age = 3, diabete = 3: .8753

// age = 3, diabete = 3, contact = 1.5: .8752
// age = 3, diabete = 3, contact = 1.2: .8753

// age = 3, diabete = 3, !covres: .8705
// age = 3, diabete = 3, !icu: .8662
// age = 3, diabete = 3, !contact: .8730
// age = 3, diabete = 3, !tobacco: .8754
// age = 3, diabete = 3, !renal: .8753
// age = 3, diabete = 3, !obese: .8748
// age = 3, diabete = 3, !cardio: .8757
// age = 3, diabete = 3, !other: .8756
// age = 3, diabete = 3, !hyper: .8752
// age = 3, diabete = 3, !inmsupr: .8
// age = 3, diabete = 3, !cardio: .8
// age = 3, diabete = 3, !cardio: .8



class NaiveBayes {
    public:
        // counts all of the variables
        void countAllVariables(string filename);
        void printInfo();
        // returns 0 if survived, returns 1 if dead
        bool willDie(int sex, int type, int tubed, int pneumon, int age, int preg, int diabete, int copd, int asthma, int inmsupr, int hyper, int other, int cardio, int obese, int renal, int tobacco, int contact, int covres, int icu);

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
        double totalCount = 108;
        double dPercent = 0;
        double aPercent = 0;
        double tPercent = 0;
        double dCount = 54;
        double aCount = 54;

        double dsex1 = 1;
        double dsex2 = 1;
        double asex1 = 1;
        double asex2 = 1;

        double dtype1 = 1;
        double dtype2 = 1;
        double atype1 = 1;
        double atype2 = 1;

        double dtubed1 = 1;
        double dtubed2 = 1;
        double dtubed3 = 1;
        double atubed1 = 1;
        double atubed2 = 1;
        double atubed3 = 1;

        double dpneumon1 = 1;
        double dpneumon2 = 1;
        double dpneumon3 = 1;
        double apneumon1 = 1;
        double apneumon2 = 1;
        double apneumon3 = 1;

        double dbelowAge = 1;
        double abelowAge = 1;
        double daboveAge = 1;
        double aaboveAge = 1;

        double dpreg1 = 1;
        double dpreg2 = 1;
        double dpreg3 = 1;
        double apreg1 = 1;
        double apreg2 = 1;
        double apreg3 = 1;

        double ddiabete1 = 1;
        double ddiabete2 = 1;
        double ddiabete3 = 1;
        double adiabete1 = 1;
        double adiabete2 = 1;
        double adiabete3 = 1;

        double dcopd1 = 1;
        double dcopd2 = 1;
        double dcopd3 = 1;
        double acopd1 = 1;
        double acopd2 = 1;
        double acopd3 = 1;

        double dasthma1 = 1;
        double dasthma2 = 1;
        double dasthma3 = 1;
        double aasthma1 = 1;
        double aasthma2 = 1;
        double aasthma3 = 1;

        double dinmsupr1 = 1;
        double dinmsupr2 = 1;
        double dinmsupr3 = 1;
        double ainmsupr1 = 1;
        double ainmsupr2 = 1;
        double ainmsupr3 = 1;

        double dhyper1 = 1;
        double dhyper2 = 1;
        double dhyper3 = 1;
        double ahyper1 = 1;
        double ahyper2 = 1;
        double ahyper3 = 1;

        double dother1 = 1;
        double dother2 = 1;
        double dother3 = 1;
        double aother1 = 1;
        double aother2 = 1;
        double aother3 = 1;

        double dcardio1 = 1;
        double dcardio2 = 1;
        double dcardio3 = 1;
        double acardio1 = 1;
        double acardio2 = 1;
        double acardio3 = 1;

        double dobese1 = 1;
        double dobese2 = 1;
        double dobese3 = 1;
        double aobese1 = 1;
        double aobese2 = 1;
        double aobese3 = 1;

        double drenal1 = 1;
        double drenal2 = 1;
        double drenal3 = 1;
        double arenal1 = 1;
        double arenal2 = 1;
        double arenal3 = 1;

        double dtobacco1 = 1;
        double dtobacco2 = 1;
        double dtobacco3 = 1;
        double atobacco1 = 1;
        double atobacco2 = 1;
        double atobacco3 = 1;

        double dcontact1 = 1;
        double dcontact2 = 1;
        double dcontact3 = 1;
        double acontact1 = 1;
        double acontact2 = 1;
        double acontact3 = 1;

        double dcovres1 = 1;
        double dcovres2 = 1;
        double dcovres3 = 1;
        double acovres1 = 1;
        double acovres2 = 1;
        double acovres3 = 1;

        double dicu1 = 1;
        double dicu2 = 1;
        double dicu3 = 1;
        double aicu1 = 1;
        double aicu2 = 1;
        double aicu3 = 1;



};


#endif
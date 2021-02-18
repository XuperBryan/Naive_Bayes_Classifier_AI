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
// age = 3, diabete = 3, !inmsupr: .8755
// age = 3, diabete = 3, !asthma: .8755
// age = 3, diabete = 3, !copd: .8755
// age = 3, diabete = 3, !diabete: .8729
// age = 3, diabete = 3, !preg: .8752
// age = 3, diabete = 3, !age: .8654
// age = 3, diabete = 3, !pneumon: .8650
// age = 3, diabete = 3, !tubed: .8646
// age = 3, diabete = 3, !type: .8669
// age = 3, diabete = 3, !sex: .8750

// age = 3, diabete = 2, !cardio: .8743
// age = 3, diabete = 3, !cardio: .8757
// age = 3, diabete = 4, !cardio: .8737
// age = 3, diabete = 5, !cardio: .8689

// age = 2, diabete = 3, !cardio: .8752
// age = 3, diabete = 3, !cardio: .8757
// age = 4, diabete = 3, !cardio: .8689
// age = 5, diabete = 3, !cardio: .8643

// age = 3, diabete = 3, !cardio, !other: .8758
// age = 3, diabete = 3, !cardio, !inmsupr: .8755
// age = 3, diabete = 3, !cardio, !asthma: .8757
// age = 3, diabete = 3, !cardio, !copd: .8758
// age = 3, diabete = 3, !cardio, !copd, !other: .8757
// age = 3, diabete = 3, !cardio, !copd, !asthma: .8758

// age = 3, diabete = 3, !cardio, !copd, !asthma, contact = 1.5: .8756
// age = 3, diabete = 3, !cardio, !copd, !asthma, contact = 1.75: .8759
// age = 3, diabete = 3, !cardio, !copd, !asthma, contact = 2.0: .8759
// age = 3, diabete = 3, !cardio, !copd, !asthma, contact = 2.5: .8752
// age = 3, diabete = 3, !cardio, !copd, !asthma, contact = 3.0: .8753

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex1.5: .8754
// age3, diabete3, !cardio, !copd, !asthma, contact2, !sex: .8757
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.5: .8758
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25: .8759
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.15: .8757

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type: .8759
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, type1.5: .8749
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, type0.5: .8742

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, !tubed: .8585
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed1.5: .8749
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed0.5: .8645
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2: .8768
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.1: .8769
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.25: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.3: .8769
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.5: .8758
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed3: .8729

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, !pneumon: .8700
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, pneumon1.5: .8766
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, pneumon0.5: .8744
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, pneumon2: .8759

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, !preg: .8765
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, preg0.5: .8766
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, preg1.2: .8769
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, preg1.5: .8771
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, preg2: .8765
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, preg3: .8761

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, !inmsupr: .8771
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr0.5: .8771
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25: .8773
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.5: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr2: .8770

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !hyper: .8760
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper0.5: .8767
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper0.75: .8771
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper0.85: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper0.925: .8772
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper1.25: .8769
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper1.5: .8762
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, hyper3: .8744

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25: .8773
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other: .8774
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, other0.25: .8773
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, other0.5: .8773
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, other1.5: .8770

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other: .8774
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, !obese: .8765
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese0.5: .8771
//  obese1.25: .8774
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5: .8775
//  obese1.65: .8775
//  obese1.75: .8775
// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese2: .8771

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5: .8775
// !renal: .8773
// renal0.5: .87758
// renal0.75: .87755
// renal: .877553
// renal1.5: .8771

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5: .87758
// !tobacco: .87758
// tobacco0.5: .87760
// tobacco1.25: .87755
// tobacco1.5: .87763
// tobacco1.65: .87763
// tobacco1.75: .87763
// tobacco2: .87753

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5: .87763
// !covres: .87493
// covres0.5: .87598
// covres1.5: .87709
// covres2: .87722
// covres2.5: .877555
// covres2.9: .87801
// covres3: .87813
// covres3.1: .87808
// covres3.25: .87760
// covres3.5: .87753
// covres4: .87676


// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3: .87813

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3: .87813

// !pneumon: .8729
// pneumon0.5: .878139  
// pneumon1: .878131  
// pneumon1.25: .878317 
// pneumon1.5: .879333
// pneumon1.75: .878774
// pneumon2: .878927
// pneumon3: .876590

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3, pneumon1.5: .879333

// !preg: .878952
// preg.5; .879028
// preg.75: .878977
// preg1.5: .878927
// preg2: .878723

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3, pneumon1.5: .879333

// !hyper: .879333
// hyper0.5: .878901
// hyper1.5: .878622
// hyper2: .878495


// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3, pneumon1.5, !hyper: .879333

// !icu: .877352
// icu0.25: .878901
// icu0.5: .879358
// icu.65: .878647
// icu.75: .880044
// icu1.5: .876920

// age3, diabete3, !cardio, !copd, !asthma, contact2, sex0.25, !type, tubed2.2, inmsupr1.25, !other, obese1.5, renal0.5, tobacco1.5, covres3, pneumon1.5, !hyper, icu.75: .880044

// !preg: .880044
// -preg: .879308
// preg0.5: .879460



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
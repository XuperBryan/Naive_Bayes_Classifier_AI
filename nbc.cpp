#include "naivebayesclassifier.h"

void NaiveBayes::countAllVariables(string filename){
    ifstream myFile(filename);
    if(!myFile.is_open()){
        throw runtime_error("Could not open file");
    }

    string line = "";
    string colname = "";
    string value = "";

    if(myFile.good()){
        getline(myFile, line);
        stringstream ss(line);

        while(getline(ss, colname, ',')){
        }
    }

    while(getline(myFile, line)){
        stringstream ss(line);
        int index = 0;
        bool dead;
        bool sex1;
        bool type1;
        while(getline(ss, value, ',')){
            // puts input into value
            switch(index){
                case 0: // sex
                // haven't checked if alive or dead yet, will need to retroactively check after index 5
                    if(stoi(value)==1){
                        dsex1++;
                        asex1++;
                        sex1 = true;
                    } else if(stoi(value)==2){
                        dsex2++;
                        asex2++;
                        sex1 = false;
                    } else {
                        cout << "weird case happened for sex\n";
                    }
                    break;
                case 1: // type
                    if(stoi(value)==1){
                        dtype1++;
                        atype1++;
                        type1 = true;
                    } else if(stoi(value)==2){
                        dtype2++;
                        atype2++;
                        type1 = false;
                    } else {
                        cout << "weird case happened for type\n";
                    }
                    break;
                case 2: // entry date
                    break;
                case 3: // date symptoms
                    break;
                case 4: // date died
                // case for alive patient
                totalCount++;
                tPercent++;
                    if(value.compare("9999-99-99") == 0){
                        aCount++;
                        dead = false;
                        aPercent++;
                        if(sex1==true){
                            dsex1--;
                        } else if(sex1==false){
                            dsex2--;
                        }

                        if(type1==true){
                            dtype1--;
                        } else if(type1==false){
                            dtype2--;
                        }
                    } else {    // case for dead patient
                        dCount++;
                        dead = true;
                        dPercent++;
                        if(sex1==true){
                            asex1--;
                        } else if(sex1==false){
                            asex2--;
                        }

                        if(type1==true){
                            atype1--;
                        } else if(type1==false){
                            atype2--;
                        }
                    }
                    break;
                case 5: // intubed
                    if(dead==true){
                        if(stoi(value)==1){
                            dtubed1++;
                        } else if(stoi(value)==2){
                            dtubed2++;
                        } else {
                            dtubed3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            atubed1++;
                        } else if(stoi(value)==2){
                            atubed2++;
                        } else {
                            atubed3++;
                        }
                    }
                    break;
                case 6: // pneumonia
                    if(dead==true){
                        if(stoi(value)==1){
                            dpneumon1++;
                        } else if(stoi(value)==2){
                            dpneumon2++;
                        } else {
                            dpneumon3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            apneumon1++;
                        } else if(stoi(value)==2){
                            apneumon2++;
                        } else {
                            apneumon3++;
                        }
                    }
                    break;
                case 7: // age case
                    if(dead==true){
                        if(stoi(value) <= ageBound){
                            dbelowAge++;
                        } else {
                            daboveAge++;
                        }
                    } else {    // alive cases
                        if(stoi(value) <= ageBound){
                            abelowAge++;
                        } else {
                            aaboveAge++;
                        }
                    }
                    break;
                case 8: // pregnancy
                    if(dead==true){
                        if(stoi(value)==1){
                            dpreg1++;
                        } else if(stoi(value)==2){
                            dpreg2++;
                        } else {
                            dpreg3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            apreg1++;
                        } else if(stoi(value)==2){
                            apreg2++;
                        } else {
                            apreg3++;
                        }
                    }
                    break;
                case 9: // diabetes
                    if(dead==true){
                        if(stoi(value)==1){
                            ddiabete1++;
                        } else if(stoi(value)==2){
                            ddiabete2++;
                        } else {
                            ddiabete3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            adiabete1++;
                        } else if(stoi(value)==2){
                            adiabete2++;
                        } else {
                            adiabete3++;
                        }
                    }
                    break;
                case 10: // copd
                    if(dead==true){
                        if(stoi(value)==1){
                            dcopd1++;
                        } else if(stoi(value)==2){
                            dcopd2++;
                        } else {
                            dcopd3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            acopd1++;
                        } else if(stoi(value)==2){
                            acopd2++;
                        } else {
                            acopd3++;
                        }
                    }
                    break; 
                case 11: // asthma
                    if(dead==true){
                        if(stoi(value)==1){
                            dasthma1++;
                        } else if(stoi(value)==2){
                            dasthma2++;
                        } else {
                            dasthma3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            aasthma1++;
                        } else if(stoi(value)==2){
                            aasthma2++;
                        } else {
                            aasthma3++;
                        }
                    }
                    break; 
                case 12: // inmsupr
                    if(dead==true){
                        if(stoi(value)==1){
                            dinmsupr1++;
                        } else if(stoi(value)==2){
                            dinmsupr2++;
                        } else {
                            dinmsupr3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            ainmsupr1++;
                        } else if(stoi(value)==2){
                            ainmsupr2++;
                        } else {
                            ainmsupr3++;
                        }
                    }
                    break; 
                case 13: // hypertension
                    if(dead==true){
                        if(stoi(value)==1){
                            dhyper1++;
                        } else if(stoi(value)==2){
                            dhyper2++;
                        } else {
                            dhyper3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            ahyper1++;
                        } else if(stoi(value)==2){
                            ahyper2++;
                        } else {
                            ahyper3++;
                        }
                    }
                    break; 
                case 14: // other
                    if(dead==true){
                        if(stoi(value)==1){
                            dother1++;
                        } else if(stoi(value)==2){
                            dother2++;
                        } else {
                            dother3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            aother1++;
                        } else if(stoi(value)==2){
                            aother2++;
                        } else {
                            aother3++;
                        }
                    }
                    break; 
                case 15: // cardio
                    if(dead==true){
                        if(stoi(value)==1){
                            dcardio1++;
                        } else if(stoi(value)==2){
                            dcardio2++;
                        } else {
                            dcardio3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            acardio1++;
                        } else if(stoi(value)==2){
                            acardio2++;
                        } else {
                            acardio3++;
                        }
                    }
                    break; 
                case 16: // obesity
                    if(dead==true){
                        if(stoi(value)==1){
                            dobese1++;
                        } else if(stoi(value)==2){
                            dobese2++;
                        } else {
                            dobese3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            aobese1++;
                        } else if(stoi(value)==2){
                            aobese2++;
                        } else {
                            aobese3++;
                        }
                    }
                    break; 
                case 17: // renal
                    if(dead==true){
                        if(stoi(value)==1){
                            drenal1++;
                        } else if(stoi(value)==2){
                            drenal2++;
                        } else {
                            drenal3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            arenal1++;
                        } else if(stoi(value)==2){
                            arenal2++;
                        } else {
                            arenal3++;
                        }
                    }
                    break; 
                case 18: // tobacco
                    if(dead==true){
                        if(stoi(value)==1){
                            dtobacco1++;
                        } else if(stoi(value)==2){
                            dtobacco2++;
                        } else {
                            dtobacco3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            atobacco1++;
                        } else if(stoi(value)==2){
                            atobacco2++;
                        } else {
                            atobacco3++;
                        }
                    }
                    break; 
                case 19: // contact
                    if(dead==true){
                        if(stoi(value)==1){
                            dcontact1++;
                        } else if(stoi(value)==2){
                            dcontact2++;
                        } else {
                            dcontact3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            acontact1++;
                        } else if(stoi(value)==2){
                            acontact2++;
                        } else {
                            acontact3++;
                        }
                    }
                    break; 
                case 20: // cov res
                    if(dead==true){
                        if(stoi(value)==1){
                            dcovres1++;
                        } else if(stoi(value)==2){
                            dcovres2++;
                        } else {
                            dcovres3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            acovres1++;
                        } else if(stoi(value)==2){
                            acovres2++;
                        } else {
                            acovres3++;
                        }
                    }
                    break; 
                case 21: // icu
                    if(dead==true){
                        if(stoi(value)==1){
                            dicu1++;
                        } else if(stoi(value)==2){
                            dicu2++;
                        } else {
                            dicu3++;
                        }
                    } else {    // alive cases
                        if(stoi(value)==1){
                            aicu1++;
                        } else if(stoi(value)==2){
                            aicu2++;
                        } else {
                            aicu3++;
                        }
                    }
                    break; 
                default:
                    break; 
            }
            index++;        
        
        }
    }   
    myFile.close();
}

bool NaiveBayes::willDie(int sex, int type, int tubed, int pneumon, int age, int preg, int diabete, int copd, int asthma, int inmsupr, int hyper, int other, int cardio, int obese, int renal, int tobacco, int contact, int covres, int icu){
    double probDie = 1;
    double probLive = 1;

    probDie+=log(dPercent/tPercent);
    probLive+=log(aPercent/tPercent);

    if(sex==1){
        probDie+=log(dsex1/dCount);
        probLive+=log(asex1/aCount);
    } else if(sex==2){
        probDie+=log(dsex2/dCount);
        probLive+=log(asex2/aCount);
    } 

    if(type==1){
        probDie+=log(dtype1/dCount);
        probLive+=log(atype1/aCount);
    } else if(type==2){
        probDie+=log(dtype2/dCount);
        probLive+=log(atype2/aCount);
    } 

    if(tubed==1){
        probDie+=2*log(dtubed1/dCount);
        probLive+=2*log(atubed1/aCount);
    } else if(tubed==2){
        probDie+=2*log(dtubed2/dCount);
        probLive+=2*log(atubed2/aCount);
    } else {
        probDie+=2*log(dtubed3/dCount);
        probLive+=2*log(atubed3/aCount);
    }

    if(pneumon==1){
        probDie+=log(dpneumon1/dCount);
        probLive+=log(apneumon1/aCount);
    } else if(pneumon==2){
        probDie+=log(dpneumon2/dCount);
        probLive+=log(apneumon2/aCount);
    } else {
        probDie+=log(dpneumon3/dCount);
        probLive+=log(apneumon3/aCount);
    }
    
    if(age <= ageBound){
        probDie+=2*log(dbelowAge/dCount);
        probLive+=2*log(abelowAge/aCount);
    } else {
        probDie+=2*log(daboveAge/dCount);
        probLive+=2*log(aaboveAge/aCount);
    }

    if(preg==1){
        probDie+=log(dpreg1/dCount);
        probLive+=log(apreg1/aCount);
    } else if(preg==2){
        probDie+=log(dpreg2/dCount);
        probLive+=log(apreg2/aCount);
    } else {
        probDie+=log(dpreg3/dCount);
        probLive+=log(apreg3/aCount);
    }
    
    if(diabete==1){
        probDie+=log(ddiabete1/dCount);
        probLive+=log(adiabete1/aCount);
    } else if(diabete==2){
        probDie+=log(ddiabete2/dCount);
        probLive+=log(adiabete2/aCount);
    } else {
        probDie+=log(ddiabete3/dCount);
        probLive+=log(adiabete3/aCount);
    }
    
    if(copd==1){
        probDie+=log(dcopd1/dCount);
        probLive+=log(acopd1/aCount);
    } else if(copd==2){
        probDie+=log(dcopd2/dCount);
        probLive+=log(acopd2/aCount);
    } else {
        probDie+=log(dcopd3/dCount);
        probLive+=log(acopd3/aCount);
    }

    if(asthma==1){
        probDie+=log(dasthma1/dCount);
        probLive+=log(aasthma1/aCount);
    } else if(asthma==2){
        probDie+=log(dasthma2/dCount);
        probLive+=log(aasthma2/aCount);
    } else {
        probDie+=log(dasthma3/dCount);
        probLive+=log(aasthma3/aCount);
    }
    
    if(inmsupr==1){
        probDie+=log(dinmsupr1/dCount);
        probLive+=log(ainmsupr1/aCount);
    } else if(inmsupr==2){
        probDie+=log(dinmsupr2/dCount);
        probLive+=log(ainmsupr2/aCount);
    } else {
        probDie+=log(dinmsupr3/dCount);
        probLive+=log(ainmsupr3/aCount);
    }
    
    if(hyper==1){
        probDie+=log(dhyper1/dCount);
        probLive+=log(ahyper1/aCount);
    } else if(hyper==2){
        probDie+=log(dhyper2/dCount);
        probLive+=log(ahyper2/aCount);
    } else {
        probDie+=log(dhyper3/dCount);
        probLive+=log(ahyper3/aCount);
    }
    
    if(other==1){
        probDie+=log(dother1/dCount);
        probLive+=log(aother1/aCount);
    } else if(other==2){
        probDie+=log(dother2/dCount);
        probLive+=log(aother2/aCount);
    } else {
        probDie+=log(dother3/dCount);
        probLive+=log(aother3/aCount);
    }
    
    if(cardio==1){
        probDie+=log(dcardio1/dCount);
        probLive+=log(acardio1/aCount);
    } else if(cardio==2){
        probDie+=log(dcardio2/dCount);
        probLive+=log(acardio2/aCount);
    } else {
        probDie+=log(dcardio3/dCount);
        probLive+=log(acardio3/aCount);
    }
    
    if(obese==1){
        probDie+=log(dobese1/dCount);
        probLive+=log(aobese1/aCount);
    } else if(obese==2){
        probDie+=log(dobese2/dCount);
        probLive+=log(aobese2/aCount);
    } else {
        probDie+=log(dobese3/dCount);
        probLive+=log(aobese3/aCount);
    }
    
    if(renal==1){
        probDie+=log(drenal1/dCount);
        probLive+=log(arenal1/aCount);
    } else if(renal==2){
        probDie+=log(drenal2/dCount);
        probLive+=log(arenal2/aCount);
    } else {
        probDie+=log(drenal3/dCount);
        probLive+=log(arenal3/aCount);
    }
    
    if(tobacco==1){
        probDie+=log(dtobacco1/dCount);
        probLive+=log(atobacco1/aCount);
    } else if(tobacco==2){
        probDie+=log(dtobacco2/dCount);
        probLive+=log(atobacco2/aCount);
    } else {
        probDie+=log(dtobacco3/dCount);
        probLive+=log(atobacco3/aCount);
    }
    
    
    if(contact==1){
        probDie+=log(dcontact1/dCount);
        probLive+=log(acontact1/aCount);
    } else if(contact==2){
        probDie+=log(dcontact2/dCount);
        probLive+=log(acontact2/aCount);
    } else {
        probDie+=log(dcontact3/dCount);
        probLive+=log(acontact3/aCount);
    }
    
    if(covres==1){
        probDie+=log(dcovres1/dCount);
        probLive+=log(acovres1/aCount);
    } else if(covres==2){
        probDie+=log(dcovres2/dCount);
        probLive+=log(acovres2/aCount);
    } else {
        probDie+=log(dcovres3/dCount);
        probLive+=log(acovres3/aCount);
    }
    
    if(icu==1){
        probDie+=log(dicu1/dCount);
        probLive+=log(aicu1/aCount);
    } else if(icu==2){
        probDie+=log(dicu2/dCount);
        probLive+=log(aicu2/aCount);
    } else {
        probDie+=log(dicu3/dCount);
        probLive+=log(aicu3/aCount);
    }
    
    // cout << "probDie = " << probDie << ",probLive = " << probLive << endl;
    if(probDie > probLive){
        return true;
    } else if(probDie < probLive){
        return false;
    } else {
        return true;
    }
}

void NaiveBayes::printAllTestCases(string filename){
    ifstream myFile(filename);
    if(!myFile.is_open()){
        throw runtime_error("Could not open file");
    }

    string line = "";
    string colname = "";
    string value = "";

    if(myFile.good()){
        getline(myFile, line);
        stringstream ss(line);

        while(getline(ss, colname, ',')){
        }
    }

    while(getline(myFile, line)){
        stringstream ss(line);
        int index = 0;
        int sex;
        int type;
        int tubed;
        int pneumon;
        int age;
        int preg;
        int diabete;
        int copd;
        int asthma;
        int inmsupr;
        int hyper;
        int other;
        int cardio;
        int obese;
        int renal;
        int tobacco;
        int contact;
        int covres;
        int icu;

        while(getline(ss, value, ',')){
            switch (index)  {
                case 0:
                    sex = stoi(value);
                    break;
                case 1:
                    type = stoi(value);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    tubed = stoi(value);
                    break;
                case 6:
                    pneumon = stoi(value);
                    break;
                case 7:
                    age = stoi(value);
                    break;
                case 8:
                    preg = stoi(value);
                    break;
                case 9:
                    diabete = stoi(value);
                    break;
                case 10:
                    copd = stoi(value);
                    break;
                case 11:
                    asthma = stoi(value);
                    break;
                case 12:
                    inmsupr = stoi(value);
                    break;
                case 13:
                    hyper = stoi(value);
                    break;
                case 14:
                    other = stoi(value);
                    break;
                case 15:
                    cardio = stoi(value);
                    break;
                case 16:
                    obese = stoi(value);
                    break;
                case 17:
                    renal = stoi(value);
                    break;
                case 18:
                    tobacco = stoi(value);
                    break;
                case 19:
                    contact = stoi(value);
                    break;
                case 20:
                    covres = stoi(value);
                    break;
                case 21:
                    icu = stoi(value);
                    break;
                default:
                    break;
            }
            index++;
        }
        cout << willDie(sex, type, tubed, pneumon, age, preg, diabete, copd, asthma, inmsupr, hyper, other, cardio, obese, renal, tobacco, contact, covres, icu) << endl;

    }
    myFile.close();
}

double NaiveBayes::checkTestCases(string filename){
    ifstream myFile(filename);
    if(!myFile.is_open()){
        throw runtime_error("Could not open file");
    }

    string line = "";
    string colname = "";
    string value = "";

    if(myFile.good()){
        getline(myFile, line);
        stringstream ss(line);

        while(getline(ss, colname, ',')){
        }
    }

    double correct = 0;
    double total = 0;
    while(getline(myFile, line)){
        stringstream ss(line);
        int index = 0;
        bool dead;
        int sex;
        int type;
        int tubed;
        int pneumon;
        int age;
        int preg;
        int diabete;
        int copd;
        int asthma;
        int inmsupr;
        int hyper;
        int other;
        int cardio;
        int obese;
        int renal;
        int tobacco;
        int contact;
        int covres;
        int icu;

        while(getline(ss, value, ',')){
            switch (index)  {
                case 0:
                    sex = stoi(value);
                    break;
                case 1:
                    type = stoi(value);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    if(value.compare("9999-99-99") == 0){
                        bool dead = false;
                    } else {
                        bool dead = true;
                    }
                    break;
                case 5:
                    tubed = stoi(value);
                    break;
                case 6:
                    pneumon = stoi(value);
                    break;
                case 7:
                    age = stoi(value);
                    break;
                case 8:
                    preg = stoi(value);
                    break;
                case 9:
                    diabete = stoi(value);
                    break;
                case 10:
                    copd = stoi(value);
                    break;
                case 11:
                    asthma = stoi(value);
                    break;
                case 12:
                    inmsupr = stoi(value);
                    break;
                case 13:
                    hyper = stoi(value);
                    break;
                case 14:
                    other = stoi(value);
                    break;
                case 15:
                    cardio = stoi(value);
                    break;
                case 16:
                    obese = stoi(value);
                    break;
                case 17:
                    renal = stoi(value);
                    break;
                case 18:
                    tobacco = stoi(value);
                    break;
                case 19:
                    contact = stoi(value);
                    break;
                case 20:
                    covres = stoi(value);
                    break;
                case 21:
                    icu = stoi(value);
                    break;
                default:
                    break;
            }
            index++;
        }
        if(dead != willDie(sex, type, tubed, pneumon, age, preg, diabete, copd, asthma, inmsupr, hyper, other, cardio, obese, renal, tobacco, contact, covres, icu)){
            correct++;
        }
        total++;

    }
    cout << "Percentage correct: " << correct/total << endl;
    cout << "Number correct: " << correct << endl;
    cout << "Number checked: " << total << endl;
    myFile.close();
}

void NaiveBayes::printInfo(){
    cout << "dCount: " << dCount << endl;
    cout << "aCount: " << aCount << endl;
    cout << "totalCount: " << totalCount << endl << endl; 
    cout << "dPercent: " << dPercent << endl;
    cout << "aPercent: " << aPercent << endl;
    cout << "tPercent: " << tPercent << endl;
}

int main(int argc, char* argv[]){
    string trainingData = argv[1];
    string testingData = argv[2];

    NaiveBayes nb = NaiveBayes();
    nb.countAllVariables(trainingData);
    //nb.printInfo();
    nb.printAllTestCases(testingData);
    // nb.checkTestCases(testingData);
    return 0;
}
#include "nbc.h"

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
                    break;
                case 1: // type
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
                    } else {    // case for dead patient
                        dCount++;
                        dead = true;
                        dPercent++;
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
                    break;
                case 9: // diabetes
                    break;
                case 10: // copd
                    break; 
                case 11: // asthma
                    break; 
                case 12: // inmsupr
                    break; 
                case 13: // hypertension
                    break; 
                case 14: // other
                    break; 
                case 15: // cardio
                    break; 
                case 16: // obesity
                    break; 
                case 17: // renal
                    break; 
                case 18: // tobacco
                    break; 
                case 19: // contact
                    break; 
                case 20: // cov res
                    break; 
                case 21: // icu
                    break; 
                default:
                    cout << "You messed up somewhere, and ended up in the default case" << endl;
                    break; 
            }
            index++;        
        
        }
    }   
    myFile.close();
}

bool NaiveBayes::willDie(int tubed, int age){
    double probDie = 1;
    double probLive = 1;

    probDie+=log(dPercent/tPercent);
    probLive+=log(aPercent/tPercent);

    if(tubed==1){
        probDie+=log(dtubed1/dCount);
        probLive+=log(atubed1/aCount);
    } else if(tubed==2){
        probDie+=log(dtubed2/dCount);
        probLive+=log(atubed2/aCount);
    } else {
        probDie+=log(dtubed3/dCount);
        probLive+=log(atubed3/aCount);
    }

    if(age <= ageBound){
        probDie+=log(dbelowAge/dCount);
        probLive+=log(abelowAge/aCount);
    } else {
        probDie+=log(daboveAge/dCount);
        probLive+=log(aaboveAge/aCount);
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
        int tubed;
        int age;

        while(getline(ss, value, ',')){
            switch (index)  {
                case 0:
                    break;
                case 1:
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
                    break;
                case 7:
                    age = stoi(value);
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 14:
                    break;
                case 15:
                    break;
                case 16:
                    break;
                case 17:
                    break;
                case 18:
                    break;
                case 19:
                    break;
                case 20:
                    break;
                case 21:
                    break;
                default:
                    cout << "Messed up somewhere in the test calculations\n"; 
                    break;
            }
            index++;
        }
        cout << willDie(tubed, age) << endl;
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
        int tubed;
        int age;

        while(getline(ss, value, ',')){
            switch (index)  {
                case 0:
                    break;
                case 1:
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
                    break;
                case 7:
                    age = stoi(value);
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 14:
                    break;
                case 15:
                    break;
                case 16:
                    break;
                case 17:
                    break;
                case 18:
                    break;
                case 19:
                    break;
                case 20:
                    break;
                case 21:
                    break;
                default:
                    cout << "Messed up somewhere in the test calculations\n"; 
                    break;
            }
            index++;
        }
        if(dead != willDie(tubed, age)){
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
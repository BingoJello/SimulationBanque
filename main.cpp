// main function
#include <iostream>
#include <string.h>
#include "header/Bank.h"
using namespace std;
#include "header/SimulationUtility.h"


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
    return true;
}


int main(int argc, char ** argv) {
    SimulationUtility::init();
    double* averageServiceTimes = new double[3];
    SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, 3);

    Bank *b = new Bank(30.0, 3, 2, averageServiceTimes);
    b->startSimulation();
    return 0;

    int nbCashier = 3;
    double dureeSimulation = 40.0;
    double timeBetweenArrivals = 5.0;
    int averageServiceTime = 3;

    int i=1;
    if(argc>1){
       
        int i, x;
        int ch = 0;
        for (i=1; i<argc; i++) {
            for (x = 0; x < strlen(argv[i]); x++) {
                ch = argv[i][x];
                if (ch == 'h'){
                    cout << "-h : help\n" << endl;
                    cout << "-C <nbCashier> : Entrer le nombre de Cashier" << endl;
                    cout << "-S <dureeSimulation> : Entrer la durée de la simulation" << endl;
                    cout << "-A <timeBetweenArrivals> : Entrer le temps entre les arrivées" << endl;
                    cout << "-T <averageServiceTime> : Entrer le temps moyen entre les arriveées" << endl;
                    exit(0);
                }
                else if (ch == 'C'){
                    if (check_number(argv[i+1]))
                        nbCashier = atoi(argv[i+1]);
                }
                else if (ch == 'S'){
                    if (check_number(argv[i+1]))
                        dureeSimulation = atoi(argv[i+1]);
                }
                else if (ch == 'T'){
                    if (check_number(argv[i+1]))
                        timeBetweenArrivals = atoi(argv[i+1]);
                }
                else if (ch == 'A'){
                    if (check_number(argv[i+1]))
                        averageServiceTime = atoi(argv[i+1]);
                }else{
                    cerr << "Wrong paramètre" << endl;
                }

            }
        }
    }else{
        cerr << "Pas d'argument ajouter\n";
    }

    cout << "nC <nbCashier> : Entrer le nombre de Cashier: " << nbCashier
     << "\n dS <dureeSimulation> : Entrer la duree de la simulation: " << dureeSimulation
     << "\n tBA <timeBetweenArrivals> : Entrer le temps entre les arrivees: " << timeBetweenArrivals
     << "\n aST <averageServiceTime> : Entrer le temps moyen entre les arrivees: " << averageServiceTime;

    SimulationUtility::init();
    double* averageServiceTimes = new double[averageServiceTime];
    SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, 3);

    Bank *b = new Bank(dureeSimulation, nbCashier, timeBetweenArrivals, averageServiceTimes);
    b->startSimulation();
    
    return 0;
}



/*
int main() {
    SimulationUtility::init();
    double* averageServiceTimes = new double[3];
    SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, 3);

    Bank *b = new Bank(30.0, 3, 2, averageServiceTimes);
    b->startSimulation();
    return 0;
}
*/

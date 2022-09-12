// main function
#include <iostream>
#include <string.h>
#include "header/Bank.h"
using namespace std;

int main(int argc, char ** argv) {
   
    int nbCashier = 3;
    double dureeSimulation = 20.0;
    double timeBetweenArrivals = 5.0;
    double averageServiceTime = 3.0;

    if(argc>1){
        if(strcmp(argv[1],"h")==0){
            cout << "h : help\n" << endl;
            cout << "nC <nbCashier> : Entrer le nombre de Cashier" << endl;
            cout << "tBA <timeBetweenArrivals> : Entrer le temps entre les arrivées" << endl;
            cout << "aST <averageServiceTime> : Entrer le temps moyen entre les arriveées" << endl;
        }
    }
    else if(argc>=3){
        
    }

    return 0;


}

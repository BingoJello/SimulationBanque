// main function
#include <iostream>
#include <string.h>
#include "header/Bank.h"
using namespace std;


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
    return true;
}

int main(int argc, char ** argv) {
   
    int nbCashier = 3;
    double dureeSimulation = 20.0;
    double timeBetweenArrivals = 5.0;
    double averageServiceTime = 3.0;

    int i=1;
    if(argc>1){
       
       
        int i, x;
        int ch = 0;
        for (i=1; i<argc; i++) {
            for (x = 0; x < strlen(argv[i]); x++) {
                ch = argv[i][x];
                if (ch == 'h'){
                    cout << "-h : help\n" << endl;
                    cout << "-nC <nbCashier> : Entrer le nombre de Cashier" << endl;
                    cout << "-dS <dureeSimulation> : Entrer la durée de la simulation" << endl;
                    cout << "-tBA <timeBetweenArrivals> : Entrer le temps entre les arrivées" << endl;
                    cout << "-aST <averageServiceTime> : Entrer le temps moyen entre les arriveées" << endl;
                    exit(0);
                }
                else if (ch == 'C'){
                    nbCashier = atoi(argv[i+1]);
                }
                else if (ch == 'S'){
                    dureeSimulation = atoi(argv[i+1]);
                }
                else if (ch == 'T'){
                    timeBetweenArrivals = atoi(argv[i+1]);
                }
                else if (ch == 'A'){
                    averageServiceTime = atoi(argv[i+1]);
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


    
    return 0;
}

/*
int main() {
    Bank *b = new Bank(10.0, 3, 0.6, 1.0);
    b->run();
    std::cout << "Hello, World!" << std::endl;
    return 0;


}
*/

// main function
#include <iostream>
#include <string.h>
#include <set>
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

    int nbCashier = 3;
    double dureeSimulation = 40.0;
    double timeBetweenArrivals = 5.0;
    int averageServiceTime = 3;

    set<char> setArgument;

    int i=1;
    if(argc>1){
       
        int i, x;
        int ch = 0;
        for (i=1; i<argc; i++) {
            for (x = 0; x < strlen(argv[i]); x++) {
                ch = argv[i][x];
                if (setArgument.count(ch) || argc > 9){
                    cerr << "Argument invalid\n";
                    exit(1);
                }
                else{
                    if (ch == 'h'){
                    setArgument.insert('h');
                    cout << "-h : help\n" << endl;
                    cout << "-C <nbCashier> : Entrer le nombre de Cashier" << endl;
                    cout << "-S <dureeSimulation> : Entrer la durée de la simulation" << endl;
                    cout << "-A <timeBetweenArrivals> : Entrer le temps entre les arrivées" << endl;
                    cout << "-T <averageServiceTime> : Entrer le temps moyen entre les arriveées" << endl;
                    exit(0);
                    }
                    else if (ch == 'C'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('C');
                            nbCashier = atoi(argv[i+1]);
                        }else{
                            cerr << "Argument invalid\n";
                            exit(1);
                        }
                       
                    }
                    else if (ch == 'S'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('S');
                            dureeSimulation = atoi(argv[i+1]);
                        }else{
                            cerr << "Argument invalid\n";
                            exit(1);
                        }
                        
                    }
                    else if (ch == 'T'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('T');
                            timeBetweenArrivals = atoi(argv[i+1]);
                        }else{
                            cerr << "Argument invalid\n";
                            exit(1);
                        }
                        
                    }
                    else if (ch == 'A'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('A');
                            averageServiceTime = atoi(argv[i+1]);
                        }else{
                            cerr << "Argument invalid\n";
                            exit(1);
                        }
                        
                    }
                }
                

            }
        }
    }else{
        cerr << "Pas d'argument ajouter\n\n";
    }
    cout << "################## Liste de parametres d'entres ######################\n"
        << "\n C <nbCashier> : Entrer le nombre de Cashier: " << nbCashier << "s"
        << "\n S <dureeSimulation> : Entrer la duree de la simulation: " << dureeSimulation << "s"
        << "\n A <timeBetweenArrivals> : Entrer le temps entre les arrivees: " << timeBetweenArrivals << "s"
        << "\n T <averageServiceTime> : Entrer le temps moyen entre les arrivees: " << averageServiceTime << "s"
        << "\n\n"
        << "###################### Debut de la Simulation ##################\n\n";

    SimulationUtility::init();
    double* averageServiceTimes = new double[averageServiceTime];
    SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, 3);

    Bank *b = new Bank(dureeSimulation, nbCashier, timeBetweenArrivals, averageServiceTimes);
    b->startSimulation();
    
    return 0;
}

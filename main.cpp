// main function
#include <iostream>
#include <string.h>
#include <set>
#include "header/Bank.h"
using namespace std;
#include "header/SimulationUtility.h"


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false && str[i] != '.')
      return false;
    return true;
}

int main(int argc, char ** argv) {

    int nbCashier = 3;
    double dureeSimulation = 100.0;
    double timeBetweenArrivals = 5.0;
    int averageServiceTime = -1;

    set<char> setArgument;

    if(argc>1){
        int ch = 0;
        for (int i=1; i<argc; i++) {
            for (int j = 0; j < strlen(argv[i]); j++) {
                ch = argv[i][j];
                if (setArgument.count(ch) || argc > 9){
                    cerr << "Argument invalide\n";
                    exit(1);
                }
                else{
                    if (ch == 'h'){
                        setArgument.insert('h');
                        cout << "-h : help\n"
                             << "-s <dureeSimulation> : Entrez la durée de la simulation \n"
                             << "-c <nbCaissier> : Entrez le nombre de caissier \n"
                             << "-a <timeBetweenArrivals> : Entrez le temps moyen de service des caissiers \n"
                             << "-t <averageServiceTime> : Entrez l'intervalle de temps moyen d'arrivée des clients \n";
                        exit(0);
                    }
                    else if (ch == 'c'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('c');
                            nbCashier = atof(argv[i+1]);
                        }else{
                            cerr << "Argument invalide : Vérifier que la valeur est bien un nombre et supérieur à 0\n";
                            exit(1);
                        }

                    }
                    else if (ch == 's'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('s');
                            dureeSimulation = atof(argv[i+1]);
                        }else{
                            cerr << "Argument invalide : Vérifier que la valeur est bien un nombre et supérieur à 0\n";
                            exit(1);
                        }

                    }
                    else if (ch == 't'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('t');
                            timeBetweenArrivals = atof(argv[i+1]);
                        }else{
                            cerr << "Argument invalide : Vérifier que la valeur est bien un nombre et supérieur à 0\n";
                            exit(1);
                        }

                    }
                    else if (ch == 'a'){
                        if (check_number(argv[i+1])){
                            setArgument.insert('a');
                            averageServiceTime = atof(argv[i+1]);
                        }else{
                            cerr << "Argument invalide : Vérifier que la valeur est bien un nombre et supérieur à 0\n";
                            exit(1);
                        }
                    }
                }
            }
        }
    }else{
        cerr << "Pas d'argument ajouté\n\n";
    }

    SimulationUtility::init();
    double* averageServiceTimes = new double[nbCashier];

    if(-1 == averageServiceTime){
        SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, nbCashier);
    } else {
        for(int i=0; i<nbCashier; i++){
            averageServiceTimes[i] = averageServiceTime;
        }
    }

    cout << "\n\n############### Paramètres de la simulation ###############\n\n"
         << "\n Nombre de caissiers : " << nbCashier
         << "\n Durée de la simulation : " << dureeSimulation << "s"
         << "\n Intervalle de temps moyen d'arrivée des clients : " << timeBetweenArrivals << "s";

    if(-1 == averageServiceTime){
        cout << "\n Temps moyen de service des caissiers: aléatoire \n\n";
    } else {
        cout << "\n Temps moyen de service des caissiers: " << averageServiceTime << "s\n\n";
    }
    cout << "\n\n############### Début de la simulation ###############\n\n";

    Bank *b = new Bank(dureeSimulation, nbCashier, timeBetweenArrivals, averageServiceTimes);
    b->startSimulation();
    return 0;
}

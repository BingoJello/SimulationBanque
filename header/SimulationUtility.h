#ifndef SIMULATIONBANQUE_SIMULATIONUTILITY_H
#define SIMULATIONBANQUE_SIMULATIONUTILITY_H

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <random>
using namespace std;

class SimulationUtility {
public:
    /**
     * @brief Initialise le générateur de nombre
     * @param seed
     */
    static void init(int seed = 0) {
        srand(seed ? seed : getpid());
    }
    /**
     * @brief Récupère une valeur aléatoire selon une loi de poisson
     * @param moy Moyenne
     * @return
     */
    static double getPoissonValue(double moy = 1.0) {
        return -log(((double)rand()/RAND_MAX))*moy;
    }
    /**
     * @brief Génère une valeur aléatoire entre un min et un max dans un tableau
     * @param min Minimum range
     * @param max Maximum range
     * @param arr Tableau de stockage
     * @param arrSize Taille du tableau
     */
    static void genRandomDoubles(double min, double max, double** arr, int arrSize) {
        uniform_real_distribution<double> unif(min, max);
        random_device rd;
        default_random_engine re(rd());
        for(int i=0 ; i<arrSize ; i++) {
            *(*arr+i) = unif(re);
        }
    }
};

#endif //SIMULATIONBANQUE_SIMULATIONUTILITY_H

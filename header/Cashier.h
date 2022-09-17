#ifndef SIMULATIONBANQUE_CASHIER_H
#define SIMULATIONBANQUE_CASHIER_H

#include "Bank.h"
#include "Departure.h"
#include "Client.h"

class Bank;

class Cashier {
private:
    Bank* _bank;
    Client* _client;
    int _idCashier;
    int _nbClientsServed;
    double _averageServiceTime;
    double _occupationTime;
public:
    /**
    * @brief Constructeur
    * @param idCashier Id du caissier
    * @param ast Temps de service moyen d'un caissier
    * @param b Banque
    */
    Cashier(int idCashier, double ast, Bank* b);
    /**
    * @brief Servir le client
    * @param client Client à servir
    */
    void serve(Client* client);
    /**
    * @brief Renvoie le client
    * @return le client
    */
    Client* getClient();
    /**
    * @brief Libère le client du caissier
    */
    void releaseClient();
    /**
    * @brief Renvoie le nombre total de clients servis par le caissier
    * @return Clients servis
    */
    int getNbServedClients();
    /**
     * @brief Renvoie le taux moyen d'occupation d'un caissier
     * @return Taux moyen d'occupation
     */
    double getAverageOccupationTime();
    /**
     * @brief Renvoie l'ID du caisser
     * @return ID
     */
    int getIdCashier();
};

#endif //SIMULATIONBANQUE_CASHIER_H
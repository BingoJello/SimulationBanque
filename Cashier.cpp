#include "header/Cashier.h"

/**
 * @brief Constructeur
 * @param idCashier Id du caissier
 * @param ast Temps de service moyen d'un caissier
 * @param b Banque
 */
Cashier::Cashier(int idCashier, double ast, Bank *b) {
    _idCashier = idCashier;
    _averageServiceTime = ast;
    _bank = b;
    _nbClientsServed = 0;
    _client = nullptr;
    _occupationTime = 0;
}

/**
 * @brief Servir le client
 * @param client Client à servir
 */
void Cashier::serve(Client* client) {
    _client = client;
    _nbClientsServed++;
    double timeServed = SimulationUtility::getPoissonValue(_averageServiceTime);
    _occupationTime+=timeServed;
    _bank->add(new Departure(_bank->getTime() + timeServed, _bank, this));
}

/**
 * @brief Renvoie le client
 * @return le client
 */
Client* Cashier::getClient() {
    return _client;
}

/**
 * @brief Libère le client du caissier
 */
void Cashier::releaseClient() {
    _client = nullptr;
}

/**
 * @brief Renvoie le nombre total de clients servis par le caissier
 * @return Clients servis
 */
int Cashier::getNbServedClients() {
    return _nbClientsServed;
}

/**
 * @brief Renvoie le taux moyen d'occupation d'un caissier
 * @return Taux moyen d'occupation
 */
double Cashier::getAverageOccupationTime() {
    return (_occupationTime / _bank->getTime());
}

/**
 * @brief Renvoie l'ID du caisser
 * @return ID
 */
int Cashier::getIdCashier() {
    return _idCashier;
}
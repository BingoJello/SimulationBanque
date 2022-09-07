cmake_minimum_required(VERSION 3.23)
project(SimulationBanque)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimulationBanque main.cpp Client.cpp header/Client.h Simulation.cpp header/Simulation.h Caissier.cpp header/Caissier.h Banque.cpp header/Banque.h FileAttente.cpp header/FileAttente.h Evenement.cpp header/Evenement.h Arrivee.cpp header/Arrivee.h Depart.cpp header/Depart.h)

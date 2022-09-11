cmake_minimum_required(VERSION 3.23)
project(SimulationBanque)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimulationBanque main.cpp Client.cpp header/Client.h Simulation.cpp header/Simulation.h Cashier.cpp header/Cashier.h Bank.cpp header/Bank.h Queue.cpp header/Queue.h Event.cpp header/Event.h Arrivee.cpp header/Arrivee.h Departure.cpp header/Departure.h SimulationUtility.cpp header/SimulationUtility.h)

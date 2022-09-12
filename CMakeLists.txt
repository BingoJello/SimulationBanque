cmake_minimum_required(VERSION 3.23)
project(SimulationBanque)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimulationBanque main.cpp Client.cpp header/Client.h Simulation.cpp header/Simulation.h Bank.cpp header/Bank.h Queue.cpp header/Queue.h Event.cpp header/Event.h Arrival.cpp header/Arrival.h Departure.cpp header/Departure.h header/SimulationUtility.h Cashier.cpp header/Cashier.h)

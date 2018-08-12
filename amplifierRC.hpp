#pragma once
#include "utilityFunctions.hpp"
#include "simpleRC.hpp"

using namespace std;

// utility functions
double calculate_ID( double vgs , double vds );
void amplifier_circuit( vector<double>* phi , vector<double>* values , double time , double march );


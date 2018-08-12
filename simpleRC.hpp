#pragma once
#include "utilityFunctions.hpp"
using namespace std;

// utility functions
void simple_RC_circuit( vector<double>* phi , vector<double>* values , double time , double march );
double generate_current_input( double time );

#pragma once
#include "utilityFunctions.hpp"

#define FORWARD_EULER 0
#define RK34 1

void ODE_Solver( void (*function)(vector<double>* , vector<double>* , double , double) ,
	vector<double>* slope , vector<double>* values , double& time , double& march , int method , bool adaptivity = false );


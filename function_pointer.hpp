//
//  function_pointer.hpp
//  PA4
//
//  Created by Ariana Bruno on 4/19/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef function_pointer_hpp
#define function_pointer_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include "utilityFunctions.hpp"

#define FORWARD_EULER 0
#define RK34 1

using namespace std;

double true_function( double time );

void exponential_function( vector<double>* phi , vector<double>* x_i0, double time,  double h);

void forward_euler( void (*function)(vector<double>* , vector<double>* , double, double) , vector<double>* slope , vector<double>* values, double time , double march );

void RK34_k1( void (*function)(vector<double>* , vector<double>* , double, double), vector<double>* k1, vector<double>* x_prev, double t, double h);

void RK34_k2( void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k2, vector<double>* x_prev, double t, double* h, vector<double>* k1);

void RK34_k3(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k3,vector<double>* x_prev, double t, double h, vector<double>* k2);

void RK34_k4(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k4,vector<double>* x_prev, double t, double h, vector<double>* k3);

void calculate_Ks (void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4,vector<double>* x_prev, double t, double h);

void RK34_function(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* rk34, vector<double>* x_prev, double t, double h, vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4);

void E_RK34_function( vector<double>* Err, double march, vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4 );

double new_h_RK34( double h, vector<double>* x_i_1, vector<double>* E_i_1, double e_rel);

#endif /* function_pointer_hpp */

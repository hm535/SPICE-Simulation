//
//  utilityFunctions.hpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef utilityFunctions_hpp
#define utilityFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#include <math.h>
#include <cstdlib>

using namespace std;

void add_vectors( vector<double>* x,  vector<double>* dx,  vector<double>* sum );

void scaleVector( double scalar, vector<double>* a,  vector<double>* result);

void shiftVector( double scalar, vector<double>* a,  vector<double>* result);


void expVector( vector<double>* result, vector<double>* input);

void vectorMultiplication( vector<double>* a , vector<double>* b, vector<double>* result );

void vectorProduct( vector<double>* result , vector<vector<double>>* matrix , vector<double>* input );

void print_full_vec( vector<double>* VF );

double calculateNorm( vector<double>* v );

#endif /* utilityFunctions_hpp */

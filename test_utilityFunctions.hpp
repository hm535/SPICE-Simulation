//
//  test_utilityFunctions.hpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef test_utilityFunctions_hpp
#define test_utilityFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool TEST_add_vectors( vector<double>* x,  vector<double>* y, vector<double>* expected_result );

bool TEST_scaleVector( double scalar, vector<double>* a, vector<double>* expected_result);

bool TEST_vectorMultiplication( vector<double>* x,  vector<double>* y, vector<double>* expected_result );

void TEST();


#endif /* test_utilityFunctions_hpp */

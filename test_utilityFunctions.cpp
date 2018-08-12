//
//  test_utilityFunctions.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "test_utilityFunctions.hpp"
#include "utilityFunctions.hpp"

// suite of test functions for utility functions
bool TEST_add_vectors( vector<double>* x,  vector<double>* y, vector<double>* expected_result ){
	// testing the elementwise addition of vectors x and y
    vector<double> sum;
    add_vectors(x, y, &sum);
    if( sum == *expected_result){
        return true;
    } else{
        return false;
    }
    
}
bool TEST_scaleVector( double scalar, vector<double>* a, vector<double>* expected_result){
	// testing the multiplication of a vector and a scalar
    vector<double> result;
    scaleVector(scalar, a, &result);
    if( result == *expected_result ){
        return true;
    } else {
        return false;
    }
    
}

bool TEST_vectorMultiplication( vector<double>* x,  vector<double>* y, vector<double>* expected_result ){
	// testing the elementwise multiplication of vectors x and y
    vector<double> product;
    vectorMultiplication(x, y, &product);
    if( product == *expected_result){
        return true;
    } else{
        return false;
    }
    
}

void TEST(){
	// parent test function to call all the individual test functions
    cout << "Testing the vector add function: " << endl << endl;
    vector<double> a = {1, 1, 1, 1};
    vector<double> b = {2, 2, 2, 2};
    vector<double> c;
    vector<double> expected_c = {3,3,3,3};
    add_vectors(&a, &b, &c);
    cout << "{1, 1, 1, 1} + {2, 2, 2, 2} = ";
    print_full_vec(&c);
    bool test_add1 = TEST_add_vectors(&a, &b, &expected_c);
    cout << "vector of 1s plus a vector of 2s is eqaul to vector of 3s: " << test_add1 << endl << endl;
    
    cout << "Testing the vector scale function: " << endl << endl;
    vector<double> d;
    vector<double> expected_d = {15,15,15,15};
    scaleVector(5, &c, &d);
    cout << "{3, 3, 3, 3} * 5 = ";
    print_full_vec(&d);
    bool test_scale1 = TEST_scaleVector(5, &c, &expected_d);
    cout << "vector of 3s scaled by 5 is eqaul to vector of 15s: " << test_scale1 << endl << endl;
    
    cout << "Testing the vector multiplication function: " << endl << endl;
    vector<double> e;
    vector<double> expected_e = {30,30,30,30};
    vectorMultiplication(&b, &d, &e);
    cout << "{2, 2, 2, 2} * {15, 15, 15, 15} = ";
    print_full_vec(&e);
    bool test_multiplication1 = TEST_vectorMultiplication(&b, &d, &expected_e);
    cout << "vector of 2s multipled by vector of 15s is eqaul to vector of 30s: " << test_multiplication1 << endl << endl;
}

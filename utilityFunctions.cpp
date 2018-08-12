//
//  utilityFunctions.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "utilityFunctions.hpp"

/* adds to vectors provided by pointers and returns sum by using a pointer */
/* from programming assignment 3 */
void add_vectors( vector<double>* x,  vector<double>* dx,  vector<double>* sum ){
    if((*x).size() != (*dx).size()){
        cout << "vectors have different dimensions... cannot add them togther! " << endl;
    }else{
        if( sum->size() >= 1 ){
            sum->erase(sum->begin(), sum->end());
        }
        for( int i = 0; i < (*x).size(); i++){
            (*sum).push_back((*x)[i] + (*dx)[i]);
        }
    }
}

/* scales the vector provided by a pointer by a scalar which is also provided by a pointer */
/* from programming assignment 3 */
void scaleVector( double scalar, vector<double>* a,  vector<double>* result){
    if( (*result) == (*a)){
        
    }
    for( int i = 0; i<(*a).size(); i++){
        (*result).push_back((*a)[i]*scalar);
    }
}

/* creates a deep copy of the vector AF in CT */
/* from programming assignment 3 */
void copyMatrix ( vector<double>* CF , vector<double>* AF ){
    (*CF) = (*AF);
    return;
}

/* adds a constant to all th elements in a vector */
void shiftVector( double scalar, vector<double>* a,  vector<double>* result){
    for( int i = 0; i<(*a).size(); i++){
        (*result).push_back((*a)[i] + scalar);
    }
}

/* calculates the exponential of each element in a vector */
void expVector( vector<double>* result, vector<double>* input){
    if( input->size() < 1 ){
        cout << "ERROR: cannot calculate the exponential of an empty vector " << endl;
    }else{
        for( int i = 0; i < input->size(); i++){
            result->push_back(exp((*input)[i]));
        }
    }
}

/* elementwise multiplication of two vectors */
void vectorMultiplication( vector<double>* a , vector<double>* b, vector<double>* result ){
    if ( (*a).size() != (*b).size() ){
        cout << "ERROR: matrix dimensions do not match!";
        return;
    }
    for ( int i = 0 ; i < (*a).size() ; i++ ){
        result->push_back(((*a)[i])*((*b)[i]));
    }
}

/* product of a matrix and a vector */
/* from programming assignment 3 */
void vectorProduct( vector<double>* result , vector<vector<double>>* matrix , vector<double>* input ){
    
    if ( (*input).size() != (*matrix).size() ){
        cout << "ERROR: matrix dimensions do not match for vector product!";
        return;
    }
    int rank = (*input).size();
    for ( int i = 0 ; i < rank ; i++ ){
        (*result).push_back(0.0);
    }
    for ( int i = 0 ; i < rank ; i++ ){
        for ( int j = 0 ; j < rank ; j++ ){
            (*result)[i] += (((*matrix)[i][j])*((*input)[j]));
        }
    }
}

/* print the full vector VF given by a pointer */
/* from programming assignment 2 */
void print_full_vec( vector<double>* VF ){
    for ( int i = 0 ; i < (*VF).size() ; i++ ){
        cout << (*VF)[i] << "   ";
    }
//    cout << endl;
}

/* calculate the norm of the vector v */
/* modified funciton from programing assignment 2 */
double calculateNorm( vector<double>* v){
    // assuming v is a vector to calculate the norm
    double squareSum = 0.0;
    for ( int i = 0 ; i < (*v).size() ; i++ ){
        double temp = (*v)[i];
        squareSum += temp*temp;
    }
    double norm = sqrt( squareSum );
    return norm;
}

//
//  main.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include "utilityFunctions.hpp"
#include "test_utilityFunctions.hpp"
#include "test_systemFunctions.hpp"
#include "function_pointer.hpp"
#include "simpleRC.hpp"
#include "amplifierRC.hpp"
#include "phi.hpp"

int main(int argc, const char * argv[]) {
//    for( int i = 0; i<=argc; i++){
//        cout << argv[i] << endl;
//    }
    string first_arg = argv[1];
    string second_arg = argv[3];
    string test_arg = "TEST";
    string exp_arg = "Exponential";
    string simple_arg = "Simple";
    string amplifier_arg = "Amplifier";
    string forward_arg = "ForwardEuler";
    string RK34_arg = "RK34";
    string RK34A_arg = "RK34A";
    
    void (*exp_fcn)( vector<double>* , vector<double>* , double , double ) = exponential_function;
    void (*simpleCircuit)( vector<double>* , vector<double>* , double , double) = simple_RC_circuit;
    void (*amplifierCircuit)( vector<double>* , vector<double>* , double , double ) = amplifier_circuit;
    
    if(first_arg == test_arg){
        //cout << fixed;
        cout << " --------------- Testing Utility Functions --------------- " << endl;
        TEST();
        
        cout << " --------------- Testing Circuit Functions --------------- " << endl;
        if ( test_current_generator() )
            cout << " current generator is working " << endl << endl;
        else cout << " current generator is not working " << endl << endl;

        if ( test_simple_RC_circuit() )
            cout << " simple RC circuit function is working " << endl << endl;
        else cout << " simple RC circuit function is not working " << endl << endl;

        if ( test_amplifier_circuit() )
            cout << " amplifier circuit function is working " << endl << endl;
        else cout << " amplifier circuit function is not working " << endl << endl;

        cout << endl << endl;
        
    } else if( second_arg == exp_arg){

    //
    // PA 4 Tasks 3
    //
    
        cout << fixed;
        
        vector<double> slope , values;
        
        vector<double> initial;
        initial = {2.0};
        double time = 0.0;
        double march = 1.0;
        double end_time = 4;
        values = initial;
        
        if( first_arg == RK34_arg ){ cout << "time:      actual:      RK34:  " << endl; };
        if( first_arg == RK34A_arg ){ cout << "time:      actual:      RK34 Adaptation:  " << endl; };
        if( first_arg == forward_arg ){ cout << "time:      actual:      Forward:  " << endl; };
        cout << "---------------------------------------------------------------------------" << endl;
        
        while(time <= end_time){
            cout << time << "   ";
            double ground_truth = true_function(time);
            cout << ground_truth << "   ";
            if( first_arg == RK34A_arg ){
                ODE_Solver( exp_fcn , &slope , &values , time , march , RK34, true);
            } else if( first_arg == RK34_arg ){
                ODE_Solver( exp_fcn , &slope , &values , time , march , RK34);
            } else {
                //Forward Euler is default
                ODE_Solver( exp_fcn , &slope , &values , time , march , FORWARD_EULER);
            }
        }
        cout << endl;
    } else if( (second_arg == simple_arg) || (second_arg == amplifier_arg) ){
    
        //
        // PA 4 Task 4 or 5
        //
        
        cout << endl;

        cout << fixed;
        cout.precision(10);
        
        //reset vectors for next task
        vector<double> slope, values, initial;
        
        //re-intializing values for this task
        double time = 0.0;
        double march = 1e-9;
        
        if(argc > 4){
            if((string)argv[5] == "0.2"){
                march = 0.2e-9;
            };
            
        }
        //    initial = {2.0};
        initial = {0.0 , 0.0};
        values = initial;
        double end_time = 100e-9;

        if( first_arg == RK34A_arg ){
            cout << "RK34 Adaptation Method: " << endl;
                
        } else if (first_arg == RK34_arg){
            cout << "RK34 Method: " << endl;
        }else if ( first_arg == forward_arg ){
            cout << "Forward Euler Method: " << endl;
            
        };
        cout << "time:     V1:        V2:     " << endl;
        cout << "--------------------------------------" << endl;

        while(time <= end_time){
            cout << time << "   ";
            
            if( first_arg == RK34A_arg ){
                if( second_arg == amplifier_arg){
                    ODE_Solver( amplifierCircuit , &slope , &values , time , march , RK34, true);
                } else {
                    // Simple Circuit is default for RK34 with adaption
                    ODE_Solver( simpleCircuit , &slope , &values , time , march , RK34, true);
                }
            } else if (first_arg == RK34_arg) {
                if( second_arg == amplifier_arg){
                    ODE_Solver( amplifierCircuit , &slope , &values , time , march , RK34);
                } else {
                    // Simple Circuit is default for RK34 with adaption
                    ODE_Solver( simpleCircuit , &slope , &values , time , march , RK34);
                }
            } else {
                if( second_arg == amplifier_arg){
                    ODE_Solver( amplifierCircuit , &slope , &values , time , march , FORWARD_EULER);
                } else {
                    // Simple Circuit is default for Forward Euler
                    ODE_Solver( simpleCircuit , &slope , &values , time , march , FORWARD_EULER);
                }
                
            }
            
        }


        cout << endl;
//        cout << dummy_march << endl;
    }

}

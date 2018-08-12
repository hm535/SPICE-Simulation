//
//  test_systemFunctions.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/22/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "test_systemFunctions.hpp"

bool test_current_generator( ){
    // function to test if the correct input current values are generated
    // returns true if all the values are correct
    // and false if any of the values are incorrect
    
    bool flag = true;
    
    if ( generate_current_input( 7.5e-9 ) != 0.1e-3
        || generate_current_input( 26.2e-9 ) != 0.1e-3
        || generate_current_input( 43.6e-9 ) != 0.1e-3
        || generate_current_input( 67.3e-9 ) != 0.1e-3
        || generate_current_input( 84.6e-9 ) != 0.1e-3)
        flag = false;
    
    if ( generate_current_input( 17.5e-9 ) != 0.0e-3
        || generate_current_input( 36.2e-9 ) != 0.0e-3
        || generate_current_input( 53.6e-9 ) != 0.0e-3
        || generate_current_input( 77.3e-9 ) != 0.0e-3
        || generate_current_input( 94.6e-9 ) != 0.0e-3)
        flag = false;
    
    if ( abs( generate_current_input( 0.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 20.5e-9 )  - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 40.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 60.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 80.5e-9 ) - 0.05e-3 ) > 1e-12 )
        flag = false;
    
    if ( abs( generate_current_input( 10.5e-9 )  - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 30.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 50.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 70.5e-9 ) - 0.05e-3 ) > 1e-12
        || abs( generate_current_input( 90.5e-9 ) - 0.05e-3 ) > 1e-12 )
        flag = false;
    
    return flag;
}

bool test_simple_RC_circuit() {
    // function to test if the simple RC function returns the correct values withing a tolerance
    // "true" values are obtained from the matlab implementation
    // returns true is all the values are correct
    // returns false if there are any incorrect values
    
    bool flag = true;
    double march = 1e-9;
    double tolerance = 1.0e-5;
    
    // test 1
    vector<double> test_1 , values_1 ;
    double time_1 = 20.5e-9 ;
    values_1 = { 1.0 , 1.0 };
    simple_RC_circuit( &test_1 , &values_1 , time_1 , march );
    if ( abs( test_1[0] - ( -50.0e6 ) ) > tolerance
        || abs( test_1[1] - ( -100.0e6 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_1 );
    }
    
    // test 2
    vector<double> test_2 , values_2 ;
    double time_2 = 64.5e-9 ;
    values_2 = { 2.0 , 4.0 };
    simple_RC_circuit( &test_2 , &values_2 , time_2 , march );
    if ( abs( test_2[0] - ( 100.0e6 ) ) > tolerance
        || abs( test_2[1] - ( -600.0e6 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_2 );
    }
    
    // test 3
    vector<double> test_3 , values_3 ;
    double time_3 = 76.3e-9;
    values_3 = { 3.0 , 5.0 };
    simple_RC_circuit( &test_3 , &values_3 , time_3 , march );
    if ( abs( test_3[0] - ( -100.0e6 ) ) > tolerance
        || abs( test_3[1] - ( -700.0e6 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_3 );
    }
    
    // return error flag
    return flag;
    
}

bool test_amplifier_circuit(){
    // function to test if the amplifier function returns the correct values withing a tolerance
    // "true" values are obtained from the matlab implementation
    // returns true is all the values are correct
    // returns false if there are any incorrect values
    
    bool flag = true;
    double march = 1e-9;
    double tolerance = 1.0;
    
    // test 1
    vector<double> test_1 , values_1 ;
    double time_1 = 20.5e-9 ;
    values_1 = { 1.0 , 1.0 };
    amplifier_circuit( &test_1 , &values_1 , time_1 , march );
    if ( abs( test_1[0] - ( -0.499999999999999e8 ) ) > tolerance
        || abs( test_1[1] - ( 3.975977349304090e8 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_1 );
        cout << endl;
    }
    
    
    // test 2
    vector<double> test_2 , values_2 ;
    double time_2 = 64.5e-9 ;
    values_2 = { 2.0 , 4.0 };
    amplifier_circuit( &test_2 , &values_2 , time_2 , march );
    if ( abs( test_2[0] - ( -1.0000e8 ) ) > tolerance
        || abs( test_2[1] - ( -8.060652805458858e8 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_2 );
        cout << endl;
    }
    
    // test 3
    vector<double> test_3 , values_3 ;
    double time_3 = 76.3e-9;
    values_3 = { 3.0 , 5.0 };
    amplifier_circuit( &test_3 , &values_3 , time_3 , march );
    if ( abs( test_3[0] - ( -0.3000e9 ) ) > tolerance
        || abs( test_3[1] - ( -3.6242603550301333e9 ) ) > tolerance ){
        flag = false;
        print_full_vec( &test_3 );
        cout << endl;
    }
    
    // return error flag
    return flag;
    
}


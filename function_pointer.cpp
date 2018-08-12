#include "function_pointer.hpp"
#include "simpleRC.hpp"
#include "amplifierRC.hpp"

double true_function( double time ){
    return (((4/1.3)*(exp(0.8*time) - exp(-0.5*time))) + 2*exp(-0.5*time));
}


void exponential_function( vector<double>* phi , vector<double>* x_i0, double time, double h){
    // function to generate the instantaneous slope at the given time step
    vector<double> x_i0_scale05;
    double exp_comp = 4.0*exp(0.8*time);
    scaleVector(-0.5, x_i0, &x_i0_scale05);
    shiftVector(exp_comp, &x_i0_scale05, phi);
    return;
}


void forward_euler( void (*function)(vector<double>* , vector<double>* , double, double) , vector<double>* slope , vector<double>* values, double time , double march ){
	// function to calculate the current slope based on the forward euler method
	// takes in a void pointer to any differential function with the standard function signature
	function( slope, values, time, march );
	return;
}

void RK34_k1( void (*function)(vector<double>* , vector<double>* , double, double), vector<double>* k1, vector<double>* x_prev, double t, double h){
    // function to calculate the k1-th slope based on the RK34 method
	// takes in a void pointer to any differential function with the standard function signature
    function( k1, x_prev , t , h );
}

void RK34_k2( void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k2, vector<double>* x_prev, double t, double h, vector<double>* k1){
    // function to calculate the k2-th slope based on the RK34 method
	// takes in a void pointer to any differential function with the standard function signature
    vector<double> k1_h, k1_h_2, h_2, x_prev_k2;
    scaleVector(h, k1, &k1_h);
    scaleVector(0.5, &k1_h, &k1_h_2);
    double t_k2 = t + (h/2.0);
    add_vectors(x_prev, &k1_h_2, &x_prev_k2);
    function(k2, &x_prev_k2, t_k2, h);
//    return h62_dx_dt(x_prev + (k1*h/2.0), t + (h/2.0));
}

void RK34_k3(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k3,vector<double>* x_prev, double t, double h, vector<double>* k2){
    // function to calculate the k3-th slope based on the RK34 method
	// takes in a void pointer to any differential function with the standard function signature
    vector<double> k2_h, k2_h_34, h_34, x_prev_k3;
    scaleVector( h,k2, &k2_h);
    scaleVector(0.75, &k2_h, &k2_h_34);
    double t_k3 = t + (h*(3.0/4.0));
    add_vectors(x_prev, &k2_h_34, &x_prev_k3);
    function(k3, &x_prev_k3, t_k3, h);
}

void RK34_k4(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k4,vector<double>* x_prev, double t, double h, vector<double>* k3){
    // function to calculate the k4-th slope based on the RK34 method
	// takes in a void pointer to any differential function with the standard function signature
    vector<double> k3_h, x_prev_k4;
    scaleVector(h, k3, &k3_h);
    double t_k4 = t + h;
    add_vectors(x_prev, &k3_h, &x_prev_k4);
    function(k4, &x_prev_k4, t_k4, h);
}
//

void calculate_Ks (void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4,vector<double>* x_prev, double t, double h){
    // helper function to call the functions to calculate values of k1 to k4 in RK34 method
    RK34_k1(function, k1, x_prev, t, h);
    RK34_k2(function, k2, x_prev, t, h, k1);
    RK34_k3(function, k3, x_prev, t, h, k2);
    RK34_k4(function, k4, x_prev, t, h, k3);
}

void RK34_function(void (*function)(vector<double>* , vector<double>*, double, double), vector<double>* rk34, vector<double>* x_prev, double t, double h, vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4){
    // function to generate the values of the next iteration based on the RK34 method
	// takes in a void pointer to any differential function with the standard function signature
    calculate_Ks(function, k1, k2, k3, k4, x_prev, t, h);
    
    vector<double> k1_7, k2_6, k3_8, k4_3, k1_k2, k3_k4, sum_K, sum_K_h, sum_K_h_scaled;
    scaleVector(7.0, k1, &k1_7);
    scaleVector(6.0, k2, &k2_6);
    scaleVector(8.0, k3, &k3_8);
    scaleVector(3.0, k4, &k4_3);
    add_vectors(&k1_7, &k2_6, &k1_k2);
    add_vectors(&k3_8, &k4_3, &k3_k4);
    add_vectors(&k1_k2, &k3_k4, &sum_K);
    scaleVector((1.0/24.0), &sum_K, rk34);
//    add_vectors(&sum_K_h_scaled, x_prev, rk34);
}

void E_RK34_function( vector<double>* Err, double march, vector<double>* k1, vector<double>* k2, vector<double>* k3, vector<double>* k4 ){
    // function to calcualte the error estimate for the adaptive RK method
    vector<double> k1_5, k2_6, k3_8, k4_9, k1_k2, k3_k4, sum_k,sum_k_h;
    scaleVector(-5.0, k1, &k1_5);
    scaleVector(6.0, k2, &k2_6);
    scaleVector(8.0, k3, &k3_8);
    scaleVector(-9.0, k4, &k4_9);
    add_vectors(&k1_5, &k2_6, &k1_k2);
    add_vectors(&k3_8, &k4_9, &k3_k4);
    add_vectors(&k1_k2, &k3_k4, &sum_k);
    scaleVector(march, &sum_k, &sum_k_h);
    scaleVector((1.0/72.0), &sum_k_h, Err);
}

double new_h_RK34( double h, vector<double>* x_i_1, vector<double>* E_i_1, double e_rel){
    // function to calculate the appropriate time step for the next iteration
    double E_i_1_Norm = calculateNorm(E_i_1);
    double x_i_1_Norm = calculateNorm(x_i_1);
    double intermediate_value = e_rel/(E_i_1_Norm/x_i_1_Norm);
    double h_i_1 = h * pow(intermediate_value, (1.0/3.0));
    return h_i_1;
}

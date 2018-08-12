#include "amplifierRC.hpp"

void amplifier_circuit( vector<double>* phi , vector<double>* values , double time , double march ){
	// function to generate the instantaneous slope at the given time step
	// based on figure 5a in the handout

	// declare given parameters of the circuit
	double Is , kappa , Vth , Vdd , R , C;
	Vdd = 5.0;
	R = 10.0e3;
	C = 1.0e-12;

	// obtain the current input at the present time
	double current_term = ( generate_current_input( time )) / C;
	// calculate the slope of V1
	double phi_1 = ( (-(*values)[0])/(R*C) ) + current_term;
	// calculate the slope of V2
	double ID = calculate_ID( (*values)[0] , (*values)[1] );
	double phi_2 = (-ID / C ) - (((*values)[1])/(R*C)) + (Vdd/(R*C));

	// push values into the return vector
	(*phi).push_back(phi_1);
	(*phi).push_back(phi_2);
}

double calculate_ID( double vgs , double vds ){
    // function to calculate the ID,EKF current values
    // based on equation 01 in the handout
    // code reused from programmin assignment 3
    double kappa = 0.7;
    double vth = 1.0;
    double is = 5.0e-6;
    double vt = 26.0e-3;
    double term_1 = log(1.0 + exp( ( kappa*( vgs -  vth ) ) / ( 2*vt ) ));
    term_1 = term_1*term_1;
    double term_2 = log(1.0 + exp( ( kappa*(vgs-vth)-vds ) / (2*vt) ));
    term_2 = term_2*term_2;
    return is*(term_1 - term_2);
}


#include "simpleRC.hpp"

void simple_RC_circuit( vector<double>* phi , vector<double>* values , double time , double march ){
	// function to generate the instantaneous slope at a given time step
	// based on figure 3 in the handout

	// declare given parameters of the circuit
	double R1 , R2 , R3 , C1 , C2 , cp11 , cp12 , cp21 , cp22 ;
	R1 = 10.0e3;
	R2 = 10.0e3;
	R3 = 10.0e3;

	C1 = 1.0e-12;
	C2 = 1.0e-12;

	cp11 = -( (1.0/(C1*R1)) + (1.0/(C1*R2)) );
	cp12 = 1.0/(C1*R2);
	cp21 = 1.0/(C2*R2);
	cp22 = -( (1.0/(C2*R2)) + (1.0/(C2*R3)) );

	// find the homogenous solution
	vector<vector<double>> circuit_param = { {cp11 , cp12 } , {cp21 , cp22} };
	vector<double> temp;
	vectorProduct( &temp , &circuit_param , values );

	// find the current input for the present time
	double current_term = ( generate_current_input( time )) / C1;

	// pushback the values into the result vector
	(*phi).push_back( temp[0] + current_term );
	(*phi).push_back( temp[1] + 0.0 );

}

double generate_current_input( double time ){
	// function to generate the current input at the given time
	// based on figure 6 in the handout

	double gradient = (0.1e-3)/(1.0e-9);

	if ( time >= 1.0e-9 && time <= 10e-9 ||
		time >= 21e-9 && time <= 30e-9 ||
		time >= 41e-9 && time <= 50e-9 ||
		time >= 61e-9 && time <= 70e-9 ||
		time >= 81e-9 && time <= 90e-9 )
		return( 0.1e-3 );

	else if ( time >= 11e-9 && time <= 20e-9 ||
		time >= 31e-9 && time <= 40e-9 ||
		time >= 51e-9 && time <= 60e-9 ||
		time >= 71e-9 && time <= 80e-9 ||
		time >= 91e-9 && time <= 100e-9)
		return ( 0.0 );

	// period one
	else if ( time >= 0.0 && time < 1.0e-9 )
		return ( gradient * time );

	else if ( time > 10e-9 && time < 11e-9 )
		return(  0.1e-3 - (gradient * (time - 10e-9)));

	// period two
	else if ( time > 20e-9 && time < 21e-9 )
		return ( gradient * (time - 20e-9) );

	else if ( time > 30e-9 && time < 31e-9 )
		return(  0.1e-3 - (gradient * (time - 30e-9)));

	// period three
	else if ( time > 40e-9 && time < 41e-9 )
		return ( gradient * (time - 40e-9) );

	else if ( time > 50e-9 && time < 51e-9 )
		return(  0.1e-3 - (gradient * (time - 50e-9)));

	// period four
	else if ( time > 60e-9 && time < 61e-9 )
		return ( gradient * (time - 60e-9) );

	else if ( time > 70e-9 && time < 71e-9 )
		return(  0.1e-3 - (gradient * (time - 70e-9)));

	// period five
	else if ( time > 80e-9 && time < 81e-9 )
		return ( gradient * (time - 80e-9) );

	else if ( time > 90e-9 && time < 91e-9 )
		return(  0.1e-3 - (gradient * (time - 90e-9)));

	// error return
	else return ( -1.0 );

}


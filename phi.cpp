#include "phi.hpp"
#include "function_pointer.hpp"
#include "simpleRC.hpp"
// #include "function_pointer.hpp"

void ODE_Solver( void (*function)(vector<double>* , vector<double>* , double , double) ,
	vector<double>* slope , vector<double>* values , double& time , double& march , int method , bool adaptivity ){
	
    vector<double> new_values;
    
    switch( method ){
		case FORWARD_EULER : {
            
            if( time == 0.0){
                new_values = *values;
            } else {
                double time_prev = time - march;
                
                forward_euler( function , slope , values , time_prev , march );
                vector<double> slope_h;
                scaleVector(march, slope, &slope_h);
                add_vectors(values, &slope_h, &new_values);
                
            }
            print_full_vec(&new_values);
            (*values) = new_values;
            slope->erase(slope->begin(), slope->end());
            double new_time = time + march;
            time = new_time;
            cout << endl;
			break; 
		}
		case RK34 :{
            vector<double> k1, k2, k3, k4, Err;
			
                
            if( time == 0.0){
                new_values = *values;
            } else {
                double time_prev = time - march;
                RK34_function(function, slope, values, time_prev, march, &k1, &k2, &k3, &k4);
                vector<double> slope_h;
                scaleVector(march, slope, &slope_h);
                add_vectors(values, &slope_h, &new_values);
                if ( adaptivity ) {
                    E_RK34_function(&Err, march, &k1, &k2, &k3, &k4 );
                    double Err_norm = calculateNorm(&Err);
                    if ( Err_norm > 1e-4 ){
                        // adjust the march (h) when Err is greater than a tolerance of 1e-4.
                        while( Err_norm > 1e-4 ){
                            double h_i_1 = new_h_RK34(march, &new_values, &Err, 1e-4);
                            march = h_i_1;
                            vector<double> slope_h, adapt_new_values, new_Err;
                            scaleVector(march, slope, &slope_h);
                            add_vectors(values, &slope_h, &adapt_new_values);
                            E_RK34_function(&new_Err, march, &k1, &k2, &k3, &k4 );
                            double new_Err_norm = calculateNorm(&new_Err);
                            Err_norm = new_Err_norm;
                        }
                    }
                }
            }
//            print_full_vec(&k1);
//            print_full_vec(&k2);
//            print_full_vec(&k3);
//            print_full_vec(&k4);
            print_full_vec(&new_values);
            (*values) = new_values;
            slope->erase(slope->begin(), slope->end());
            double new_time = time + march;
            time = new_time;
            cout << endl;
            break; 
		}
	}
	return;
}


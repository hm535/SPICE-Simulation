function [phi] = amplifierCircuit( current_values , time )
    Vdd = 5.0;
	R = 10e3;
	C = 1.0e-12;
    
    current_term = generateCurrent(time)/C;
    phi(1) = (-current_values(1)/(R*C)) + current_term;
    ID = calculate_ID( current_values(1) , current_values(2) );
    phi(2) = (-ID/C) - (current_values(2) / (R*C) ) + ( Vdd/ (R*C));
end
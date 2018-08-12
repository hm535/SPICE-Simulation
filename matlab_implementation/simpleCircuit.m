function [phi] = simpleCircuit( current_values , time )

R1 = 10.0e3;
R2 = 10.0e3;
R3 = 10.0e3;

C1 = 1.0e-12;
C2 = 1.0e-12;

cp11 = -( (1.0/(C1*R1)) + (1.0/(C1*R2)) );
cp12 = 1.0/(C1*R2);
cp21 = 1.0/(C2*R2);
cp22 = -( (1.0/(C2*R2)) + (1.0/(C2*R3)) );
circuit_params = [cp11 cp12 ; cp21 cp22];

temp = circuit_params*current_values;
current_term = generateCurrent(time)/C1;
phi = [ temp(1) + current_term ; temp(2) ];
end


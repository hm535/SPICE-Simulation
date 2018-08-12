function [ID] = calculate_ID(vgs,vds)
kappa = 0.7;
vth = 1.0;
is = 5.0e-6;
vt = 26e-3;

term_1 = log(1.0 + exp( ( kappa*( vgs -  vth ) ) / ( 2*vt ) ));
term_1 = term_1*term_1;

term_2 = log(1.0 + exp( ( kappa*(vgs-vth)-vds ) / (2*vt) ));
term_2 = term_2*term_2;

ID = is*(term_1 - term_2);
end


function [phi] = expfcn( current_values , time )
phi = 4*exp(0.8*time) - 0.5*current_values;
end


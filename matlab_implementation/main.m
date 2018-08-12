clc, clear, close all;
format long;

%% Testing Values of Simple Circuit
current_values = [ 1.0 ; 1.0 ];
time = 20.5e-9;
s_test_1 = simpleCircuit( current_values , time );

current_values = [ 2.0 ; 4.0 ];
time = 64.5e-9;
s_test_2 = simpleCircuit( current_values , time );

current_values = [ 3.0 ; 5.0 ];
time = 76.3e-9;
s_test_3 = simpleCircuit( current_values , time );

%% Testing Values of Amplifier Circuit
current_values = [ 1.0 ; 1.0 ];
time = 20.5e-9;
a_test_1 = amplifierCircuit( current_values , time );

current_values = [ 2.0 ; 4.0 ];
time = 64.5e-9;
a_test_2 = amplifierCircuit( current_values , time );

current_values = [ 3.0 ; 5.0 ];
time = 76.3e-9;
a_test_3 = amplifierCircuit( current_values , time );

%%  Testing Forward Euler for Exponential

time = 0.0;
march = 1.0;
n_steps = 5;
current_values = 2.0;
value_log_exp_euler = zeros( 1 , round(n_steps));
for ii = 1:n_steps
    phi = expfcn( current_values , time );
    current_values = current_values + march*phi;
    value_log_exp_euler(:,ii) = current_values;
    time = time + march;
end

%%  Testing RK34 for Exponential 

time = 0.0;
march = 1.0;
n_steps = 5;
current_values = 2.0;
value_log_exp_RK34 = zeros( 1 , round(n_steps));
for ii = 1:n_steps
    k1 = expfcn( current_values , time );
    k2 = expfcn( current_values + 0.5*march*k1 , time + 0.5*march );
    k3 = expfcn( current_values + 0.75*march*k2 , time + 0.75*march );
    k4 = expfcn( current_values + march*k3 , time + march );
    temp = ( 7.0*k1 + 6.0*k2 + 8.0*k3 + 3.0*k4 )*march / 24.0;
    current_values = current_values + temp;
    value_log_exp_RK34(:,ii) = current_values;
    time = time + march;
end

% %%  Testing Adaptive RK34 for Exponential 
% 
% time = 0.0;
% march = 1.0;
% n_steps = 5;
% current_values = 2.0;
% tol = 1.0e-7;
% value_log_exp_RK34A = zeros( 1 , round(n_steps));
% for ii = 1:n_steps
%     k1 = expfcn( current_values , time );
%     k2 = expfcn( current_values + 0.5*march*k1 , time + 0.5*march );
%     k3 = expfcn( current_values + 0.75*march*k2 , time + 0.75*march );
%     k4 = expfcn( current_values + march*k3 , time + march );
%     temp = ( 7.0*k1 + 6.0*k2 + 8.0*k3 + 3.0*k4 )*march / 24.0;
%     error_estimate = ( -5.0*k1 + 6.0*k2 + 8.0*k3 -9.0*k4 ) / 72.0;
%     current_values = current_values + temp;
%     error_norm = norm( error_estimate );
%     state_norm = norm( current_values );
%     scale = tol/ ( error_norm / state_norm );
%     march = march*scale;
%     value_log_exp_RK34A(:,ii) = current_values;
%     time = time + march;
% end

%%  Testing Forward Euler for Simple Circuit

time = 0.0;
march = 1.0e-9;
n_steps = 100e-9 / march + 1;
current_values = [ 0.0 ; 0.0 ];
value_log_simple_euler = zeros( 2 , round(n_steps));
for ii = 1:n_steps
    phi = simpleCircuit( current_values , time );
    current_values = current_values + march*phi;
    value_log_simple_euler(:,ii) = current_values;
    time = time + march;
end

%%  Testing RK34 for Simple Circuit

time = 0.0;
march = 1.0e-9;
n_steps = 100e-9 / march + 1;
current_values = [ 0.0 ; 0.0 ];
value_log_simple_RK34 = zeros( 2 , round(n_steps));
for ii = 1:n_steps
    k1 = simpleCircuit( current_values , time );
    k2 = simpleCircuit( current_values + 0.5*march*k1 , time + 0.5*march );
    k3 = simpleCircuit( current_values + 0.75*march*k2 , time + 0.75*march );
    k4 = simpleCircuit( current_values + march*k3 , time + march );
    temp = ( 7.0*k1 + 6.0*k2 + 8.0*k3 + 3.0*k4 )*march / 24.0;
    current_values = current_values + temp;
    value_log_simple_RK34(:,ii) = current_values;
    time = time + march;
end

%%  Testing Forward Euler for Amplifier Circuit

time = 0.0;
march = 1.0e-9;
n_steps = 100e-9 / march + 1;
current_values = [ 0.0 , 0.0 ];
value_log_amplifier_euler = zeros( 2 , round(n_steps));
for ii = 1:n_steps
    phi = amplifierCircuit( current_values , time );
    current_values = current_values + march*phi;
    value_log_amplifier_euler(:,ii) = current_values';
    time = time + march;
end

%%  Testing RK34 for Amplifier Circuit

time = 0.0;
march = 1.0e-9;
n_steps = 100e-9 / march + 1;
current_values = [ 0.0 , 0.0 ];
value_log_amplifier_RK34 = zeros( 2 , round(n_steps));
for ii = 1:n_steps
    k1 = amplifierCircuit( current_values , time );
    k2 = amplifierCircuit( current_values + 0.5*march*k1 , time + 0.5*march );
    k3 = amplifierCircuit( current_values + 0.75*march*k2 , time + 0.75*march );
    k4 = amplifierCircuit( current_values + march*k3 , time + march );
    temp = ( 7.0*k1 + 6.0*k2 + 8.0*k3 + 3.0*k4 )*march / 24.0;
    current_values = current_values + temp;
    value_log_amplifier_RK34(:,ii) = current_values';
    time = time + march;
end
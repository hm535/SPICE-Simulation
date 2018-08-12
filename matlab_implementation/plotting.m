FEAmp1results = FEAmp1results(1:end-1, 1:3);
FEAmp01 = table2array(FEAmp1results);
FEAmp02results = FEAmp02results(1:end-1, 1:3);
FEAmp02 = table2array(FEAmp02results);

FESimp1results = FESimp1results(1:end-1, 1:3);
FESimp01 = table2array(FESimp1results);
FESimp02results = FESimp02results(1:end-1, 1:3);
FESimp02 = table2array(FESimp02results);

RK34AAmp02results = RK34AAmp02results(1:end-1, 1:3);
RKAAmp02 = table2array(RK34AAmp02results);
RK34AAmp1results = RK34AAmp1results(1:end-1, 1:3);
RKAAmp01 = table2array(RK34AAmp1results);

RK34Amp02results = RK34Amp02results(1:end-1, 1:3);
RKAmp02 = table2array(RK34Amp02results);
RK34Amp1results = RK34Amp1results(1:end-1, 1:3);
RKAmp01 = table2array(RK34Amp1results);

RK34ASimp02results = RK34ASimp02results(1:end-1, 1:3);
RKASimp02 = table2array(RK34ASimp02results);
RK34ASimp1results = RK34ASimp1results(1:end-1, 1:3);
RKASimp01 = table2array(RK34ASimp1results);

RK34Simp02results = RK34Simp02results(1:end-1, 1:3);
RKSimp02 = table2array(RK34Simp02results);
RK34Simp1results = RK34Simp1results(1:end-1, 1:3);
RKSimp01 = table2array(RK34Simp1results);

%%
time_FE = FEAmp02(:,1);
V1_FE = FEAmp02(:,2);
V2_FE = FEAmp02(:,3);

time_RK = RKAmp02(:,1);
V1_RK = RKAmp02(:,2);
V2_RK = RKAmp02(:,3);

time_ARK = RKAAmp02(:,1);
V1_ARK = RKAAmp02(:,2);
V2_ARK = RKAAmp02(:,3);

%

figure(1);
plot( time_FE , V1_FE , time_FE , V2_FE , 'LineWidth' , 1.5 );
hold on;
plot( time_RK , V1_RK , '--', time_RK , V2_RK , '--' ,'LineWidth' , 1.5 );
plot( time_ARK , V1_ARK ,':', time_ARK , V2_ARK , ':' , 'LineWidth' , 1.5 );
xlim([0 , 100e-9]);
legend('V1 Euler' , 'V2 Euler' , 'V1 RK34' , 'V2 RK34' , 'V1 RK34A' , 'V2 RK34A');
title( 'Amplifier Circuit Solution with March = 0.2ns' , 'FontSize' , 14);
xlabel('Time in seconds' , 'FontSize' , 12 );
ylabel('Output Voltages' , 'FontSize' , 12 );
hold off;

%%
time_FE = FEAmp01(:,1);
V1_FE = FEAmp01(:,2);
V2_FE = FEAmp01(:,3);

time_RK = RKAmp01(:,1);
V1_RK = RKAmp01(:,2);
V2_RK = RKAmp01(:,3);

time_ARK = RKAAmp01(:,1);
V1_ARK = RKAAmp01(:,2);
V2_ARK = RKAAmp01(:,3);

%

figure(2);
plot( time_FE , V1_FE , time_FE , V2_FE , 'LineWidth' , 1.5 );
hold on;
plot( time_RK , V1_RK , '--', time_RK , V2_RK , '--' ,'LineWidth' , 1.5 );
plot( time_ARK , V1_ARK ,':', time_ARK , V2_ARK , ':' , 'LineWidth' , 1.5 );
xlim([0 , 100e-9]);
legend('V1 Euler' , 'V2 Euler' , 'V1 RK34' , 'V2 RK34' , 'V1 RK34A' , 'V2 RK34A');
title( 'Amplifier Circuit Solution with March = 1.0ns' , 'FontSize' , 14);
xlabel('Time in seconds' , 'FontSize' , 12 );
ylabel('Output Voltages' , 'FontSize' , 12 );
hold off;

%%
time_FE = FESimp02(:,1);
V1_FE = FESimp02(:,2);
V2_FE = FESimp02(:,3);

time_RK = RKSimp02(:,1);
V1_RK = RKSimp02(:,2);
V2_RK = RKSimp02(:,3);

time_ARK = RKASimp02(:,1);
V1_ARK = RKASimp02(:,2);
V2_ARK = RKASimp02(:,3);

%

figure(3);
plot( time_FE , V1_FE , time_FE , V2_FE , 'LineWidth' , 1.5 );
hold on;
plot( time_RK , V1_RK , '--', time_RK , V2_RK , '--' ,'LineWidth' , 1.5 );
plot( time_ARK , V1_ARK ,':', time_ARK , V2_ARK , ':' , 'LineWidth' , 1.5 );
xlim([0 , 100e-9]);
legend('V1 Euler' , 'V2 Euler' , 'V1 RK34' , 'V2 RK34' , 'V1 RK34A' , 'V2 RK34A');
title( 'Simple Circuit Solution with March = 0.2ns' , 'FontSize' , 14);
xlabel('Time in seconds' , 'FontSize' , 12 );
ylabel('Output Voltages' , 'FontSize' , 12 );
hold off;

%%
time_FE = FESimp01(:,1);
V1_FE = FESimp01(:,2);
V2_FE = FESimp01(:,3);

time_RK = RKSimp01(:,1);
V1_RK = RKSimp01(:,2);
V2_RK = RKSimp01(:,3);

time_ARK = RKASimp01(:,1);
V1_ARK = RKASimp01(:,2);
V2_ARK = RKASimp01(:,3);

%%

figure(4);
plot( time_FE , V1_FE , time_FE , V2_FE , 'LineWidth' , 1.5 );
hold on;
plot( time_RK , V1_RK , '--', time_RK , V2_RK , '--' ,'LineWidth' , 1.5 );
plot( time_ARK , V1_ARK ,':', time_ARK , V2_ARK , ':' , 'LineWidth' , 1.5 );
xlim([0 , 100e-9]);
legend('V1 Euler' , 'V2 Euler' , 'V1 RK34' , 'V2 RK34' , 'V1 RK34A' , 'V2 RK34A');
title( 'Simple Circuit Solution with March = 1.0ns' , 'FontSize' , 14);
xlabel('Time in seconds' , 'FontSize' , 12 );
ylabel('Output Voltages' , 'FontSize' , 12 );
hold off;

save( 'plotting_variables');
function [current] = generateCurrent(time)
gradient = (0.1e-3)/(1.0e-9);

if ( time >= 1.0e-9 && time <= 10e-9 || time >= 21e-9 && time <= 30e-9 || time >= 41e-9 && time <= 50e-9 || time >= 61e-9 && time <= 70e-9 || time >= 81e-9 && time <= 90e-9 )
		current = 0.1e-3;
elseif ( time >= 11e-9 && time <= 20e-9 || time >= 31e-9 && time <= 40e-9 || time >= 51e-9 && time <= 60e-9 || time >= 71e-9 && time <= 80e-9 || time >= 91e-9 && time <= 100e-9)
        current = 0.0;
elseif ( time >= 0.0 && time < 1.0e-9 )
        current = gradient * time ;
elseif ( time > 10e-9 && time < 11e-9 )
        current = (  0.1e-3 - (gradient * (time - 10e-9)));
elseif ( time > 20e-9 && time < 21e-9 )
		current = ( gradient * (time - 20e-9) );
elseif ( time > 30e-9 && time < 31e-9 )
		current = (  0.1e-3 - (gradient * (time - 30e-9)));
elseif ( time > 40e-9 && time < 41e-9 )
		current =  ( gradient * (time - 40e-9) );
elseif ( time > 50e-9 && time < 51e-9 )
		current = (  0.1e-3 - (gradient * (time - 50e-9)));
elseif ( time > 60e-9 && time < 61e-9 )
		current =  ( gradient * (time - 60e-9) );
elseif ( time > 70e-9 && time < 71e-9 )
		current = (  0.1e-3 - (gradient * (time - 70e-9)));
elseif ( time > 80e-9 && time < 81e-9 )
		current =  ( gradient * (time - 80e-9) );
elseif ( time > 90e-9 && time < 91e-9 )
		current = (  0.1e-3 - (gradient * (time - 90e-9)));
end
end


# ECE4960-PA4 - Programming Assignment 4 Compact SPICE for ODE Solutions

**Summary**
This program focuses on building ODE solvers for SPICE-like circuit simulation. Three different one-step solvers (Euler, Standard Runge-Kutta, and Adaptive Runge-Kutta) were built and tested. The main program builds all relevant functions in the C++ language. A succint implementation on MATLAB is included to cross-check that the values obtained are accurate.

***************************************************************************
### Usage
***************************************************************************
The program is simple to use for user's looking to run individual runs to generate results to solve a specific system's ODEs with various ODE Solver methods. To run the program it takes the standard format:

**`./program Argument#1 - Argument#2 - Argument#3`**

- **Argument#1**: Pick the ODE Solver method to use
    - `ForwardEuler`, `RK34`, `RK34A`
    - `TEST` --> sending the argument only will run the test mode
- **Argument#2**: Pick the system to solve
    - `Exponential`, `Simple`, `Amplifier`
- **Argument#3**: Pick the size of the time step
    - `1`, `0.2`

***************************************************************************
### Part 0 - Utility Functions
***************************************************************************
**Overview:** Common utility functions that will be accessed and used commonly throughout the assignment. All functions have been resused from previous programming assignments.

**Documentation:**
- `add_vectors( a , b , sum )`: element-wise addition of vectors `a` and `b` with result being stored in `sum`
- `scaleVector( scalar , a , result )`: multiplies vector `a` by a constant `scalar` and stores it in `result`
- `shiftVector( scalar , a , result )`: adds a constant `scalar` to vector `a` and stores it in `result`
- `expVector( result , input )`: takes the element-wise exponential of the elements in `input` and stores it in `result`
- `vectorMultiplication ( a , b , result )`: element-wise multiplication of vectors `a` and `b`
- `vectorProduct( results , A , b )`: matrix product of a matrix `A` and a vector `b`
- `print_full_vec( a )`: prints all elements in vector `a` to screen
- `calculateNorm ( a )`: calculates the norm of vector `a`

***************************************************************************
### Part 1 - Differential Functions
***************************************************************************
**Overview:** Implementation of ODE functions that will be solved using the three methods discussed in Part 2.

**Documentation:**
All functions have to create/ call the standard function signature:
- `phi`: `vector<double>` for storing the slope of the function at the current time step
- `xi`: `vector<double` for sending the values of the function at the current time step
- `time`: `double` value for sending the current time step
- `march`: `double` value for sending the time interval (march) value at each iteration

**`exponential_function()`**: exponential test function as detailed in the hacker practices

**`simple_RC_circuit()`**: differential equations for simple circuit given in Figure 03 of handout

**`amplifier_circuit()`**: differential equations for common source amplifier given in Figure 5a of handout

Other helper functions:
- `generate_current_input( time )`: returns the current at the given `time`, following the function given in Figure 6
- `calculate_ID( vgs , vds )`: returns the ID,EKF current for the given parameters, as defined in Equation 1 of the handout - reused from Programming Assignment 03

Testing functions:
- `test_current_generator()`: testing function to check that `generate_current_input( time )` returns the correct values
- `test_simple_RC_circuit()`: testing function to check that `simple_RC_circuit()` returns the correct values - values are cross-referenced with the MATLAB implementation
- `test_amplifier_circuit()`: testing function to check that the `amplifier_circuit()` returns the correct values - values are cross-referenced with the MATLAB implementation

***************************************************************************
### Part 2 - ODE Solver Methods
***************************************************************************
**Overview:** Implementation of ODE Solver methods that solve the systems defined in Part 1.

**Documentation:**
All functions have to create/ call the these variables:
- `*function`: for passing the phi function that corresponds to the system that will be solved (i.e. simple_RC_circuit())
- `slope`: `vector<double>` for storing the slope (phi) of the function at the current time step
- `values`: `vector<double` for sending the (current) values to the function to calculate the next iterative values
- `time`: `double` value for sending the current time step (t)
- `march`: `double` value for sending the time interval (h) value at each iteration

**`forward_euler()`**: solves for phi at each time step using the forward euler method and the system's ODE given as a pointer.

The Runge Kutta method functions have to create/ call these additional variables:
- `k1`, `k2`, `k3`, `k4`: `vector<double>` for calculating the intermediate k values to calculate the `phi` at each time step
- `adaptivity`: `bool` to decide when to enable adaptive time steps, which calculats the new time step size using the k values, x_i+1, and a relative error of 1e-4

**`RK34_function()`**: solves for phi at each time step using the Runge Kutta 3-4 method and the system's ODE given as a pointer.

**`ODE_Solver()`**: solves x_i+1 for given the current time step, and calculates `phi` using the function pointer which provided based which system is being solved.

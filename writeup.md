# PID Controller
The project goal is to build a PID controller in C++ which is able to drive the vehicle around lake track. This PID controller takes into account proportional, integral and differencial parameter values.

## P, I, D Coefficients:
- P, Proportional parameter increases or decreases contorl signal proportional to the error. It can cause oscillations is the system.
- I, Integral parameter is used to counter bias in the system. When error is increased due to system bias, control signal is increased to minimize error.
- D, Derivative parameter is related with change of error in the system. To reduce oscillations in the system we use this parameter to reduce overshoot.

## Parameter optimization
I changed parameters one by one to see the effect of each parameter.
When only P coefficient is used, car goes off track while having big oscillations.
* [Only P](https://youtu.be/WRxlR14LhM0) - Modify only P coefficient Video

When only I coefficient is used, car goes off track immediately.
* [Only I](https://youtu.be/8tTRnS-T-k4) - Modify only I coefficient Video

When only D cofficient is used, there are no oscillations but car goes off track after driving in straight line for a while.
* [Only D](https://youtu.be/8NFU_hwcNHU) - Modify only D coefficient Video

### Final Hyperparameters
I used manual tuning to find final PID hyperparameters.
My approach was as under for selection of P,I,D parameters
```
0.3 0.0 0.0 // Car goes off track
0.0 0.3 0.0 // Car goes off track
0.0 0.0 0.3 // Car goes off track
0.3 0.01 0.3 // Car goes off track
0.3 0.01 0.8 // oscillations reduced, still car goes off track
0.3 0.01 1.8 // Car goes off track
0.3 0.01 2.8 // loop ok, fine tune more
-0.5 0.01 2.8 // Car goes off track
0.5 0.01 2.8 // Car goes off track
0.2 0.01 3.5 // drive ok
```
Video of full loop around lake track is uploaded as below:
[PID Video](https://youtu.be/LcCktYCkGwA) - Final coefficient optimization video 
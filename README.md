# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
Author: *Igor Passchier*
Email: *igor.passchier@tassinternational.com*

---
## Introduction

This README follows the Project rubric.

## Compilation
### Code should compile
The code compiles with cmake and make, as described. This has been tested on a mac with latest OS and latest version of Xcode and command line tools.

## Implementation
### The PID procedure follows what was taught in the lesson
The PID controller is implemented in line with the theory described in the lesson. The errors are stored in the PID controler already taking into account the control constants. It would have been just as well possible to apply the constants only when the total error is calculated.

## Reflection
### Describe the effect of PID

Two PID controllers are implemented, one for steering, one for throttle. The steering PID is similar to the PID developed in python in the lesson. The P component is the basis of the controller. The larger the Kp, the faster the car is steered back to the central line. However, this also causes overshoot. The overshoot is cancelled by the D term. The PID controller does not take into account the time step, so effectively the Kd constant has to compensate for the timestep. In the lesson, the timestep was 1, here it is 0.1. That means that the ratio between Kp and Pd should be a factor 10 different than in the lesson. The steering seems not to have a big bias in itself, so the Ki term could be kept small/zero. However, as we go around in one direction, we effectively still have a bias, as on average we should be steering to the left. Similarly as to the D component, also the I component need to compensate the timestep in the constant Ki. In this case, scaled in the opposite direction.

The effect of the various terms is similar for the PID controller for the speed.

### Describe how the final hyperparameters were chosen
The PID controller for the steering was first initialized based on the twiddle optimized values of the PID controller from the lesson, taking into account the scaling due to the update frequency differences. Afterwards, the parameters where tuned visually via the simulator. Also, an average error parameter was calculated, and roughly checked what that was after a full lap. the Kp term was increased to get the car faster to the center line, D to reduce the oscilations, and I to finally get the lowest possible value for the average error after a full lap. Parameter changes where made in a similar way as twiddle would do.

I would have liked to do a real twiddle optimization, but I had no effective way to control and restart the simulator, and to determine when a full lap was reached. 

The final result would make me sick if I would have to sit in the car. The driving can be made much more smooth by reducing all parameter values, but then the car will not make the sharp corners. People would brake at the corners, and see them coming, but this simple controller does not see the curves coming. So the P term needs to be large enough to make it through the curves.

The PID controller for the throttle was optimized in a similar was. In the first part, it overshoots, because the I term blows up because the car starts at a stand still. This could be overcome by having a more advanced controller, where e.g. the I term would not be taken into account during initial acceleration. This would mean that not the same PID controller could have been used. Therefore, I have not done this.

The setspeed also can be tuned. I have experimented with several values. It is very well possible to tune the steering PID properly for any values below 40 Mph. I have arbitrary choosen 30 Mph. Higher than 40 Mph makes the steering very unstable, and the car goes out of the track, as would a normal car also do if it tries to go around the track at such high speeds.

## Simulation
### The vehicle must successfully drive around the track
With the current settings, the car drives nicely around the track. In some corners it is tight and it is possible to keep the car better in the center in the curves, but that would mean less smooth driving on the rest of the track. Although that is not part of the criteria, I still choose settings that resulted in more smooth driving.



#include "PID.h"

#include "algorithm"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  // Previous CTE
  previous_cte = 0.0;
    
  // Counter
  //counter = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  // Proportional Error
  p_error = cte;
  
  // Integral Error
  i_error += cte;
  
  // Differential Error
  d_error = cte - previous_cte;
  previous_cte = cte;
  
  //counter++;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error * Kp + i_error * Ki + d_error * Kd;  // TODO: Add your total error calc here!
}

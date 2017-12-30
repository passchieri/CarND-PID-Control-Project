#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd){
  this->Kp=Kp;
  this->Kd=Kd;
  this->Ki=Ki;
  first=true;
}

void PID::UpdateError(double cte) {
  p_error=-Kp*cte;
  i_error-=Ki*cte;
  if (first) {
    prev_cte=cte;
    first=false;
  }
  d_error=-Kd*(cte-prev_cte);
  prev_cte=cte;
}

double PID::TotalError() {
  return p_error+i_error+d_error;
}


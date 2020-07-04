void F_ccw()
{
   
   if (F_pulse_error < -1 )
      {
         F_correction = abs(F_pulse_error) * F_Kp + (F_last_error - abs(F_pulse_error) ) * F_Kd / F_dt + F_sum_error * F_Ki * F_dt;
         if (F_correction > max_speed) F_correction = max_speed;
         if (F_correction < 0 ) F_correction = 0;
         if (F_sum_error<F_anti_windup) F_sum_error = F_sum_error + abs(F_pulse_error);
       
         if (F_sum_error >  F_anti_windup ) F_sum_error = F_sum_error;
         F_last_error = abs (F_pulse_error);

        digitalWrite (F_dir_pin, LOW);
        analogWrite (F_pwm_pin,F_correction );
      }
           if (F_pulse_error>-1 && F_pulse_error<0)
      {

        digitalWrite (F_dir_pin, LOW);
        analogWrite (F_pwm_pin, 0);
      }
      


}

void F_cw ()
{
  
  
      if (F_pulse_error> 1)
      {
        F_correction = abs(F_pulse_error) * F_Kp + (F_last_error - abs(F_pulse_error) ) * F_Kd / F_dt + F_sum_error * F_Ki * F_dt;
         if (F_correction > max_speed) F_correction = max_speed;
         if (F_correction < 0 ) F_correction = 0;
         if (F_sum_error<F_anti_windup) F_sum_error = F_sum_error + abs(F_pulse_error);
         if (F_sum_error >  F_anti_windup ) F_sum_error = F_sum_error;
         F_last_error = abs (F_pulse_error);
         
        digitalWrite (F_dir_pin, HIGH);
        analogWrite (F_pwm_pin,F_correction );
      }
     if (F_pulse_error<2 && F_pulse_error>0)
      
      {
        digitalWrite (F_dir_pin, HIGH);
        analogWrite (F_pwm_pin, 0);
      }
       
}


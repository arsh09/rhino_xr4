void C_cw()
{
   
   if (C_pulse_error > 1 )
      {
         C_correction = abs(C_pulse_error) * C_Kp + (C_last_error - abs(C_pulse_error) ) * C_Kd / C_dt + C_sum_error * C_Ki * C_dt;
         if (C_correction > max_speed) C_correction = max_speed;
         if (C_correction < 0 ) C_correction = 0;
         if (C_sum_error<C_anti_windup) C_sum_error = C_sum_error + abs(C_pulse_error);
         if (C_sum_error >  C_anti_windup ) C_sum_error = C_sum_error;
         C_last_error = abs (C_pulse_error);

        digitalWrite (C_dir_pin, HIGH);
        analogWrite (C_pwm_pin,C_correction );
      }
           if (C_pulse_error < 1 && C_pulse_error > -1)
      {

        digitalWrite (C_dir_pin, HIGH);
        analogWrite (C_pwm_pin, 0);
      }
      


}

void C_ccw ()
{
  
  
      if (C_pulse_error < -1)
      {
         C_correction = abs(C_pulse_error) * C_Kp + (C_last_error - abs(C_pulse_error) ) * C_Kd / C_dt + C_sum_error * C_Ki * C_dt;
         if (C_correction > max_speed) C_correction = max_speed;
         if (C_correction < 0 ) C_correction = 0;
         if (C_sum_error<C_anti_windup) C_sum_error = C_sum_error + abs(C_pulse_error);
         if (C_sum_error >  C_anti_windup ) C_sum_error = C_sum_error;
         C_last_error = abs (C_pulse_error);
         
        digitalWrite (C_dir_pin, LOW);
        analogWrite (C_pwm_pin,C_correction );
      }
     if (C_pulse_error > - 2 && C_pulse_error < 0)
      
      {
        digitalWrite (C_dir_pin, LOW);
        analogWrite (C_pwm_pin, 0);
      }
       
}


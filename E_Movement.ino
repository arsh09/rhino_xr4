void E_ccw()
{
   
   if (E_pulse_error < -1 )
      {/*
         E_correction = abs(E_pulse_error) * E_Kp + (E_last_error -abs( E_pulse_error )) * E_Kd / E_dt + E_sum_error * E_Ki * E_dt;
         if (E_correction > max_speed) E_correction = max_speed;
         if (E_correction < 0 ) E_correction = 0;
         if (E_sum_error<E_anti_windup) E_sum_error = E_sum_error +abs( E_pulse_error);
         if (E_sum_error >  E_anti_windup ) E_sum_error = E_sum_error;
         E_last_error = abs (E_pulse_error);*/

        digitalWrite (E_dir_pin, LOW);
        analogWrite (E_pwm_pin,255 );
      }
           if (E_pulse_error > -2 && E_pulse_error < 0)
      {

        digitalWrite (E_dir_pin, HIGH);
        analogWrite (E_pwm_pin, 0);
      }
      


}

void E_cw ()
{
  
  
      if (E_pulse_error > 1)
      {/*
        E_correction = abs(E_pulse_error) * E_Kp + (E_last_error -abs( E_pulse_error )) * E_Kd / E_dt + E_sum_error * E_Ki * E_dt;
         if (E_correction > max_speed) E_correction = max_speed;
         if (E_correction < 0 ) E_correction = 0;
         if (E_sum_error<E_anti_windup) E_sum_error = E_sum_error + abs(E_pulse_error);
         if (E_sum_error >  E_anti_windup ) E_sum_error = E_sum_error;
         E_last_error = abs (E_pulse_error);
         */
         
        digitalWrite (E_dir_pin, HIGH);
        analogWrite (E_pwm_pin,255 );
      }
     if (E_pulse_error  < 1 && E_pulse_error > 0)
      
      {
        digitalWrite (E_dir_pin, LOW);
        analogWrite (E_pwm_pin, 0);
      }
       
}


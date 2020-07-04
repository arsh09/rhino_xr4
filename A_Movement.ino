void A_ccw()
{
   
   if (A_pulse_error > 1 )
      {
         A_correction = abs(A_pulse_error) * A_Kp + (A_last_error - abs(A_pulse_error )) * A_Kd / A_dt + A_sum_error * A_Ki * A_dt;
         if (A_correction > max_speed) A_correction = max_speed;
         if (A_correction < 0 ) A_correction = 0;
         if (A_sum_error<A_anti_windup) A_sum_error = A_sum_error + abs(A_pulse_error);
         if (A_sum_error >  A_anti_windup ) A_sum_error = A_sum_error;
         A_last_error = abs (A_pulse_error);

        digitalWrite (A_dir_pin, LOW);
        analogWrite (A_pwm_pin,A_correction );
      }
           if (A_pulse_error < 1 && A_pulse_error > 0)
      {

        digitalWrite (A_dir_pin, LOW);
        analogWrite (A_pwm_pin, 0);
      }
}

void A_cw ()
{

      if (A_pulse_error < -1)
      {
         A_correction = abs(A_pulse_error) * A_Kp + (A_last_error - abs(A_pulse_error )) * A_Kd / A_dt + A_sum_error * A_Ki * A_dt;
         if (A_correction > max_speed) A_correction = max_speed;
         if (A_correction < 0 ) A_correction = 0;
         if (A_sum_error<A_anti_windup) A_sum_error = A_sum_error + abs(A_pulse_error);
         if (A_sum_error >  A_anti_windup ) A_sum_error = A_sum_error;
         A_last_error = abs (A_pulse_error);
         
        digitalWrite (A_dir_pin, HIGH);
        analogWrite (A_pwm_pin,A_correction );
      }
     if (A_pulse_error > - 2 && A_pulse_error < 0)
      
      {
        digitalWrite (A_dir_pin, HIGH);
        analogWrite (A_pwm_pin, 0);
      }
       
}


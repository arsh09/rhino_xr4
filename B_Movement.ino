void B_ccw()
{
   
   if (B_pulse_error > 1 )
      {
         B_correction = abs(B_pulse_error )* B_Kp + (B_last_error - abs(B_pulse_error )) * B_Kd / B_dt + B_sum_error * B_Ki * B_dt;
         if (B_correction > max_speed) B_correction = max_speed;
         if (B_correction < 0 ) B_correction = 0;
         if (B_sum_error<B_anti_windup) B_sum_error = B_sum_error + abs(B_pulse_error);
         if (B_sum_error >  B_anti_windup ) B_sum_error = B_sum_error;
         B_last_error = abs (B_pulse_error);

        digitalWrite (B_dir_pin, LOW);
        analogWrite (B_pwm_pin, B_correction );
      }
           if (B_pulse_error < 1 && B_pulse_error > 0)
      {

        digitalWrite (B_dir_pin, LOW);
        analogWrite (B_pwm_pin, 0);
      }
      


}

void B_cw ()
{
  
  
      if (B_pulse_error < -1)
      {
        B_correction = abs(B_pulse_error) * B_Kp + (B_last_error - abs(B_pulse_error )) * B_Kd / B_dt + B_sum_error * B_Ki * B_dt;
         if (B_correction > max_speed) B_correction = max_speed;
         if (B_correction < 0 ) B_correction = 0;
         if (B_sum_error<B_anti_windup) B_sum_error = B_sum_error + abs(B_pulse_error);
         if (B_sum_error >  B_anti_windup ) B_sum_error = B_sum_error;
         B_last_error = abs (B_pulse_error);
         
        digitalWrite (B_dir_pin, HIGH);
        analogWrite (B_pwm_pin,B_correction );
      }
     if (B_pulse_error > - 2 && B_pulse_error < 0)
      
      {
        digitalWrite (B_dir_pin, LOW);
        analogWrite (B_pwm_pin, 0);
      }
       
}


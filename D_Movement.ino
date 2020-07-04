void D_cw()
{
   
   if (D_pulse_error > 1 )
      {
         D_correction = abs(D_pulse_error) * D_Kp + (D_last_error - abs(D_pulse_error) ) * D_Kd / D_dt + D_sum_error * D_Ki * D_dt;
         if (D_correction > max_speed) D_correction = max_speed;
         if (D_correction < 0 ) D_correction = 0;
         if (D_sum_error<D_anti_windup) D_sum_error = D_sum_error + abs(D_pulse_error);
       
         if (D_sum_error >  D_anti_windup ) D_sum_error = D_sum_error;
         D_last_error = abs (D_pulse_error);

        digitalWrite (D_dir_pin, LOW);
        analogWrite (D_pwm_pin,D_correction );
      }
           if (D_pulse_error < 1 && D_pulse_error > 0)
      {

        digitalWrite (D_dir_pin, HIGH);
        analogWrite (D_pwm_pin, 0);
      }
     
}

void D_ccw ()
{
  
  
      if (D_pulse_error < -1)
      {
        D_correction = abs(D_pulse_error) * D_Kp + (D_last_error - abs(D_pulse_error) ) * D_Kd / D_dt + D_sum_error * D_Ki * D_dt;
         if (D_correction > max_speed) D_correction = max_speed;
         if (D_correction < 0 ) D_correction = 0;
         if (D_sum_error<D_anti_windup) D_sum_error = D_sum_error + abs(D_pulse_error);
         if (D_sum_error >  D_anti_windup ) D_sum_error = D_sum_error;
         D_last_error = abs (D_pulse_error);
         
        digitalWrite (D_dir_pin, HIGH);
        analogWrite (D_pwm_pin,D_correction );
      }
     if (D_pulse_error > - 2 && D_pulse_error < 0)
      
      {
        digitalWrite (D_dir_pin, LOW);
        analogWrite (D_pwm_pin, 0);
      }
       
}


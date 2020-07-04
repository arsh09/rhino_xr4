
void Rhino_Home_Position()
{
  while (digitalRead (F_switch_pin) == HIGH || digitalRead (E_switch_pin) == HIGH || digitalRead (D_switch_pin) == HIGH || digitalRead (C_switch_pin) == HIGH ||  digitalRead (B_switch_pin) == HIGH ||digitalRead (A_switch_pin) == HIGH )
  {
    if (digitalRead (F_switch_pin) == HIGH )
    F_Home_Position();
    if (digitalRead (D_switch_pin) == HIGH )
    D_Home_Position();
    if (digitalRead (E_switch_pin) == HIGH )
    E_Home_Position();
    if (digitalRead (C_switch_pin) == HIGH )
    C_Home_Position();
    if (digitalRead (B_switch_pin) == HIGH )
    B_Home_Position();
    if (digitalRead (A_switch_pin) == HIGH )
    A_Home_Position();
  }
}



void F_Home_Position()
{
    while (digitalRead (F_switch_pin) == HIGH)
  {
    while (abs(F_cw_difference) > 0  && digitalRead (F_switch_pin)== HIGH)
    // This condition tells the controller that the motor is yet not at it's extreme clockwise position.
    // and keeps the track of Home position button. If either condition fails, control is out of the loop! :)
    
     {
      digitalWrite (F_dir_pin, HIGH);   
      analogWrite (F_pwm_pin, 255);
      F_last_counter = F_counter;
      delay (200);                       
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
     F_cw_difference = F_counter - F_last_counter;
   
     
   }
    
      digitalWrite (F_dir_pin, LOW);  // CCW Movement   
      analogWrite (F_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
      
      
  }

  delay (150);
  analogWrite (F_pwm_pin, 0);
  F_counter = 0;
 
}


void E_Home_Position()
{
    while (digitalRead (E_switch_pin) == HIGH)
  {
    while (abs(E_cw_difference) > 0  && digitalRead (E_switch_pin)== HIGH)
    // This condition tells the controller that the motor is yet not at it's extreme clockwise position.
    // and keeps the track of Home position button. If either condition fails, control is out of the loop! :)
    
     {
      digitalWrite (E_dir_pin, LOW);   
      analogWrite (E_pwm_pin, 255);
      E_last_counter = E_counter;
      delay (200);                       
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
     E_cw_difference = E_counter - E_last_counter;
      
     
   }
    
      digitalWrite (E_dir_pin, HIGH);  // CCW Movement   
      analogWrite (E_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
      
      
  }

  delay (150);
  analogWrite (E_pwm_pin, 0);
  E_counter = -1040;
}



void D_Home_Position()
{
    while (digitalRead (D_switch_pin) == HIGH)
  {
    while (abs(D_cw_difference) > 0  && digitalRead (D_switch_pin)== HIGH)
    // This condition tells the controller that the motor is yet not at it's extreme clockwise position.
    // and keeps the track of Home position button. If either condition fails, control is out of the loop! :)
    
     {
      digitalWrite (D_dir_pin, HIGH);   
      analogWrite (D_pwm_pin, 255);
      D_last_counter = D_counter;
      delay (200);                       
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
     D_cw_difference = D_counter - D_last_counter;
      
     
   }
    
      digitalWrite (D_dir_pin, LOW);  // CCW Movement   
      analogWrite (D_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
      
      
  }

  delay (100);
  analogWrite (D_pwm_pin, 0);
  D_counter = 1170;
 }


void C_Home_Position()
{
  
      digitalWrite (C_dir_pin, LOW);   
      analogWrite (C_pwm_pin, 255);      
      delay (3000);                       
       while (digitalRead (C_switch_pin) == HIGH)
  {
      digitalWrite (C_dir_pin, HIGH);  // CCW Movement   
      analogWrite (C_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
  }  

  delay (150);
  analogWrite (C_pwm_pin, 0);
  C_counter = 0;
 
}


void B_Home_Position()
{
    while (digitalRead (B_switch_pin) == HIGH)
  {
    while (abs(B_cw_difference) > 0  && digitalRead (B_switch_pin)== HIGH)
    // This condition tells the controller that the motor is yet not at it's extreme clockwise position.
    // and keeps the track of Home position button. If either condition fails, control is out of the loop! :)
    
     {
      digitalWrite (B_dir_pin, HIGH);   
      analogWrite (B_pwm_pin, 255);
      B_last_counter = B_counter;
      delay (200);                       
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
     B_cw_difference = B_counter - B_last_counter;
 
     
   }
    
      digitalWrite (B_dir_pin, LOW);  // CCW Movement   
      analogWrite (B_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
      
      
  }

  delay (150);
  analogWrite (B_pwm_pin, 0);
  B_counter = 0;
 
}



void A_Home_Position()
{
    while (digitalRead (A_switch_pin) == HIGH)
  {
    while (abs(A_cw_difference) > 0  && digitalRead (A_switch_pin)== HIGH)
    // This condition tells the controller that the motor is yet not at it's extreme clockwise position.
    // and keeps the track of Home position button. If either condition fails, control is out of the loop! :)
    
     {
      digitalWrite (A_dir_pin, LOW);   
      analogWrite (A_pwm_pin, 255);
      A_last_counter = A_counter;
      delay (200);                       
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
     A_cw_difference = A_counter - A_last_counter;
 
     
   }
    
      digitalWrite (A_dir_pin, HIGH);  // CCW Movement   
      analogWrite (A_pwm_pin, 255);
      // This delay ensures that the values in the last counter and current counter don't equal due to speed of controller.
      
      
  }

  delay (150);
  analogWrite (A_pwm_pin, 0);
  A_counter = 0;
 
}


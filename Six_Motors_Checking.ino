

// Pins Declaration
const int F_enc_a = 18;
const int F_enc_b = 47;
const int F_pwm_pin = 9;
const int F_dir_pin = 27;
const int F_switch_pin = 49;

const int E_enc_a = 19;
const int E_enc_b = 51;
const int E_pwm_pin = 10;
const int E_dir_pin = 31;
const int E_switch_pin = 53;

const int D_enc_a = 20;
const int D_enc_b = 44;
const int D_pwm_pin = 12;
const int D_dir_pin = 11;
const int D_switch_pin = 42;

const int C_enc_a = 21;
const int C_enc_b = 40;
const int C_pwm_pin = 13;
const int C_dir_pin = 37;
const int C_switch_pin = 38;

const int B_enc_a = 3;
const int B_enc_b = 39;
const int B_pwm_pin = 8;
const int B_dir_pin = 25;
const int B_switch_pin = 41;

const int A_enc_a = 2;
const int A_enc_b = 43;
const int A_pwm_pin = 7;
const int A_dir_pin = 22;
const int A_switch_pin = 45;

const int D1 = 23;
const int D2 = 35;
const int D3 = 29;



// Variable declaration for each ISR
volatile int F_counter = 0;
volatile int E_counter = -1040;
volatile int D_counter = 1170;
volatile int C_counter = 0;
volatile int B_counter = 0;
volatile int A_counter = 0;



// Variables declaration for Each HP
int F_last_counter = 0;
int F_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int F_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH

int E_last_counter = 0;
int E_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int E_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH

int D_last_counter = 0;
int D_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int D_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH

int C_last_counter = 0;
int C_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int C_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH

int B_last_counter = 0;
int B_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int B_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH

int A_last_counter = 0;
int A_cw_difference = -1;  // The value is -1 just to enter into the first nested While loop if Switch is HIGH
int A_ccw_difference = 1;  // The value is +1 just to enter into the second nested While loop if Switch is HIGH



// Variable Declaration for counter pulses using Serial
int F_pulses_receive = 0;
int E_pulses_receive = 0;
int D_pulses_receive = 0;
int C_pulses_receive = 0;
int B_pulses_receive = 0;
int A_pulses_receive = 0;

// Variables for Synchronization in Serial
int initial_sync = 0;
int final_sync = 0;

// Variables for each motor's pulses error
int F_pulse_error = 0;
int E_pulse_error = 0;
int D_pulse_error = 0;
int C_pulse_error = 0;
int B_pulse_error = 0;
int A_pulse_error = 0;


int initial  = 0;
int final = 0;
int i = 0;



float A_Kp = 10, A_Ki = 0.5, A_Kd = 0;
float A_sum_error = 0, A_last_error = 0;
float A_anti_windup = 20000;
float A_correction = 0;
float A_dt = 0.001;

float B_Kp = 10, B_Ki = 0.5, B_Kd = 0;
float B_sum_error = 0, B_last_error = 0;
float B_anti_windup = 20000;
float B_correction = 0;
float B_dt = 0.001;

float C_Kp = 10, C_Ki = 0.5, C_Kd = 0;
float C_sum_error = 0, C_last_error = 0;
float C_anti_windup = 20000;
float C_correction = 0;
float C_dt = 0.001;

float D_Kp = 10, D_Ki = 0.5, D_Kd = 0;
float D_sum_error = 0, D_last_error = 0;
float D_anti_windup = 20000;
float D_correction = 0;
float D_dt = 0.001;

float E_Kp = 10, E_Ki = 0.5, E_Kd = 0;
float E_sum_error = 0, E_last_error = 0;
float E_anti_windup = 20000;
float E_correction = 0;
float E_dt = 0.001;

float F_Kp = 10, F_Ki = 0.5, F_Kd = 0;
float F_sum_error = 0, F_last_error = 0;
float F_anti_windup = 20000;
float F_correction = 0;
float F_dt = 0.001;
int max_speed = 255;




void setup ()
{
  pinMode (F_enc_a, INPUT);
  pinMode (F_enc_b, INPUT_PULLUP);
  pinMode (F_switch_pin, INPUT_PULLUP);
  pinMode (F_pwm_pin, OUTPUT);
  pinMode (F_dir_pin, OUTPUT);

  pinMode (E_enc_a, INPUT);
  pinMode (E_enc_b, INPUT_PULLUP);
  pinMode (E_switch_pin, INPUT_PULLUP);
  pinMode (E_pwm_pin, OUTPUT);
  pinMode (E_dir_pin, OUTPUT);

  pinMode (D_enc_a, INPUT);
  pinMode (D_enc_b, INPUT_PULLUP);
  pinMode (D_switch_pin, INPUT_PULLUP);
  pinMode (D_pwm_pin, OUTPUT);
  pinMode (D_dir_pin, OUTPUT);


  pinMode (C_enc_a, INPUT);
  pinMode (C_enc_b, INPUT_PULLUP);
  pinMode (C_switch_pin, INPUT_PULLUP);
  pinMode (C_pwm_pin, OUTPUT);
  pinMode (C_dir_pin, OUTPUT);

  pinMode (B_enc_a, INPUT);
  pinMode (B_enc_b, INPUT_PULLUP);
  pinMode (B_switch_pin, INPUT_PULLUP);
  pinMode (B_pwm_pin, OUTPUT);
  pinMode (B_dir_pin, OUTPUT);

  pinMode (A_enc_a, INPUT);
  pinMode (A_enc_b, INPUT_PULLUP);
  pinMode (A_switch_pin, INPUT_PULLUP);
  pinMode (A_pwm_pin, OUTPUT);
  pinMode (A_dir_pin, OUTPUT);


  pinMode (D1, OUTPUT);
  digitalWrite (D1, HIGH);   // D1 and D2 are 'Disabled Driver' Pins. Both are HIGH so both drivers will work.
  pinMode (D2, OUTPUT);
  digitalWrite (D2, HIGH);
  pinMode (D3, OUTPUT);
  digitalWrite (D3, HIGH);

  // Interrupt Declaration for Rising on Signal A's of all Encoders
  attachInterrupt (5, F_count, RISING);
  attachInterrupt (4, E_count, RISING);
  attachInterrupt (3, D_count, RISING);
  attachInterrupt (2, C_count, RISING);
  attachInterrupt (1, B_count, RISING);
  attachInterrupt (0, A_count, RISING);


  // Opening the serial port
  Serial.begin (115200);

  {
  }

}


void loop ()
{


  while (Serial.available ()  )
  {

    initial = Serial.parseInt ();
    F_pulses_receive = Serial.parseFloat ();
    E_pulses_receive = Serial.parseFloat ();
    D_pulses_receive = Serial.parseFloat ();
    C_pulses_receive = Serial.parseFloat ();
    B_pulses_receive = Serial.parseFloat ();
    A_pulses_receive = Serial.parseFloat ();
    max_speed = Serial.parseInt ();
    final = Serial.parseInt ();

    if (C_pulses_receive > 90)
      C_pulses_receive = 90;

    if (C_pulses_receive < -1900)
      C_pulses_receive = -1900;
    
    if (initial == 0 && final == 1)
    {

    for (i = 0 ; i < 1; i++)
      {
        Rhino_Home_Position ();
      }

      Serial.print (F_counter);
      Serial.print ("a");
      Serial.print (F_pulse_error);
      Serial.print ("b");
      Serial.print (E_counter);
      Serial.print ("c");
      Serial.print (E_pulse_error);
      Serial.print ("d");
      Serial.print (D_counter);
      Serial.print ("e");
      Serial.print (D_pulse_error);
      Serial.print ("f");
      Serial.print (C_counter);
      Serial.print ("g");
      Serial.print (C_pulse_error);
      Serial.print ("h");
      Serial.print (B_counter);
      Serial.print ("i");
      Serial.print (B_pulse_error);
      Serial.print ("j");
      Serial.print (A_counter);
      Serial.print ("k");
      Serial.print (A_pulse_error);
      Serial.print ("l");
    //  delay (5);


    }
    

    if (initial == 1 && final == 1)
    {
      F_pulse_error =   F_pulses_receive - F_counter ;
      D_pulse_error =   D_pulses_receive -  D_counter;
      E_pulse_error =   E_pulses_receive -  E_counter ;
      C_pulse_error =   C_pulses_receive -  C_counter  ;
      B_pulse_error =   B_counter - B_pulses_receive;
      A_pulse_error =   A_pulses_receive  - A_counter ;



      if (F_pulse_error < 4 && F_pulse_error > -4)
      {
        digitalWrite (F_dir_pin, LOW);
        analogWrite (F_pwm_pin, 0);
      }

      if (F_pulse_error > 4)
        F_cw();
      if (F_pulse_error < -4)
        F_ccw();

      if (E_pulse_error < 8 && E_pulse_error > -8)
      {
        digitalWrite (E_dir_pin, LOW);
        analogWrite (E_pwm_pin, 0);
      }

      if (E_pulse_error > 8)
        E_cw();
      if (E_pulse_error < -8)
        E_ccw();

      if (D_pulse_error < 8 && D_pulse_error > -8)
      {
        digitalWrite (D_dir_pin, LOW);
        analogWrite (D_pwm_pin, 0);
      }

      if (D_pulse_error < -8)
        D_ccw();
      if (D_pulse_error > 8)
        D_cw();

      if (C_pulse_error < 6 && C_pulse_error > -6)
      {
        digitalWrite (C_dir_pin, LOW);
        analogWrite (C_pwm_pin, 0);
      }

      if (C_pulse_error <  -6)
        C_ccw();
      if (C_pulse_error >  6)
        C_cw();

      if (B_pulse_error < 3 && B_pulse_error > -3)
      {
        digitalWrite (B_dir_pin, LOW);
        analogWrite (B_pwm_pin, 0);
      }

      if (B_pulse_error > 3)
        B_ccw();
      if (B_pulse_error < -3)
        B_cw();

      if (A_pulse_error < 15 && A_pulse_error > -15)
      {
        digitalWrite (A_dir_pin, LOW);
        analogWrite (A_pwm_pin, 0);
      }

      if (A_pulse_error > 15)
        A_ccw();
      if (A_pulse_error < -15)
        A_cw();

      Serial.print (F_counter);
      Serial.print ("a");
      Serial.print (F_pulse_error);
      Serial.print ("b");
      Serial.print (E_counter);
      Serial.print ("c");
      Serial.print (E_pulse_error);
      Serial.print ("d");
      Serial.print (D_counter);
      Serial.print ("e");
      Serial.print (D_pulse_error);
      Serial.print ("f");
      Serial.print (C_counter);
      Serial.print ("g");
      Serial.print (C_pulse_error);
      Serial.print ("h");
      Serial.print (B_counter);
      Serial.print ("i");
      Serial.print (B_pulse_error);
      Serial.print ("j");
      Serial.print (A_counter);
      Serial.print ("k");
      Serial.print (A_pulse_error);
      Serial.print ("l");
    }
    delay (10);
  }
}




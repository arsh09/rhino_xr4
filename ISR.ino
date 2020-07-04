
void F_count ()
{
  if (digitalRead (F_enc_b) == LOW)
    F_counter--;
  else
    F_counter++;
}

void E_count ()
{
  if (digitalRead (E_enc_b) == LOW)
    E_counter--;
  else
    E_counter++;
}

void D_count ()
{
  if (digitalRead (D_enc_b) == LOW)
    D_counter--;
  else
    D_counter++;
}


void C_count ()
{
  if (digitalRead (C_enc_b) == LOW)
    C_counter--;
  else
    C_counter++;
}

void B_count ()
{
  if (digitalRead (B_enc_b) == LOW)
    B_counter--;
  else
    B_counter++;
}

void A_count ()
{
  if (digitalRead (A_enc_b) == LOW)
    A_counter--;
  else
    A_counter++;
}

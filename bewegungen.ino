// Die folgenden Funktionen lassen den Roboter in eine bestimmte Richtung gehen
// Jede Funktion unterbricht die vorherige Bewegung
void GehenVorwaerts()
{
  g_InControlState.TravelLength.z = 30;
  g_InControlState.TravelLength.y = 0;
  g_InControlState.TravelLength.x = 0;
}
void GehenRueckwaerts()
{
  g_InControlState.TravelLength.x = 0;
  g_InControlState.TravelLength.z = -30;
  g_InControlState.TravelLength.y = 0;
}
void DrehenLinks()
{
  g_InControlState.TravelLength.x = 0;
  g_InControlState.TravelLength.z = 0;
  g_InControlState.TravelLength.y = 7;
}
void DrehenRechts()
{
  g_InControlState.TravelLength.x = 0;
  g_InControlState.TravelLength.z = 0;
  g_InControlState.TravelLength.y = -7;
}
void GehenRechts()
{
  g_InControlState.TravelLength.x = 30;//-20;
  g_InControlState.TravelLength.z = 0;
  g_InControlState.TravelLength.y = 0;
}
void GehenLinks()
{
  g_InControlState.TravelLength.x = -30;
  g_InControlState.TravelLength.z = 0;
  g_InControlState.TravelLength.y = 0;
}

// Lässt den Roboter stehen bleiben und alle Beine auf den Boden setzen
void Stop()
{
  g_InControlState.TravelLength.x = 0;
  g_InControlState.TravelLength.y = 0;
  g_InControlState.TravelLength.z = 0;
  
  //Noch ein paar mal aufrufen, das alle Beine am Boden sind
  for(int i = 0; i < 18; i++)
  {
    PhoenixLoop();
  }
}

// Lässt den Roboter zum Boden und wieder in die Höhe gehen
void Bounce()
{
  Stop();
  g_InControlState.BodyPos.y = 20;
  AdjustLegPositionsToBodyHeight();
  Wait(500);
  g_InControlState.BodyPos.y = 60;
  AdjustLegPositionsToBodyHeight();
  Wait(500); 
}

// Ändert die Art zu gehen
// param GaitNr: Wählt die Gangart aus. Gültige Werte: 0 - 5
void SetGait(int GaitNr)
{
  g_InControlState.GaitType = GaitNr;
  GaitSelect();
}

// Ändert die Höhe der Basis des Roboters
// param h: Höhe über dem Boden in mm
void SetHoehe(int h)      // 0 = Roboter liegt am Boden
{
  g_InControlState.BodyPos.y = h;
  AdjustLegPositionsToBodyHeight();
}

// Schickt ein Kommando zum einstellen der Position
// des Servos zum Servocontroller
// Das Kommando muss mit SetMovetime(int Zeit)
// abgeschlossen werden
// param ServoNr  : Servo der angesprochen werden soll
// param Pulsweite: Pulsweite die dem Servo gesendet
// werde soll in ms. 1500 entspricht der Mittelstellung
// Bereich 500-2500, mechanische Limits beachten!
void SetServo(int ServoNr, int Pulsweite)
{
  Serial.print('#');
  Serial.print(ServoNr);
  Serial.print('P');
  Serial.print(Pulsweite);
}

// Schließt ein Kommando zum Servocontroller mit 
// der Zeit die die Servo brauchen sollen ab.
// param Zeit: Zeit die die Bewegung dauern soll
void SetMovetime(int Zeit)
{
  Serial.print('T');
  Serial.print(Zeit);
  Serial.print('\r');
}

// Kombiniert die beiden obigen Funktionen um einen
// Servo zu bewegen.
// Parameter wie in den obigen Funktionen
void SetServo(int ServoNr, int Pulsweite, int Zeit)
{
  SetServo(ServoNr, Pulsweite);
  SetMovetime(Zeit);
}



// Ein Beispiel wie eigene Servopositionen implementiert werden können
void SpecialMove()    // "Verbeugung"
{
  // Servo: Mitte = 1500 Bereich(500-2500) mechanische Limits beachten!
  
  SetServo(5,1500);      // Coxa Servos einstellen
  SetServo(21,1500);
  SetServo(4,1500);      // Femur
  SetServo(20,1500);
  SetServo(8,1000);      // Tibia
  SetServo(24,2000);
  SetMovetime(2000);     // Zeit die die Bewegung dauern soll und Abschluss des Befehls           
}



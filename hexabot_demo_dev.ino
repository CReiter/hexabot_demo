// Hexabot Demo
// 
// Angepasst von Christoph Reiter
// basierend auf Arbeit von: 
//     Jeroen Janssen [aka Xan]
//     Kurt Eckhardt(KurtE) converted to C and Arduino
//     Kåre Halvorsen aka Zenta - Makes everything work correctly!

#include <TimerOne.h>
#include "ringpuffer.h"

bool toggle = false;
int state = 0;
int active = 0;

// 5 Zellen, NiMH Entladeschlussspannnung 0,8V
#define LOW_VOLTAGE 5*800  
#define VOLTAGEPIN A1
// Faktor um auf mV zu kommen
// ( 5V Referenzspannung, Spannungsteiler 1:1, 10Bit ADC)
#define VOLTAGEFACTOR  5000L*2/1023 
volatile uint16_t avgVoltage = 0;

// Bibliothek für die I2C Schnittstelle
#include <i2cmaster.h>  

// Phoenix includes
// Achtung: Reihenfolge nicht ändern
#include "hex_cfg.h"
#include <Phoenix.h>
#include <Phoenix_Input_Dummy.h>
#include <Phoenix_Driver_SSC32.h>
#include <Phoenix_Code.h>

// Puffer um die Werte zu glätten
#define TEMPERATUREBUFSIZE 3
#define VOLTAGEBUFSIZE 10

int TemperatureData[TEMPERATUREBUFSIZE];
int VoltageData[VOLTAGEBUFSIZE];
struct ringbuffer TemperatureBuffer, VoltageBuffer;
int filteredTemperature;


void setup()
{
  RingBufferInit(TEMPERATUREBUFSIZE, &TemperatureBuffer,
		 TemperatureData);
  RingBufferInit(VOLTAGEBUFSIZE, &VoltageBuffer,
		 VoltageData);
  
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  LedInit(); // Ausgänge für die Leds konfigurieren
  
  i2c_init(); //Initialise the i2c bus
  Timer1.initialize(100000); // 100ms Timer
  
  // Interruptfunktion bei Overflow ausführen
  Timer1.attachInterrupt(Interrupt);
  
  PhoenixSetup();
  g_InControlState.fHexOn = true;
  SetGait(1);
  //g_InControlState.LegLiftHeight = 80;
  SetHoehe(70);
}

void loop()
{
  DrehenRechts();
    //delay(2000);
    //GehenVorwaerts();
    //Wait(7000);
    //Bounce();
    //Bounce();
    //Bounce();
    //SpecialMove();
    //delay(5000);
    //Bounce();
    //Bounce();
    //GehenRechts();
    //Wait(6500);
    //GehenVorwaerts();
    Wait(5500);
    Stop();
    while(true)
    {
      //PhoenixLoop();
      Wait(100);
      DrehenRechts();
    }
}

// Hält den Programmablauf an, lässt den Roboter aber weitergehen.
// param ms: Millisekunden die gewartet werden soll
void Wait(int ms)
{
  long vergangen = millis();
  while((millis() - vergangen) < ms)
  {
    PhoenixLoop();  // Debug ausgaben
    Serial.print("[VOLTAGE] ");
    Serial.print(avgVoltage);
    Serial.println("mV");
    Serial.print("[TEMP] ");
    Serial.print(filteredTemperature / 10);
    Serial.print(",");
    Serial.print(filteredTemperature % 10);
    Serial.println("°C");
    delay(100);
  }
}

void Interrupt()  //Wird alle 100ms ausgeführt
{
  RingBufferAdd((int)getTemp(), &TemperatureBuffer);
  filteredTemperature = RingBufferGetAvg(&TemperatureBuffer);
  RingBufferAdd((analogRead(VOLTAGEPIN) * VOLTAGEFACTOR),
		&VoltageBuffer);
  avgVoltage = RingBufferGetAvg(&VoltageBuffer);
  if(avgVoltage > 4800)
  {
    LedNext(4);
  }
  else
  {
    LedNext(0);
  }
  CheckVoltage();
}




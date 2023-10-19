#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
unsigned int adata = 0;
unsigned int temp = 0;
int LED = 3;
void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    Mirf.cePin = 9;     
    Mirf.csnPin = 10;   
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();  
    Mirf.setRADDR((byte *)"Rec01");
    Mirf.payload = sizeof(unsigned int);
    Mirf.channel = 3;
    Mirf.config();
    Serial.println("I'm Receiver...");
}

void loop()
{
    byte data[Mirf.payload];
    if(Mirf.dataReady())    
    {
        Mirf.getData(data);   
        adata = (unsigned int)(data[0]);
            Serial.print(adata);
            Serial.print(",");
        temp = (unsigned int)(data[1]);
            Serial.println(temp);
    }
    else
    
     if(adata)
     {
         digitalWrite(LED, LOW);
         delay(500);
     }
     else
     {
      digitalWrite(LED, HIGH);
      delay(500);
      }
}

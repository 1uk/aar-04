/*
DATEI: ultraschall.ino
AUTOR: Lukas Kitsche & Henri Chilla
*/

int triggerPIN=11;
int echoPIN=12;
const int schallMPS=343;         //Schallgeschwindigkeit als Konstante definieren in Metern pro Sekunde

void setup(){
   Serial.begin(9600);           //Serielle Verbindung mit dem Roboter aufbauen
   
   pinMode(triggerPIN, OUTPUT);  //Trigger Pin als Ausgang definieren
   pinMode(echoPIN, INPUT);      //Echo Pin als Eingang definieren
}

long streckeBerechnen(int dauer){
  long distanz = dauer/2/2.92;
  return distanz;               //Meter pro sekunde * Mikrosekunde * 1000 = Millimeter
}

void loop(){
   digitalWrite(triggerPIN, HIGH);                        //Trigger Pin anmachen
   delayMicroseconds(1000);                               //Eine Millisekunde warten
   digitalWrite(triggerPIN, LOW);                         //Trigger Pin anmachen
   int dauer = pulseIn(echoPIN, HIGH);                    //Am Echo Pin auf ein "an" Signal warten und Zeit in durationYS speichern
   
   int strecke = streckeBerechnen(dauer);                 //Entfernung berechnen
   //Serial.println(dauer);
   if(strecke < 180000){                                //Wenn Objekt zu weit entfernt ist, wird Distanz nicht angezeigt
       Serial.print(strecke); Serial.println("mm");       //Strecke ausgeben 
   }
   else{
       Serial.println("Zu weit entfernt");
   }
   
   delay(250);                                            //Halbe Sekunde warten, damit nicht zu schnell
}

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
  long distanz = dauer/2/2.92;   //Distanz mithilfe der Dauer und der Schallgeschwinidkeit berechnen
  return distanz;
}

void loop(){
   digitalWrite(triggerPIN, HIGH);                        //Trigger Pin anmachen
   delayMicroseconds(1000);                               //Eine Millisekunde warten
   digitalWrite(triggerPIN, LOW);                         //Trigger Pin anmachen
   int dauer = pulseIn(echoPIN, HIGH);                    //Am Echo Pin auf ein "an" Signal warten und Zeit in durationYS speichern
   
   int strecke = streckeBerechnen(dauer);                 //Entfernung berechnen
   if(strecke < 1800 && strecke > 20){                    //Wenn Objekt zu weit entfernt bzw. zu nah ist, wird Distanz nicht angezeigt, weil fehlerhaft
       Serial.print(strecke); Serial.println("mm");       //Strecke ausgeben 
   }
   else{
       Serial.println("Zu weit entfernt");
   }
   
   delay(500);                                            //Halbe Sekunde warten für Ausgabe
}

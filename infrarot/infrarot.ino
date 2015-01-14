#include <libraries/Arduino-IRremote/IRremote.h>

#define VOR_R   9       //links vorwärts
#define VOR_L   5       //links zurück
#define ZUR_R   10      //rechts vorwärts
#define ZUR_L   6       //rechts zurück
#define BESCHL  100     // Beschleunigung

#define F_2     0xFF18E7
#define F_4     0xFF10EF
#define F_6     0xFF5AA5
#define F_8     0xFF4AB5
#define F_PWR   0xE318261B

IRrecv irrecv(4);  // pin
decode_results results;


int x, y; // vektor
void fahren(int p1, int p2);

void setup()
{
    x = y = 0;

    // infrarot
    Serial.begin(9600);
    irrecv.enableIRIn(); // empfänger starten
    Serial.println("ir initialized");
    Serial.println(F_2, HEX);

    // motor
    pinMode(VOR_L, OUTPUT);
    pinMode(ZUR_L, OUTPUT);
    pinMode(VOR_R, OUTPUT);
    pinMode(ZUR_R, OUTPUT);

    analogWrite(VOR_L, 0);
    analogWrite(ZUR_L, 0);
    analogWrite(VOR_R, 0);
    analogWrite(ZUR_R, 0);
}

void loop() {
    Serial.println("loop");
    if (irrecv.decode(&results)) {
        Serial.println("if");
        Serial.print("received: ");
        Serial.println(results.value, HEX);

        switch (results.value) {
            case F_2: y += BESCHL;
            break;
            case F_8: y -= BESCHL;
            break;
            case F_4: x -= BESCHL;
            break;
            case F_6: x += BESCHL;
            break;
            case F_PWR: y = x = 0;
            break;
        }
        fahren(x, y);

        Serial.print("x:");
        Serial.print(x);
        Serial.print(" y:");
        Serial.println(y);

        irrecv.resume(); // weiter empfangen
    }
}

void fahren(int x, int y) {
    // layer 2 (vektor)
    int r, l, vor_r, zur_r, vor_l, zur_l;
    l = y + x/2;
    r = y - x/2;

    // layer 1 (links rechts)
    if (l > 0) {
        vor_l = l;
        zur_l = LOW;
    }
    else {
        vor_l = LOW;
        zur_l = -l;
    }
    if (r > 0) {
        vor_r = l;
        zur_r = LOW;
    }
    else {
        vor_r = LOW;
        zur_r = -l;
    }

    // layer 0 (hardware)
    analogWrite(VOR_L, vor_l);
    analogWrite(ZUR_L, zur_l);
    analogWrite(VOR_R, vor_r);
    analogWrite(ZUR_R, zur_r);
}

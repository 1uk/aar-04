#include <libraries/Arduino-IRremote/IRremote.h>
IRrecv irrecv(2);  // pin
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
    Serial.println("initialized");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("received: ");
        Serial.println(results.value, HEX);
        irrecv.resume(); // Continue receiving
    }
}

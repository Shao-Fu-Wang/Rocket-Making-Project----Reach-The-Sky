#include "HX711.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);
int state = 0;
HX711 scale(3, 2);
float calibration_factor = -360; //calibration

void setup() {
	pinMode(12, INPUT);
	pinMode(11, OUTPUT);
	pinMode(13, OUTPUT);
	lcd.begin(16, 2);
	lcd.clear();
	Serial.begin(9600);
	Serial.println("Place igniter in.");
	Serial.println("Press it.");
	scale.set_scale();
	scale.tare(); 
	long zero_factor = scale.read_average(); 
	Serial.println(zero_factor);
	Serial.println(" ");
}
void loop() {
	scale.set_scale(calibration_factor);
	delay(500);
	state = digitalRead(12);
	if (state == HIGH) {
		Serial.println("Testing.");
		for (int i=0; i <= 50; i++){
			digitalWrite(13, HIGH);
			delay (100);
			digitalWrite (13, LOW);
			delay (100);
	}
	digitalWrite(11, HIGH);
	for (int i=0; i <= 1000; i++){ 
		scale.set_scale(calibration_factor); 
		Serial.print(scale.get_units(), 1);
		Serial.println();
	}
	digitalWrite (13,LOW);
	digitalWrite (11,LOW);
	Serial.println();
	}
}

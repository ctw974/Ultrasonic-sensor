#include <Arduino.h>

//Définition de la broche Echo.
const uint8_t ECHO_PIN = 7;

//Définition de la broche Trigger.
const uint8_t TRIG_PIN = 8;

// Definition des variables
const uint16_t MesureMaxi = 300;
const uint8_t MesureMini = 3;
uint32_t Duree;
uint32_t Distance;

void setup() {
  pinMode(TRIG_PIN,OUTPUT); // Broche Trigger en sortie
  pinMode(ECHO_PIN,INPUT); // Broche Echo en entree
  
  Serial.begin(9600);
  }
void loop() {

// Début de la mesure en envoyant un signal de 10us sur Trigger
digitalWrite(TRIG_PIN,LOW); //Mise à 0 de Trigger
_delay_us (2); // delay de 2us
digitalWrite(TRIG_PIN,HIGH); // Mise à 1 de Trigger
_delay_us (10); // delay de 10us
digitalWrite(TRIG_PIN,LOW); // Remise à 0 de Trigger

// Mesure de combien de temps le niveau logique haut est actif sur ECHO
Duree=pulseIn(ECHO_PIN,HIGH);
Duree=Duree-2; // correction

// Calcul de la distance
Distance=Duree*0.034/2;

// Verification si valeur mesuree est dans la plage d'utilisation
if(Distance>=MesureMaxi||Distance<=MesureMini) {
// Si la distance est hors plage, on affiche un message d'erreur
Serial.println("Distance de mesure en dehors de la plage (3 cm à 3m)");
}
else{
// Sinon affichage de la distance mesuree
Serial.print("Distance mesuree : ");
Serial.print(Distance);
Serial.println("cm");
}

//  Delay avant la prochaine mesure
delay(1000);

}
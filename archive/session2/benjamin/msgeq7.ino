int strobePin = 9;
int resetPin = 11;
int Frequencies[7];
int OutPin = A1;

const int laser = 2;

int Values[20];
int j = 0;
int Somme = 0;
double Moyenne = 0;

double calculMoyenne() {

  Somme += Frequencies[0];
  if (j < 20) {
    Values[j] = Frequencies[0];

  }
  else {
    Somme -= Values[0];
    for (int k = 0; k < 19; k++) {
      Values[k + 1] = Values[k];
    }
    Values[19] = Frequencies[0];
  }
  Moyenne = Somme / 20;
  j += 1;
  return Moyenne;
}

void setup() {
 
  Serial.begin(9600);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(OutPin, INPUT);

  digitalWrite(resetPin,  LOW);
  digitalWrite(strobePin, LOW);
  delay(1);

  digitalWrite(resetPin,  HIGH);
  delay(1);
  digitalWrite(resetPin,  LOW);
  digitalWrite(strobePin, HIGH);
  delay(1);

  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);

}

void loop() {
  // Lecture de la sortie du module pour chaque fréquence

  for (int i = 0; i < 7; i++) {
    digitalWrite(strobePin, LOW);
    delayMicroseconds(100);
    Frequencies[i] = analogRead(OutPin);
    digitalWrite(strobePin, HIGH);
    delayMicroseconds(1);
  }

  // Création d'un tableau de valeurs
  for (int i = 0; i < 7; i++) {
    Serial.print(Frequencies[i]);
    Serial.print("   ");
  }
  if (Frequencies[0] >= 100) {
    digitalWrite(laser, LOW);
  }
  else {
    digitalWrite(laser, HIGH);
  }

  Serial.println();



  //Calcul moyenne glissante :
  Serial.println(calculMoyenne());



}

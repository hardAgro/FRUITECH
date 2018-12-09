#define entradaDigital 8
#define entradaAnalogica 0

bool dSensor;
int aSensor;

void setup() {
  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
 }

void loop() {
    dSensor = digitalRead(entradaDigital);
    aSensor = analogRead(entradaAnalogica);
    Serial.print("Leitura entrada digital: ");
    Serial.println(dSensor);
    Serial.print("Leitura entrada analógica: ");
    Serial.println(aSensor);
    Serial.println();
    delay(1000);
}

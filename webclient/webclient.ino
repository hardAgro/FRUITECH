/* DHTServer - ESP8266 Webserver with a DHT sensor as an input
 
   Based on ESP8266Webserver, DHTexample, and BlinkWithoutDelay (thank you)
 
   Version 1.0  5/3/2014  Version 1.0   Mike Barela for Adafruit Industries
*/

#define pontencF1  D1
#define pontencF2  D2
#define buzzer D8

 

void setup(void)
{
  Serial.begin(9600);
  pinMode(pontencF1, INPUT);
  pinMode(pontencF2, INPUT);
  pinMode(buzzer, OUTPUT);

}

int inputF1pressao;
int inputF2pressao;

void loop(void)
{
  inputF1pressao = digitalRead(pontencF1);
  inputF2pressao = digitalRead(pontencF2);
  Serial.println("Pressao F1: ");
  Serial.println(inputF1pressao);
  delay(1000);
  Serial.println("Pressao F2: ");
  Serial.println(inputF2pressao);
  
  if(inputF1pressao==HIGH || inputF2pressao==HIGH){
    digitalWrite(buzzer,HIGH);
  }else{
    digitalWrite(buzzer,LOW);
  }
  
} 
 


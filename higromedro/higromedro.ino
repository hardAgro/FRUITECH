#define pinF1pressao 1
#define pinF1sensor 0
#define entradaF1DigitalSensor 8
#define pinF1verde 11
#define pinF1amarelo 12
#define pinF1vermelho 13
#define pinF1buzzer 7
#define pinF1rele 6

bool dSensor = 0;
int valF1sensor = 0;
int valF1pressao = 0;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);

  pinMode(pinF1buzzer,OUTPUT);
  pinMode(pinF1rele,OUTPUT);
   
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(pinF1rele, LOW);

  Serial.begin(9600);
}

void loop()
{
  dSensor = digitalRead(entradaF1DigitalSensor);
  valF1sensor = analogRead(pinF1sensor);    
  valF1pressao = analogRead(pinF1pressao);
  valF1pressao = map(valF1pressao,0,1023,0,9);
  Serial.print("Sensor - Leitura entrada digital F1: ");
  Serial.println(valF1sensor);
  Serial.print("Sensor - Leitura entrada analógica F1: ");
  Serial.println(valF1sensor);
  Serial.print("Pressao - Leitura entrada analógica F1: ");  
  Serial.println(valF1pressao);
  delay(1000);  
  
  if(900<=valF1sensor && valF1sensor<=1023){
    if(valF1pressao<4){
      digitalWrite(pinF1vermelho, HIGH);
      digitalWrite(pinF1verde, LOW);
      digitalWrite(pinF1amarelo, LOW);
      digitalWrite(pinF1buzzer, HIGH);
      digitalWrite(pinF1rele, LOW);
    }
    else{
      digitalWrite(pinF1verde, HIGH);
      digitalWrite(pinF1vermelho, LOW);
      digitalWrite(pinF1amarelo, LOW);
      digitalWrite(pinF1buzzer, LOW);
      digitalWrite(pinF1rele, HIGH);
    }  
  }
  
  if(400<=valF1sensor && valF1sensor<=899){
    if(valF1pressao<4){
      digitalWrite(pinF1vermelho, HIGH);
      digitalWrite(pinF1amarelo, LOW);
      digitalWrite(pinF1verde, LOW);
      digitalWrite(pinF1buzzer, HIGH);
      digitalWrite(pinF1rele, LOW);
      
    }
    else{
      digitalWrite(pinF1amarelo, HIGH);
      digitalWrite(pinF1vermelho, LOW);
      digitalWrite(pinF1verde, LOW);
      digitalWrite(pinF1buzzer, LOW);
      digitalWrite(pinF1rele, HIGH);
    }  
  }else{
    if(valF1sensor<399){
      digitalWrite(pinF1vermelho, HIGH);
      digitalWrite(pinF1verde, LOW);
      digitalWrite(pinF1amarelo, LOW);
      digitalWrite(pinF1buzzer, LOW);
      digitalWrite(pinF1rele, LOW);
    }  
 }
 
    
}


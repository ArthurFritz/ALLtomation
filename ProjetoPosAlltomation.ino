
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  Serial.print("server is at ");
}

void loop() {
  verificarUmidadeLigarMotors();
  delay(1000);
}

void verificarUmidadeLigarMotors(){
  for(int a=1; a<5; a++){
    if(humidadeTerreno(a)>500){
      acaoMotor(a,LOW);
    }else{
      acaoMotor(a,HIGH);
    }
  }
}

float humidadeTerreno(int ponto){
  float umid = 0;
  umid = analogRead(ponto);
  Serial.print("Humidade Ponto ");
  Serial.print(ponto);
  Serial.print(": ");
  Serial.print(umid);
  Serial.println();
  return umid;
}

void acaoMotor(int motor, int ligarDesligar){
  int pinoMotor = 0;
  int colunaLed = 0;
  int linhaLed = 0;
  switch (motor) {
    case 1:
      pinoMotor = 12;
      break;
    case 2:
      pinoMotor = 11;
      colunaLed=10;
      break;
    case 3:
      pinoMotor = 10;
      linhaLed = 1;
      break;
    case 4:
      pinoMotor = 9;
      linhaLed = 1;
      colunaLed=10;
      break;
  }
  if(pinoMotor>0)
    digitalWrite(pinoMotor, ligarDesligar);
}

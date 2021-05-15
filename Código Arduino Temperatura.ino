// C++ code
//
int tempBase = 0;
int celsius = 0;
int fahrenheit = 0;

void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  tempBase = 30;
  celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
  
  if(celsius < tempBase){
  	digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  if(celsius >= tempBase  && celsius < tempBase + 5 ){
     digitalWrite(7, LOW);
  	 digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
  }
  
  if(celsius >= tempBase + 5 && celsius < tempBase + 10){
  	  digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
  }
  if(celsius >= tempBase + 10){
  	  digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
  }
   delay(500); // Espere 1000 milisegundos
}
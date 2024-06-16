//    Codigo para subir o bajar la polea en caso de error
byte m1 = 3;
byte m2 = 11;

byte sensorI = 2;
byte sensorF = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorI, INPUT);
  pinMode(sensorF, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
}

void bajar()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
}
void subir()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
}
void detener()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}

void loop()
{
  int inicio = digitalRead(sensorI);
  int fin = digitalRead(sensorF);

  Serial.print("Inicio de carrera:  ");
  Serial.print(inicio);
  Serial.print("  ");
  Serial.print("Fin de carrera:  ");
  Serial.println(fin);   
  if (inicio == 0)
  {
    subir();
  }
  else if (fin == 0)
  {
    bajar();
  }
  
}

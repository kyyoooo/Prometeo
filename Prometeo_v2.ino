// Proyecto Prometeo version 2
#include <VirtualWire.h>

byte sensorI = 2;
byte sensorF = 13;

byte m1 = 3;
byte m2 = 11;

const int ledPin1  = 4;
const int ledPin2  = 5;
const int ledPin3  = 6;
const int ledPin4  = 8;
const int ledPin5 = 9;
const int ledPin6  = 10;

// Variables para controlar nuestros motores
int val;

int valor_recibido_RF; // Valor leido por el arduino
char recibido_RF_char[4]; //Guarda el valor
int comparador;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(sensorI, INPUT);
  pinMode(sensorF, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  vw_set_rx_pin(7);   
  vw_setup(1000); 
  vw_rx_start();
  Serial.println("Recepción del modulo RF - Aguardando...");
}

void loop()
{
  int presenciaI = digitalRead(sensorI);
  int presenciaF = digitalRead(sensorF);
  comparador = valor_recibido_RF;
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen))
  {
    int i;
    for (i = 0; i < buflen; i++)
    {
      //ordena los caracteres recibidos
      recibido_RF_char[i] = char(buf[i]);
    }
    recibido_RF_char[buflen] = '\0';

    //Convierte el valor recibido en integer
    valor_recibido_RF = atoi(recibido_RF_char);

    Serial.print("Recibido: ");
    Serial.print(valor_recibido_RF);
    Serial.print("  ");
    Serial.print("comparador: ");
    Serial.print(comparador);
    Serial.print("  ");
    Serial.print("Inicio: ");
    Serial.print(presenciaI);
    Serial.print("  ");
    Serial.print("Fin: ");
    Serial.println(presenciaF);

    // se mapea las señales y se convierte en salida al motor
    if (valor_recibido_RF >= 20)
    {
      val = map(valor_recibido_RF, 20, 100, 100, 255);
      
      if((presenciaI == 0)&&(presenciaF == 1))
      {
        subir();
        delay(100);
      }
      else if ((presenciaF == 0)&&(presenciaI == 1))
      {
        detener();
        delay(1000);
        bajar();
        delay(300);
      }
      else
      {
      
          if (valor_recibido_RF < 40) { 
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            digitalWrite(ledPin4, LOW);
            digitalWrite(ledPin5, LOW);
            digitalWrite(ledPin6, LOW);
            detener();
          }
          
          if (comparador < valor_recibido_RF )  // si el comparador es menor al ultimo valor, bajar
          {  
            if (valor_recibido_RF >= 45) {
              un_led();
              bajar();
            } 
            if (valor_recibido_RF >= 55) {
              dos_leds();
              bajar();
            }
            if (valor_recibido_RF >= 65) {
              tres_leds();
              bajar();
            }
            if (valor_recibido_RF >= 75) {
              cuatro_leds();
              bajar();
            }
            if (valor_recibido_RF >= 85) {
              cinco_leds();
              bajar();
            }
            if (valor_recibido_RF >= 95) {
              seis_leds();
              bajar();
            }
          }
          
           else if (comparador > valor_recibido_RF) 
           { 
            if (valor_recibido_RF <= 45) {
              un_led();
              subir();
            } 
            if (valor_recibido_RF <= 55) {
              dos_leds();
              subir();
            }
            if (valor_recibido_RF <= 65) {
              tres_leds();
              subir();
            }
            if (valor_recibido_RF <= 75) {
              cuatro_leds();
              subir();
            }
            if (valor_recibido_RF <= 85) {
              cinco_leds();
              subir();
            }
            if (valor_recibido_RF <= 95) {
              seis_leds();
              subir();
            }
        }
      }
    
  }
  delay(100);
  }
}

void apagar()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
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
void un_led()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
}
void dos_leds()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
}
void tres_leds()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
}
void cuatro_leds()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
}
void cinco_leds()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, LOW);
}
void seis_leds()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
}

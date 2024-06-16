// Proyecto Prometeo version 0.1 ( motor y leds en forma precisa)
#include <VirtualWire.h>

// Motor
byte m1 = 3;
byte m2 = 11;

// leds
const int ledPin1  = 4;
const int ledPin2  = 5;
const int ledPin3  = 6;
const int ledPin4  = 8;
const int ledPin5 = 9;
const int ledPin6  = 10;

// estas son variables para controlar nuestros motores
int val;


int valor_recibido_RF; // lee nuestro valor leido por el arduino
char recibido_RF_char[4]; //guarda el valor
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
  
  // pin del driver
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  
  //Pin ligado al pin DATA del receptor RF
  vw_set_rx_pin(7);
  
  //Velocidad de comunicación (bits por segundo)
  vw_setup(1000);
  
  //Inicia a recepción
  vw_rx_start();
  Serial.println("Recepción del modulo RF - Aguardando...");
}

void loop()
{
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

    //Muestra en monitor el valor recibido
    Serial.print("Recibido: ");
    Serial.println(valor_recibido_RF);
    Serial.print("comparador: ");
    Serial.println(comparador);



    // si el nivel de atencion es mayor o igual a 50 el carrito se movera
    // sino no, apaga motores
    if (valor_recibido_RF >= 20)
    {
      val = map(valor_recibido_RF, 20, 100, 100, 255);

      if (valor_recibido_RF < 20) {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, LOW);
      }
      if (comparador < valor_recibido_RF ) {
        
        if (valor_recibido_RF >= 25) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        } 
        if (valor_recibido_RF >= 35) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        }
        if (valor_recibido_RF >= 45) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        }
        if (valor_recibido_RF >= 55) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        }
        if (valor_recibido_RF >= 65) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        }
        if (valor_recibido_RF >= 75) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        digitalWrite(m1,  HIGH);
        digitalWrite(m2, LOW);
        }
      }
       else if (comparador > valor_recibido_RF) {
        
        if (valor_recibido_RF <= 25) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        } 
        if (valor_recibido_RF <= 35) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        }
        if (valor_recibido_RF <= 45) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        }
        if (valor_recibido_RF <= 55) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        }
        if (valor_recibido_RF <= 65) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, LOW);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        }
        if (valor_recibido_RF <= 75) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        digitalWrite(m1,  LOW);
        digitalWrite(m2, HIGH);
        }
    }
    
  }
  delay(100);
  }
}

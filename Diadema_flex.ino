#include <VirtualWire.h> // RF
#include <Brain.h>       // Mindflex
Brain brain(Serial);     

char Valor_CharMsg[10];  // guarda el valor que se enviara envio de señal 
int estado = 0;
int valor_bot;

void setup() 
{
  Serial.begin(9600);   
  vw_set_tx_pin(12); // Datos para el transmisor
  vw_setup(1000); // velocidad de transmision 
  Serial.println("Trasmision modulo RF - Acción o salir...");
}

void loop() 
{
  //leeremos el nivel de atencion con la funcion sig.
  valor_bot = brain.readAttention();
  if (brain.update()) // Señal
  {
    itoa(valor_bot,Valor_CharMsg,10);
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //envio de datos
    vw_wait_tx();

    //  valores enviados
    Serial.print("Valor enviado: ");
    Serial.println(brain.readCSV());
    Serial.println(Valor_CharMsg);
  } }

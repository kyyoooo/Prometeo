//  Diadema
// señal del datos del modulo transmisor de RF (emisor) en el pin 13

#include <VirtualWire.h> // libreria para RF
#include <Brain.h>       // libreria para Minflex
Brain brain(Serial);     // declaracion del monitor serie

char Valor_CharMsg[10];  // guarda el valor que se enviara envio de señal 
// estado led = ligar/desligar
int estado = 0;
int valor_bot;

void setup() 
{
  Serial.begin(9600);   
  
  //Pin ligado a pin DATA de transmisor RF
  vw_set_tx_pin(8);
  //Velocidad de comunicacacion (bits por segundo)
  vw_setup(1000);
  Serial.println("Trasmision modulo RF - Acción o salir...");
}

void loop() 
{
  //leeremos el nivel de atencion con la funcion sig.
  valor_bot = brain.readAttention();
  
  //preuntamos si esta enviando señal 
  if (brain.update())
  {
  
    //Convierte valor para envio
    itoa(valor_bot,Valor_CharMsg,10);
    //Envio de datos
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));
    //Aguarda envio de datos
    vw_wait_tx();
    
    //ESTA parte solo sera por si queremos ver las señales enviadas del minflex en monitor serie
    //Nota: tiene que estar conectado por cable 
    Serial.print("Valor enviado: ");
    Serial.println(brain.readCSV());
    Serial.println(Valor_CharMsg);
  } }

// MOTOR DERECHO
#define PWMD = 3; // Este pin es el que controlara la potencia que se usara en el motor derecho
#define IN4 = 2; // Teniendo en cuenta que 255 es el 100%
#define IN3 = 4;
// MOTOR IZQUIERDO
#define PWMI = 6; // Este pin es el que controlara la potencia que se usara en el motor izquierdo
#define IN2 = 5; // Teniendo en cuenta que 255 es el 100%
#define IN1 = 7;
#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
        // para comunicacion serie


// Estos pines son los que nos permitiran tener comunicacion con el modulo bluetooth.
SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX



void setup() {
  Serial.begin(9600);
  Serial.println("Listo");  // escribe Listo en el monitor
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  pinMode (IN4,OUTPUT);
  pinMode (IN3,OUTPUT);
  pinMode (IN2,OUTPUT);
  pinMode (IN1,OUTPUT);

}

void loop() {
MyControl(); // Funcion que creamos para poder enviar informacion via bluetooth.
Movimiento();// Funcion que creamos para saber que hacer con la informacion resivida.

}

void MyControl(){
  
  if (miBT.available())       // si hay informacion disponible desde modulo
   Serial.write(miBT.read());   // lee Bluetooth y envia a monitor serial de Arduino
 
 

if (Serial.available())     // si hay informacion disponible desde el monitor serial
  miBT.write(Serial.read());   // lee monitor serial y envia a Bluetooth
 
  }

 void Movimiento(){
  switch  (miBT.read()){ // Utilizamos un switch case para poder definir las acciones que
                        // se ejecutaran dependiendo la informacion resivida.
    
    case 'a':
    Serial.println("Izquierda");
    //Llanta derecha
     digitalWrite (IN4, HIGH);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,200);
    //Llanta izquierda
     digitalWrite (IN2, HIGH);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,50);

    break;    
        case 'b':
    Serial.println("Derecha");
     //Llanta derecha
     digitalWrite (IN4, HIGH);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,50);
    //Llanta izquierda
     digitalWrite (IN2, HIGH);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,200);
    break; 
        case 'h':
    Serial.println("Freno");
     //Llanta derecha
     digitalWrite (IN4, LOW);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,0);
    //Llanta izquierda
     digitalWrite (IN2, LOW);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,0);
     break;

        case 'q':
    Serial.println("Reversa");
    //Llanta derecha
     digitalWrite (IN4, LOW);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,0);
    //Llanta izquierda
     digitalWrite (IN2, LOW);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,0);
     delay(800);

     
    //Llanta derecha
     digitalWrite (IN4, LOW);
     digitalWrite (IN3, HIGH);
     analogWrite (PWMD,160);
    //Llanta izquierda
     digitalWrite (IN2, LOW);
     digitalWrite (IN1, HIGH);
     analogWrite (PWMI,160);

    break; 
        case 'e':
    Serial.println("Turbo");
     
    //Llanta derecha
     digitalWrite (IN4, HIGH);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,250);
    //Llanta izquierda
     digitalWrite (IN2, HIGH);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,250); 

    break; 
        case 'f':
    Serial.println("Acelerar");
  
    //Llanta derecha
     digitalWrite (IN4, HIGH);
     digitalWrite (IN3, LOW);
     analogWrite (PWMD,200);
    //Llanta izquierda
     digitalWrite (IN2, HIGH);
     digitalWrite (IN1, LOW);
     analogWrite (PWMI,200);
    break; 
    
    }
    
  
    

  }

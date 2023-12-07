#include <PID_v1.h>

// Pinos da planta
#define PIN_INPUT A1 // Acredito que o Pino A1 ligaremos nosso sensor de temperatura
#define PIN_SETPOINT A0 // Acredito que não teremos Pino para o setpoint, pois, nosso resistor será fixo e podemos startar o cooler em qualquer valor, que será ajustado
#define PIN_OUTPUT 3 // Onde será ligado nosso Cooler, iremos usar PWM, junto ao MOSFET para realizar o controle da velocidade do Cooler

unsigned long lastSend = 0;

// Define as Variáveis para conexão 
double Setpoint, Input, Output;

// PID
double Kp = 0.00434, Ki = 0.0869, Kd = 0.00005; 
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


void setup() {
  Serial.begin(9600);
  
  // Inicializando as variáveis
  Input = analogRead(PIN_INPUT);
  Setpoint = 100;  

  // Ligando o PID
  myPID.SetMode(AUTOMATIC);
}

void loop() {
    if (millis() - lastSend > 50) { ////Define o scan em 0.1 segundos
        lastSend = millis();
        Input = analogRead(PIN_INPUT);
        Setpoint = analogRead(PIN_SETPOINT);
        myPID.Compute();
        analogWrite(PIN_OUTPUT, Output);

        Serial.print(Setpoint);
        Serial.print(" ");
        Serial.print(Input);
        Serial.print(" ");
        Serial.print(Output);
        Serial.println(" ");
    }
}
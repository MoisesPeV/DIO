#include <IRremote.h>

// Definições de pinos
const int IR_PIN = 2; // Pino do receptor IR
const int LAMPADA1_PIN = 3; // Pino da lâmpada 1
const int LAMPADA2_PIN = 4; // Pino da lâmpada 2

// Códigos dos botões do controle remoto (substitua pelos códigos do seu controle)
const unsigned long BOTAO_LAMPADA1 = 0xFFA25D; // Código do botão para lâmpada 1
const unsigned long BOTAO_LAMPADA2 = 0xFF629D; // Código do botão para lâmpada 2

// Estados iniciais das lâmpadas
bool estadoLampada1 = false;
bool estadoLampada2 = false;

// Configuração do receptor IR
IRrecv irrecv(IR_PIN);
decode_results resultados;

void setup() {
  // Configura os pinos das lâmpadas como saída
  pinMode(LAMPADA1_PIN, OUTPUT);
  pinMode(LAMPADA2_PIN, OUTPUT);

  // Inicia o receptor IR
  irrecv.enableIRIn();

  // Inicia a comunicação serial (para depuração)
  Serial.begin(9600);
}

void loop() {
  // Verifica se um código IR foi recebido
  if (irrecv.decode(&resultados)) {
    unsigned long codigoRecebido = resultados.value;
    Serial.print("Código recebido: ");
    Serial.println(codigoRecebido, HEX);

    // Verifica o código e alterna o estado da lâmpada correspondente
    if (codigoRecebido == BOTAO_LAMPADA1) {
      estadoLampada1 = !estadoLampada1; // Inverte o estado da lâmpada 1
      digitalWrite(LAMPADA1_PIN, estadoLampada1 ? HIGH : LOW);
      Serial.println("Lâmpada 1 alterada.");
    } else if (codigoRecebido == BOTAO_LAMPADA2) {
      estadoLampada2 = !estadoLampada2; // Inverte o estado da lâmpada 2
      digitalWrite(LAMPADA2_PIN, estadoLampada2 ? HIGH : LOW);
      Serial.println("Lâmpada 2 alterada.");
    }

    // Libera o receptor IR para receber o próximo sinal
    irrecv.resume();
  }
}

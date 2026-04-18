// DEFINICIÓN DE PINES
const int PIN_ENTRADA = 2;  // Botón de activación

const int PIN_PULSOS_ASCENDENTE = 3;   // PULSOS CONTADOR ASCENDENTE
const int PIN_PULSOS_DESCENDENTE = 4;  // PULSOS CONTADOR DESCENDENTE

const int PIN_DIR_1 = 5;  // Dirección 1
const int PIN_DIR_2 = 6;  // Dirección 2

int estadoActual = LOW;
int estadoAnterior = LOW;

void setup() {

  pinMode(PIN_ENTRADA, INPUT);

  pinMode(PIN_PULSOS_ASCENDENTE, OUTPUT);
  pinMode(PIN_PULSOS_DESCENDENTE, OUTPUT);

  pinMode(PIN_DIR_1, OUTPUT);
  pinMode(PIN_DIR_2, OUTPUT);

  // Asegurar que todo comience apagado
  digitalWrite(PIN_PULSOS_ASCENDENTE, LOW);
  digitalWrite(PIN_PULSOS_DESCENDENTE, LOW);

  digitalWrite(PIN_DIR_1, LOW);
  digitalWrite(PIN_DIR_2, LOW);
}

void loop() {
  estadoActual = digitalRead(PIN_ENTRADA);

  // Detectar el botón pulsado
  if (estadoActual == HIGH) {

    girarCarusell(15, PIN_DIR_1, PIN_PULSOS_ASCENDENTE);

    delay(100);

    girarCarusell(10, PIN_DIR_2, PIN_PULSOS_DESCENDENTE);
  }

  delay(50);
}

void girarCarusell(int duracion, int pin_puente_h, int pin_contador) {
  digitalWrite(pin_puente_h, HIGH);

  //delay(1000);
  for (int i = 0; i < duracion; i++) {
    digitalWrite(pin_contador, LOW);
    delay(500);  // 100ms HIGH
    digitalWrite(pin_contador, HIGH);
    delay(500);  // 100ms LOW
  }

  digitalWrite(pin_contador, LOW);
  digitalWrite(pin_puente_h, LOW);

  delay(200);
}
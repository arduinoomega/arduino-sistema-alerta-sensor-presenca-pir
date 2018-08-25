#define PINOSENSOR 2 // Pino utilizado pelo sensor PIR
#define PINOLED 3 // Pino utilizado pelo led
 
int valorAnterior = 0; // Variável para armazenar o último esado do sensor de presença
void setup() {
Serial.begin(9600); // Inicialização da comunicação serial
pinMode(PINOSENSOR,INPUT); // Inicializando pino do sensor como entrada no Arduino
pinMode(PINOLED,OUTPUT); // Inicializando pino do led como saída no Arduino
// put your setup code here, to run once:
 
}
 
void loop() {
int valorAtual = digitalRead(PINOSENSOR); // Leitura do estado do sensor PIR: 1 - Presença detectada 0 - Presença não detectada
if (valorAnterior!=valorAtual){ // Verifica se o estado atual é diferente do estado anterior, para só assim tomar alguma decisão
if (valorAtual==HIGH){ // Se o sensor identificar uma presença
Serial.println("Presença Detectada"); // Mensagem é escrita na serial do Arduino
digitalWrite(PINOLED,HIGH); // Led será aceso
}
else{ // Caso uma presença não tenha sido detectada
digitalWrite(PINOLED,LOW); // Led será apagado
}
}
valorAnterior = valorAtual; // Copiamos o estado atual como estado anterior, para assim realizarmos a próxima leitura
 
}

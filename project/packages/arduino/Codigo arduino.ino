// atribui o número do pino
int right_pin = 6;
int left_pin = 7;
int forward_pin = 10;
int reverse_pin = 9;

// duração da saída
int time = 50;
// initial command
int command = 0;

//CONFIGURAÇAO INICIAL DOS PINOS
void setup()
{
  pinMode(right_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);
  pinMode(forward_pin, OUTPUT);
  pinMode(reverse_pin, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  //Recebe os comandos
  if (Serial.available() > 0)
  {
    command = Serial.read();
    send_command(command, time); // CHAMA FUNÇOES PARA EXECUTAR O COMANDO ENVIADO
  }
  else
  {
    reset();
  }
}

//Virar para a direita
void right(int time)
{
  digitalWrite(right_pin, LOW);
  delay(time);
}

//Virar para esquerda
void left(int time)
{
  digitalWrite(left_pin, LOW);
  delay(time);
}

//Seguir em frente
void forward(int time)
{
  digitalWrite(forward_pin, LOW);
  delay(time);
}

//RÉ
void reverse(int time)
{
  digitalWrite(reverse_pin, LOW);
  delay(time);
}
//Virar para a direita em Movimento (ANDANDO PARA FRENTE)
void forward_right(int time)
{
  digitalWrite(forward_pin, LOW);
  digitalWrite(right_pin, LOW);
  delay(time);
}
//Virar para a direita em movimento(RÉ)
void reverse_right(int time)
{
  digitalWrite(reverse_pin, LOW);
  digitalWrite(right_pin, LOW);
  delay(time);
}

//Virar para a ESQUERDA em Movimento (ANDANDO PARA FRENTE)
void forward_left(int time)
{
  digitalWrite(forward_pin, LOW);
  digitalWrite(left_pin, LOW);
  delay(time);
}
//Virar para a ESQUERDA em Movimento (RÉ)
void reverse_left(int time)
{
  digitalWrite(reverse_pin, LOW);
  digitalWrite(left_pin, LOW);
  delay(time);
}

//PARA O CARRO
void reset()
{
  digitalWrite(right_pin, HIGH);
  digitalWrite(left_pin, HIGH);
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, HIGH);
}

//COMANDOS
//1 == PARA O VEICULO
//2 == SEGUE EM FRENTE
//3 == RÉ
//4 == VIRA RODA PARA DIREITA
//5 == VIRA RODA PARA ESQUERDA
//6 == ACELERA E VIRA A RODA PARA A DIREITA
//7 == ACELERA E VIRA A RODA PARA ESQUERDA
//8 == DA RÉ E VIRA A RODA PARA DIREITA
//9 == DA RÉ E VIRA A RODA PARA ESQUERDA

//ENVIA COMANDOS PARA O VEICULO
void send_command(int command, int time)
{
  switch (command)
  {

    //reset command
    //PARA VEICULO
  case 1:
    reset();
    break;

  //COMANDOS COM UMA UNICA FUNÇAO
  case 2:
    forward(time);
    break; //SEGUIR EM FRENTE
  case 3:
    reverse(time);
    break; //RÉ
  case 4:
    right(time);
    break; // VIRAR A RODA PRA DIREITA
  case 5:
    left(time);
    break; //VIRAR A RODA PARA A ESQUERDA

  //COMANDOS COMBINADOS
  case 6:
    forward_right(time);
    break; // ACELERA E VIRA A RODA PARA A DIREITA
  case 7:
    forward_left(time);
    break; // ACELERA E VIRA A RODA PARA ESQUERDA
  case 8:
    reverse_right(time);
    break; // DA RÉ E VIRA A RODA PARA DIREITA
  case 9:
    reverse_left(time);
    break; // DA RÉ E VIRA A RODA PARA ESQUERDA

  default:
    reset(); // PARA O VEICULO CASO NAO IDENTIFIQUE O COMANDO
  }
}

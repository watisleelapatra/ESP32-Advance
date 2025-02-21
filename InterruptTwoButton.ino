#define Up 17   //Increase value
#define Down 16 //Decrease value
int Counter = 0;

void IRAM_ATTR Up_isr()
{
  Counter++;
}
void IRAM_ATTR Down_isr() 
{
  Counter--;
}
void setup() {
  Serial.begin(9600);
  pinMode(Up, OUTPUT);
  pinMode(Down, OUTPUT);
  attachInterrupt(Up, Up_isr, RISING);
  attachInterrupt(Down, Down_isr, RISING);
}

void loop() {
  
  Serial.println(Counter);
  delay(100);
}

#define Up 17   //Increase value
#define Down 16 //Decrease value
int Counter = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Up, OUTPUT);
  pinMode(Down, OUTPUT);
}

void loop() {
  
  Serial.println(Counter);
  if(digitalRead(Up) == 1)    
    Counter++;
  if(digitalRead(Down) == 1)
    Counter--;
  delay(100);
}

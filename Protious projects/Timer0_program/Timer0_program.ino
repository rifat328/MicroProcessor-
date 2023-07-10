// C++ code
//
#define PIN_USED 8
int milisec=2;
int prescalar=1024;
int clk_freq=16000000/prescalar;
float clk_period= 1/(float)clk_freq;
float count=((milisec*.001/clk_period)-1);
//float count = (milisec * clk_freq) / 1000.0 - 1;

void setup()
{
  pinMode(PIN_USED, OUTPUT);
  //set up timar
  TCCR0A=0b00000000;
  TCCR0B=0b00000101;
  TCNT0=0; //initial 0;
 // pinMode(PIN_USED, OUTPUT);
  // Set up Timer0 with prescaler of 1024
  //TCCR0A = 0;  // Set Timer0 to Normal mode
  //TCCR0B = (1 << CS02) | (1 << CS00);  // Set prescaler to 1024
  //TCNT0 = 0;  // Initialize the timer count
  
}

void loop()
{
  if(TCNT0 >= count){// chacking if delay time has passed
  	TCNT0=0;
    digitalWrite(PIN_USED,! digitalRead(PIN_USED));
  }
  
}

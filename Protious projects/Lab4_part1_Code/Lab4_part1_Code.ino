// part 1

#define GREEN1 8 //define name of pins used 
#define GREEN2 10 
#define GREEN3 12
#define RED1 9
#define RED2 11
#define RED3 13

//define the delays for each LED
int LED_blink = 700; 
//define variable for switch press
int switch_read; //defining a variable which will read the state of the switch
int LED_sequence=1; //defining which way the LEDs will light up (left to right or right to lrft
int delay_timer (int miliseconds)
{
 int count = 0;
 while(1)
 {
 if(TCNT0 >= 15) // Checking if 1 milisecond has passed
 {
 TCNT0=0;
 count++; 
 if (count == miliseconds) //checking if required miliseconds delay has passed
 {
 count=0;
 break; // exits the loop
 }
 }
 }
 return 0;
}



void setup() {
  // put your setup code here, to run once:
  //define pins connected to LEDs as outputs
 pinMode(GREEN1, OUTPUT); 
 pinMode(GREEN1, OUTPUT);
 pinMode(GREEN3, OUTPUT);
  pinMode(RED1, OUTPUT);
 pinMode(RED2, OUTPUT);
 pinMode(RED3, OUTPUT);
 pinMode(2, INPUT);
 
 //set up timer
 TCCR0A = 0b00000000;
 TCCR0B = 0b00000101; //setting highest prescaler for timer clock
 TCNT0=0;

}

void loop() {
  // put your main code here, to run repeatedly:
switch_read=digitalRead(2);
 if (switch_read==LOW){
 LED_sequence=!LED_sequence;
 }

 if (LED_sequence==1){
 //to make green1 LED blink
 digitalWrite(GREEN1, HIGH); 
 delay_timer(LED_blink);
 digitalWrite(GREEN1, LOW);
 
 //to turn red1 LED blink
 digitalWrite(RED1, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED1, LOW);
 
 //green2 blink and so on
 digitalWrite(GREEN2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(GREEN2, LOW);
 digitalWrite(RED2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED2, LOW);
 
 digitalWrite(GREEN3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(GREEN3, LOW);
 //green2 blink and so on
 digitalWrite(RED3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED3, LOW);
 }
 else {
 
 digitalWrite(RED3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED3, LOW);
 digitalWrite(GREEN3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(GREEN3, LOW);
 digitalWrite(RED2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED2, LOW);
 digitalWrite(GREEN2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(GREEN2, LOW);
 digitalWrite(RED1, HIGH);
 delay_timer(LED_blink);
 digitalWrite(RED1, LOW);
 digitalWrite(GREEN1, HIGH); 
 delay_timer(LED_blink);
 digitalWrite(GREEN1, LOW);
 delay_timer(LED_blink);
 }

}

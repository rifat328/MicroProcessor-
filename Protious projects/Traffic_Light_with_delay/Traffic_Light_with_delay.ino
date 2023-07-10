// C++ code
//
const int RedPin=13;
const int GreenPin=12;
const int YelloPin=11;
void setup()
{
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(YelloPin, OUTPUT);
}

void loop()
{
  // Red pin high for 30 sec
  digitalWrite(RedPin, HIGH);
  digitalWrite(GreenPin, LOW);
  digitalWrite(YelloPin, LOW);
  delay(30000); 
  
//Red will go off and Green will light up for 55sec.
  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, HIGH);
  digitalWrite(YelloPin, LOW);
  delay(50000);
  //50s after green lights up, Yellow will start to blink for 5s at a total 1s interval .
//[Consider blink to be a light lighting up for 500ms and staying off for
//500ms and the sequence is repeated.]
  for(int i=0;i<5;i++){
  	  digitalWrite(YelloPin, HIGH);
  	  delay(500);
      digitalWrite(YelloPin, LOW);
	  delay(500);
  }
//Then green and yellow will turn off.
    digitalWrite(GreenPin, LOW);
    digitalWrite(YelloPin, LOW);

}

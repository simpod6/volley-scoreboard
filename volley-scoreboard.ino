
#include <TM1638.h>

#define NORMAL_SET_POINTS 25
#define TIE_BREAK_SET_POINTS 15


//define a regular module 
TM1638 module(8, 9, 7);

byte points[2];
byte sets[2];
byte setEnd;  //points to win the set

void setup() {

  resetGame();  
  module.setupDisplay(true, 7);
  
}


void resetSet() {
  points[0] = 0;
  points[1] = 0;
}

void resetGame() {
  resetSet();

  sets[0] = 0;
  sets[1] = 0;
}

void displayStatus() {
  //show current points
  char s[9];
  sprintf(s, "%2d    %2d", points[0], points[1]);
  module.setDisplayToString(s);

  //show current sets  
  for (int i=0; i<sets[0]; i++) {
    module.setLED(1, i);
  }
  for (int i=sets[0]; i<4; i++) {
    module.setLED(0, i);
  }
  for (int i=0; i<sets[1]; i++) {
    module.setLED(1, 8-1-i);
  }
  for (int i=sets[1]; i<4; i++) {
    module.setLED(0, 8-1-i);
  }
    
}

void loop() {

  //read buttons
  byte buttons = module.getButtons();
  if (buttons != 0)
  {
    byte b;
    while ((b = module.getButtons()) != 0)
    {
      if (b == 131)  //reset the game
      {
        resetGame();
        buttons = 0;
      }
      if (b == 24)  //reset the current set
      {
        resetSet();
        buttons = 0;
      }
    }    
  } 

  switch (buttons) {
    case 1: //home team scores
      points[0]++;
      break;
    case 128: //guest team scores
      points[1]++;
      break;
    case 8: //home team increment set
      sets[0]++;      
      break;
    case 16: //guest team increment set
      sets[1]++;
      break;
  }

  //define points to win the set
  if (sets[0] + sets[1] == 4)
    setEnd = TIE_BREAK_SET_POINTS;
  else
    setEnd = NORMAL_SET_POINTS;

  //check if home team won the set
  if ( (points[0] >= setEnd) && (points[0] > (points[1]+1)) ) {
    sets[0]++;
    resetSet();
  }
  //check if guest team won the set
  if ( (points[1] >= setEnd) && (points[1] > (points[0]+1)) ) {
    sets[1]++;
    resetSet();
  }

  //reset the sets if overflow
  if (sets[0] > 4)
    sets[0] = 0;
  if (sets[1] > 4)
    sets[1] = 0;
     
  //show the status
  displayStatus();

  //blink if setpoint
  if ( (points[0] >= (setEnd-1)) && (points[0] > points[1]) ) {
    char s[9];
    sprintf(s, "      %2d", points[1]);
    module.setDisplayToString(s);
    delay(50);
  }
  if ( (points[1] >= setEnd-1) && (points[1] > points[0]) ) {
    char s[9];
    sprintf(s, "%2d      ", points[0]);
    module.setDisplayToString(s);
    delay(50);
  }
  
}

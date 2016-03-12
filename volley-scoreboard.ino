
#include <TM1638.h>

//define a regular module 
TM1638 module(8, 9, 7);

//team points
byte points[2];

void setup() {

  resetGame();
  
  module.setupDisplay(true, 7);
}

void resetGame() {
  points[0] = 0;
  points[1] = 0; 

}

void loop() {
  // put your main code here, to run repeatedly:

  byte buttons = module.getButtons();
  if (buttons != 0)
  {
    while (module.getButtons() != 0)
      ;
    
  }
 
 
  if (buttons == 1)
    points[0]++;
  if (buttons == 128)
    points[1]++;

  

  

  char s[8];
  sprintf(s, "%2d    %2d", points[0], points[1]);
  module.setDisplayToString(s);


}

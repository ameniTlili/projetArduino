

#include <TFT.h> 
#include <SPI.h>


#define cs   10
#define dc   9
#define rst  8  

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);


void setup() {
  
  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  
  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255,255,255);
  // set the font size
  TFTscreen.setTextSize(5);
  // write the text to the top left corner of the screen
  TFTscreen.text("hello ",0,0);

}

void loop() {

  
}


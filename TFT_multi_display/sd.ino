// #ifdef SD_TEXT
#include <SPI.h>
#include <SD.h>
#define SD_CS_PIN 4
File myFile;
bool setupSD() {
  if (!SD.begin(SD_CS_PIN)) {
    return false;
  }
  return true;
}
bool writeSD(String row ) {
  myFile = SD.open("test.txt",FILE_WRITE );

  // if the file opened okay, write to it:
  if (myFile) {
     
    myFile.println(row);
    // close the file:
    myFile.close();
  // if the file opened okay, write to it:
 
  }
}
// #endif
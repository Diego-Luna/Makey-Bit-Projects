// Adafruit IO Publish Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// this int will hold the current count for our sketch
String dataSend;
unsigned long number = 0;

// set up the 'counter' feed
AdafruitIO_Feed *S_next = io.feed("spotify-next");
AdafruitIO_Feed *S_pause = io.feed("spotify-pause");
AdafruitIO_Feed *S_play = io.feed("spotify-play");

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  // start the serial connection
  Serial.begin(9600);

  // wait for serial monitor to open
  while (! Serial);

  //  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    delay(500);
  }

  // we are connected
  //  Serial.println();
  //  Serial.println(io.statusText());
  Serial.println("on");

}

void loop() {

  if (Serial.available() > 0 ) {
    digitalWrite(LED_BUILTIN, LOW);
    dataSend = Serial.read();
    if (dataSend) {
      io.run();
      //      number++;
      number = random(1, 100);
      if (dataSend == "e") {
        S_pause->save(number);
      }
      if (dataSend == "p") {
        S_play->save(number);
      }
      if (dataSend == "r") {
        S_next->save(number);
      }
    }
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }

}

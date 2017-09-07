/*
This is an example of the "Analog" class of the MIDI_controller library.
Connect a potentiometer to analog pin A0. This will be the MIDI channel volume of channel 1.
Map it in your DAW or DJ software.

Written by Pieter P, 22-08-2017
https://github.com/tttapa/MIDI_controller
*/

#include <MIDI_controller.h> // Include the library

const uint8_t Channel_Volume = 0x7; // Controller number 7 is defined as Channel Volume in the MIDI specification
const uint8_t MIDI_Channel = 1;     // Send Control Change messages on MIDI channel 1

const size_t analogAverage = 8; // Use the average of 8 analog samples to get smooth transitions and prevent noise

// Create a new instance of the class 'Analog, called 'potentiometer', on pin A0, 
// that sends MIDI messages with controller 7 (channel volume) on channel 1
Analog potentiometer(A0, Channel_Volume, 1);

//________________________________________________________________________________________________________________________________

void setup() {
  potentiometer.average(analogAverage); // Use the average of 8 analog samples to get smooth transitions and prevent noise
}

//________________________________________________________________________________________________________________________________

void loop() {
  // Refresh the MIDI controller (check whether the potentiometer's input has changed since last time, if so, send the new value over MIDI)
  MIDI_Controller.refresh();
}
#include <Arduino.h>
#include <IRremote.hpp>


/*
    d19 --> receving from button 1 (to start listening (via hold))
    d18 --> receving from diod

    d21 --> receving from button 2 (to trigger IR blast)
    d26 --> outputting to IR LED (triggering IR blast)
*/


const int RECV_PIN = 18;
const int RECV_BUTTON = 19;

const int IR_SEND_PIN = 26;
const int SEND_BUTTON = 21;


// variables to do with getting and sending ir codes
int sAddress;
const int sRepeats = 0;
int sCommand;



// variables to do with the buttons
int RecButtonState;
int LastRecButtonState;

int TransButtonState;
int LastTransButtonState;



void setup()
{
    Serial.begin(115200);


    // starting to listen to diod
    IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);


    // starting to listening to button
    RecButtonState = digitalRead(RECV_BUTTON);
    TransButtonState = digitalRead(SEND_BUTTON);

  
    // starting to send func
    pinMode(IR_SEND_PIN, OUTPUT);
    IrSender.begin(IR_SEND_PIN);
    
    Serial.println("start up completed");
}



void loop()
{

    //fetching button state in loop
    RecButtonState = digitalRead(RECV_BUTTON);
    LastRecButtonState = RecButtonState;
    RecButtonState = digitalRead(RECV_BUTTON);

    TransButtonState = digitalRead(SEND_BUTTON);
    LastTransButtonState = TransButtonState;
    TransButtonState = digitalRead(SEND_BUTTON);


    
    // getting IR signal

    if (RecButtonState == LOW) {

        // Serial.println("listening for ir code");
        
        LastRecButtonState = RecButtonState;
        
        // if signal is decoded the writting data to variables 

        if (IrReceiver.decode()) {

            sAddress = IrReceiver.decodedIRData.address;
            sCommand = IrReceiver.decodedIRData.command;
            
            Serial.print("address --> ");
            Serial.println(sAddress);
            
            Serial.print("command --> ");
            Serial.println(sCommand);


            IrReceiver.resume();

        }
    }
    


    // sending IR signal

    if (TransButtonState == LOW) {

        // Serial.println("sending ir codes");

        LastTransButtonState = TransButtonState;


        Serial.println("Button pressed, sending codes");
        IrSender.sendNEC(sAddress, sCommand, sRepeats);
        delay(1000); 

    }
}


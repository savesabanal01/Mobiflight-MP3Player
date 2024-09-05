#include "MF_MP3Player.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include "mp3tf16p.h"
/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */
MP3Player mp3(10, 11);

MF_MP3Player::MF_MP3Player(uint8_t Pin1, uint8_t Pin2)
{
    _pin1 = Pin1;
    _pin2 = Pin2;
}

void MF_MP3Player::begin()
{
    Serial.begin(9600);
    mp3.initialize();
}

void MF_MP3Player::attach(uint16_t Pin3, char *init)
{
    _pin3 = Pin3;
}

void MF_MP3Player::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void MF_MP3Player::set(int16_t messageID, char *setPoint)
{
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    // int32_t  data = atoi(setPoint);
    // uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
        break;
    case -2:
        // tbd., get's called when PowerSavingMode is entered
        break;
    case 0:
        playGPWS(atoi(setPoint));
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void MF_MP3Player::update()
{
    // Do something which is required regulary
}

void MF_MP3Player::playGPWS(int playFlag)
{
    if(playFlag == 1)
        mp3.playTrackNumber(1, 25,false);
}


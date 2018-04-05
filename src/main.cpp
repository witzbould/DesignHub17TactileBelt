#include "stdafx.h"
#include "Config.h"
#include "TactileBelt.h"
#include "TactileSettings.h"

using namespace DesignHub;

TactileBelt *Belt;
unsigned long nextTick;
int skippedFrames;

// String forceCharBuffer = "";
// std::list<int> motorForces;
// int motorId = 0;
// TactileSettings *settings = nullptr;
// bool isSettingsReady = false;

/**
 * Setup
 */
void setup()
{
  Belt = new TactileBelt();
  Belt->addMotor(0, 12);
  Belt->setMotorForce(0, 100);
  // Belt->addMotor(1, 11);
  // Belt->addMotor(2, 10);

  // forceCharBuffer.reserve(FORCE_CHAR_BUFFER_SIZE);

  Serial.begin(57600);

  while (!Serial)
    ;

  Serial.println("You're connected.");

  // settings = new TactileSettings();
  // settings->appendForce(0, 255);
  // isSettingsReady = false;
  nextTick = millis();
}

/**
 * Loop
 */
void loop()
{
  skippedFrames = 0;
  while (millis() > nextTick && skippedFrames < MAX_SKIPPEDFRAMES)
  {
  //   // new TactileSettings()
  //   if (isSettingsReady)
  //   {
  //     Belt->update(settings);

  //     settings = nullptr;
  //     isSettingsReady = false;
  //   }
  //   else
  //   {
  //     Belt->update(nullptr);
  //   }

  Serial.println("Tick");

  nextTick += DEBOUNCEDELAY;
  skippedFrames++;
  }

  Belt->render();
}

/**
 * SerialEvent
 *
 * read Serial
 * 0=20,0,100&1=0,0,30&7=200,0,255\r\n
 */
// void serialEvent()
// {
//   if (settings == nullptr)
//   {
//     settings = new TactileSettings();
//   }

//   while (Serial.available())
//   {
//     char inChar = (char)Serial.read();

//     switch (inChar)
//     {
//     case ',': // push_back()
//     case '&':
//       settings->appendForce(motorId, forceCharBuffer.toInt());
//       forceCharBuffer = "";
//       break;
//     case '=': // buffer has motorId -> set _motorId
//       motorId = forceCharBuffer.toInt();
//       forceCharBuffer = "";
//       break;
//     case '\r':
//     case '\n':
//       // send TactileSettings
//       isSettingsReady = true;

//       // clear rest buffer
//       if (Serial.peek() == '\n')
//       {
//         Serial.read();
//       }
//       forceCharBuffer = "";
//       break;
//     default:
//       forceCharBuffer += inChar;
//     }
//   }
// }

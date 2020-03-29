/*=============================================================================
 * @file respi-prod.cpp
 *
 * COVID Respirator
 *
 * @section copyright Copyright
 *
 * Makers For Life
 *
 * @section descr File description
 *
 * This file execute the MakAir program
 */

// INCLUDES ==================================================================

// External
#include <AnalogButtons.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Internal
#include "common.h"
#include "config.h"
#include "debug.h"
#include "display.h"
#include "keyboard.h"
#include "parameters.h"
#include "pressure_controller.h"
#include "pressure_sensor.h"

// PROGRAM =====================================================================

void setup()
{
    pinMode(PIN_CAPTEUR_PRESSION, INPUT);

    DBG_DO(Serial.begin(9600);)
    DBG_DO(Serial.println("Start");)

    pController.setup();
    startScreen();
    initKeyboard();
}

void loop()
{
    /********************************************/
    // INITIALIZE THE RESPIRATORY CYCLE
    /********************************************/

    displayEveryRespiratoryCycle(pController.peakPressure(), pController.plateauPressure(),
                                 pController.peep());

    pController.initRespiratoryCycle();

    /********************************************/
    // START THE RESPIRATORY CYCLE
    /********************************************/
    uint16_t centiSec = 0;

    while (centiSec < pController.centiSecPerCycle())
    {
        static uint32_t lastpControllerComputeDate = 0uL;
        uint32_t currentDate = millis();
        if ((currentDate - lastpControllerComputeDate) >= PCONTROLLER_COMPUTE_PERIOD)
        {
            lastpControllerComputeDate = currentDate;

// Get the measured pressure for the feedback control
#ifdef SIMULATION
            if (centiSec < uint16_t(50))
            {
                pController.updatePressure(60);
            }
            else
            {
                pController.updatePressure(30);
            }
            if (centiSec > pController.centiSecPerInhalation())
            {
                pController.updatePressure(5);
            }
#else
            pController.updatePressure(pSensor.read());
#endif

            // Perform the pressure control
            pController.compute(centiSec);

            // Check if some buttons have been pushed
            keyboardLoop();

            // Display relevant information during the cycle
            if ((centiSec % LCD_UPDATE_PERIOD) == 0u)
            {
                displayDuringCycle(pController.cyclesPerMinuteCommand(),
                                   pController.maxPlateauPressureCommand(),
                                   pController.minPeepCommand(), pController.pressure());
            }

            // next tick
            centiSec++;
        }
    }
    /********************************************/
    // END OF THE RESPIRATORY CYCLE
    /********************************************/
}

/*=============================================================================
 * @file affichage.h
 *
 * COVID Respirator
 *
 * @section copyright Copyright
 *
 * Makers For Life
 *
 * @section descr File description
 *
 * Fichier définissant les fonctionnalitées liés à l'affichage
 */

#pragma once

#include "common.h"

// FORWARD DECLARATIONS =======================================================
class LiquidCrystal;

// STRUCTURES =================================================================

/*! This enum lists the different screen sizes
 *  2 LCD versions are supported:
 *  -   LCD with 16 columns and 2 rows (16x2)
 *  -   LCD with 20 columns and 4 rows (20x4)
 */
enum ScreenSize
{
    CHARS_16,
    CHARS_20
};

// FUNCTIONS ==================================================================

//! This function starts the screen
void startScreen();

//! This function resets the screen
void resetScreen();

//! This function displays test characters on the screen
void displayTestPattern();

//! This function displays 2 lines of 16 characters (or less)
void display(char line1[], char line2[]);

//! This function displays only adds a status message in the 4th line
void displayStatus(char msg[]);

void displaySubPhase(CycleSubPhases phase);

/*! This function displays the relevant pressures on the HMI screen once every
 *  cycle
 *  N.B.: by default, the screen size is 16 chars
 *
 *  \param peakPressure     The peak pressure [mmH2O]
 *  \param plateauPressure  The plateau pressure [mmH2O]
 *  \param peep             The Positive End Expiratory Pressure (PEEP) [mmH2O]
 *  \param pressure         Current pressure [mmH2O]
 */
void displayEveryRespiratoryCycle(int peakPressure, int plateauPressure, int peep, int pressure);

/*! This function displays the relevant pressures on the HMI screen during the
 *  cycle.
 *  N.B.: by default, the screen size is 16 chars
 *
 *  \param peakPressureMax      PeakPressureMax [mmH2O]
 *  \param maxPlateauPressure   Next maximal plateau pressure [mmH2O]
 *  \param peep                 Next desired Positive End Expiratory Pressure (PEEP) [mmH2O]
 *  \param cyclesPerMinute      Next desired number of cycles per minute
 */
void displayDuringCycle(int peakPressureMax, int plateauPressureMax, int peepMin, int cyclesPerMinute);

/* 
 * File:   canfd.h
 * Author: seb
 *
 * Created on July 6, 2020, 10:55 PM
 */

#ifndef CANFD_H
#define	CANFD_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "buttons.h"
#include "EVE_target.h"

xTaskHandle canfdHandle;
BUTTONS_DATA buttonStates;


    volatile uint32_t messageID;
    uint8_t message;
    uint8_t message2;
    uint8_t messageLength;
    int buttonFlag;
    
    

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

void canfd();

void canfd_init();

void print_menu(void);








#endif	/* CANFD_H */


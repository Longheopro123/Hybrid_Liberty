/*
 * zero_crossing_types.h
 *
 * Code generation for model "HEV_mode".
 *
 * Model version              : 1.92
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Jun 16 12:10:27 2023
 *
 * Target selection: avl_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ZERO_CROSSING_TYPES_H
#define ZERO_CROSSING_TYPES_H
#include "rtwtypes.h"

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum { FALLING_ZCEVENT = -1, NO_ZCEVENT = 0, RISING_ZCEVENT = 1 }
  ZCEventType;

#endif                                 /* ZERO_CROSSING_TYPES_H */

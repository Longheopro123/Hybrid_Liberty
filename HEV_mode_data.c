/*
 * HEV_mode_data.c
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

#include "HEV_mode.h"

/* Block parameters (default storage) */
P_HEV_mode_T HEV_mode_P = {
  /* Variable: SOCCrit
   * Referenced by:
   *   '<Root>/Switch1'
   *   '<S1>/Switch'
   *   '<S2>/Switch1'
   *   '<S9>/Switch3'
   */
  90.0,

  /* Variable: f_mtr_w_bpt
   * Referenced by:
   *   '<S1>/1-D Lookup Table'
   *   '<S4>/1-D Lookup Table2'
   *   '<S9>/1-D Lookup Table'
   */
  { 0.0, 174.5329252, 349.0658504, 500.0, 1570.796327, 2094.395102, 2617.993878,
    3141.592654, 3665.191429, 4188.790205, 4712.38898, 5235.987756, 5759.586532,
    6283.185307 },

  /* Variable: f_tbrake_n_bpt
   * Referenced by: '<S7>/1-D Lookup Table1'
   */
  { 0.0, 1000.0, 1200.0, 2000.0, 3000.0, 4000.0, 5000.0, 5250.0, 6000.0, 7000.0,
    7750.0 },

  /* Variable: f_tbrake_t_max_bpt
   * Referenced by: '<S7>/1-D Lookup Table1'
   */
  { 0.721140563, 8.958917794, 9.310751301, 10.55825182, 11.75800208, 12.55816857,
    12.9587513, 12.99646202, 12.95975026, 12.56116545, 12.0 },

  /* Variable: f_tmtr_max
   * Referenced by:
   *   '<S1>/1-D Lookup Table'
   *   '<S4>/1-D Lookup Table2'
   *   '<S9>/1-D Lookup Table'
   */
  { 30.5, 30.5, 30.5, 30.5, 9.708451529, 7.281338646, 5.825070917, 4.854225764,
    4.160764941, 3.640669323, 3.23615051, 2.912535459, 2.647759508, 2.427112882
  },

  /* Mask Parameter: CheckStaticRange_max
   * Referenced by: '<S8>/max_val'
   */
  6000.0,

  /* Mask Parameter: CheckStaticRange_min
   * Referenced by: '<S8>/min_val'
   */
  4000.0,

  /* Expression: 0.3
   * Referenced by: '<S1>/Gain'
   */
  0.3,

  /* Expression: -1
   * Referenced by: '<S1>/Gain3'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: -31
   * Referenced by: '<Root>/Constant5'
   */
  -31.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant9'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Switch1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain2'
   */
  -1.0
};

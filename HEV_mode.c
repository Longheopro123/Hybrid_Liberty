/*
 * HEV_mode.c
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
#include "rtwtypes.h"
#include <string.h>
#include "HEV_mode_private.h"
#include "rt_nonfinite.h"

/* External inputs (root inport signals with default storage) */
ExtU_HEV_mode_T HEV_mode_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HEV_mode_T HEV_mode_Y;

/* Real-time model */
static RT_MODEL_HEV_mode_T HEV_mode_M_;
RT_MODEL_HEV_mode_T *const HEV_mode_M = &HEV_mode_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Model output function */
static void HEV_mode_output(void)
{
  real_T rtb_Gain;
  real_T rtb_Switch1;
  real_T rtb_Switch1_c;
  real_T rtb_Switch2;
  real_T rtb_uDLookupTable1;

  /* Lookup_n-D: '<S7>/1-D Lookup Table1' incorporates:
   *  Inport: '<Root>/Eng_spd'
   */
  rtb_uDLookupTable1 = look1_binlxpw(HEV_mode_U.Eng_spd,
    HEV_mode_P.f_tbrake_n_bpt, HEV_mode_P.f_tbrake_t_max_bpt, 10U);

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Inport: '<Root>/Mtr_spd'
   *  Inport: '<Root>/SOC'
   *  Lookup_n-D: '<S9>/1-D Lookup Table'
   */
  if (HEV_mode_U.SOC > HEV_mode_P.SOCCrit) {
    rtb_Switch1 = look1_binlxpw(HEV_mode_U.Mtr_spd, HEV_mode_P.f_mtr_w_bpt,
      HEV_mode_P.f_tmtr_max, 13U);
  } else {
    rtb_Switch1 = HEV_mode_P.Constant4_Value;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S8>/max_val'
   *  Constant: '<S8>/min_val'
   *  Inport: '<Root>/Eng_spd'
   *  Inport: '<Root>/SOC'
   *  Logic: '<S8>/conjunction'
   *  RelationalOperator: '<S8>/max_relop'
   *  RelationalOperator: '<S8>/min_relop'
   *  Switch: '<S1>/Switch3'
   */
  if (HEV_mode_U.SOC > HEV_mode_P.SOCCrit + 5.0) {
    rtb_Switch2 = HEV_mode_P.Constant4_Value_g;
  } else if ((HEV_mode_P.CheckStaticRange_min <= HEV_mode_U.Eng_spd) &&
             (HEV_mode_U.Eng_spd <= HEV_mode_P.CheckStaticRange_max)) {
    /* Switch: '<S1>/Switch3' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain3'
     *  Inport: '<Root>/Eng_spd'
     *  Lookup_n-D: '<S1>/1-D Lookup Table'
     */
    rtb_Switch2 = look1_binlxpw(HEV_mode_P.Gain_Gain * HEV_mode_U.Eng_spd,
      HEV_mode_P.f_mtr_w_bpt, HEV_mode_P.f_tmtr_max, 13U) *
      HEV_mode_P.Gain3_Gain;
  } else {
    /* Switch: '<S1>/Switch3' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    rtb_Switch2 = HEV_mode_P.Constant4_Value_g;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<Root>/Product' incorporates:
   *  Inport: '<Root>/Load_Signal'
   *  Sum: '<Root>/Add'
   */
  rtb_Gain = ((rtb_uDLookupTable1 + rtb_Switch1) + rtb_Switch2) *
    HEV_mode_U.Load_Signal;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/SOC'
   */
  if (!(HEV_mode_U.SOC > HEV_mode_P.SOCCrit)) {
    rtb_Switch1 = HEV_mode_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<Root>/Add1' */
  rtb_Switch1_c = rtb_Gain - rtb_Switch1;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/SOC'
   *  Switch: '<S2>/Switch1'
   */
  if (rtb_Gain <= rtb_Switch1) {
    /* Outputs for IfAction SubSystem: '<Root>/Mtr_only' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outport: '<Root>/Motor_Load' incorporates:
     *  Inport: '<Root>/Load_Signal'
     *  SignalConversion generated from: '<S3>/Load_Signal'
     */
    HEV_mode_Y.Motor_Load = HEV_mode_U.Load_Signal;

    /* SignalConversion generated from: '<S3>/Engine_Load' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Gain = HEV_mode_P.Constant_Value;

    /* End of Outputs for SubSystem: '<Root>/Mtr_only' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Hybrid//EngineOnly' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    if (HEV_mode_U.SOC > HEV_mode_P.SOCCrit) {
      /* Switch: '<S2>/Switch1' incorporates:
       *  Constant: '<S2>/Constant'
       *  Outport: '<Root>/Motor_Load'
       */
      HEV_mode_Y.Motor_Load = HEV_mode_P.Constant_Value_e;
    } else {
      /* Outport: '<Root>/Motor_Load' incorporates:
       *  Constant: '<S2>/Constant1'
       *  Switch: '<S2>/Switch1'
       */
      HEV_mode_Y.Motor_Load = HEV_mode_P.Constant1_Value;
    }

    /* End of Outputs for SubSystem: '<Root>/Hybrid//EngineOnly' */

    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    if (!(rtb_Switch1_c > HEV_mode_P.Switch2_Threshold)) {
      rtb_Switch1_c = HEV_mode_P.Constant3_Value;
    }

    /* Outputs for IfAction SubSystem: '<Root>/Hybrid//EngineOnly' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/LoadAid_Signal' incorporates:
     *  Product: '<Root>/Divide'
     *  Switch: '<Root>/Switch2'
     */
    rtb_Gain = rtb_Switch1_c / rtb_uDLookupTable1;

    /* End of Outputs for SubSystem: '<Root>/Hybrid//EngineOnly' */
  }

  /* End of If: '<Root>/If' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   *  RelationalOperator: '<S6>/LowerRelop1'
   *  RelationalOperator: '<S6>/UpperRelop'
   *  Switch: '<S6>/Switch'
   */
  if (rtb_Gain > HEV_mode_P.Constant9_Value) {
    /* Outport: '<Root>/Engine_Load' */
    HEV_mode_Y.Engine_Load = HEV_mode_P.Constant9_Value;
  } else if (rtb_Gain < HEV_mode_P.Constant8_Value) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<Root>/Constant8'
     *  Outport: '<Root>/Engine_Load'
     */
    HEV_mode_Y.Engine_Load = HEV_mode_P.Constant8_Value;
  } else {
    /* Outport: '<Root>/Engine_Load' incorporates:
     *  Switch: '<S6>/Switch'
     */
    HEV_mode_Y.Engine_Load = rtb_Gain;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<Root>/Switch' */
  if (rtb_Gain > HEV_mode_P.Switch_Threshold) {
    /* Outport: '<Root>/Clutch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    HEV_mode_Y.Clutch = HEV_mode_P.Constant_Value_i;
  } else {
    /* Outport: '<Root>/Clutch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    HEV_mode_Y.Clutch = HEV_mode_P.Constant1_Value_n;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outport: '<Root>/Generator2_TrqCmd' */
  HEV_mode_Y.Generator2_TrqCmd = rtb_Switch2;

  /* Switch: '<Root>/Switch3' */
  if (rtb_Gain > HEV_mode_P.Switch3_Threshold) {
    /* Outport: '<Root>/Eng_Switch' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    HEV_mode_Y.Eng_Switch = HEV_mode_P.Constant7_Value;
  } else {
    /* Outport: '<Root>/Eng_Switch' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    HEV_mode_Y.Eng_Switch = HEV_mode_P.Constant6_Value;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Lookup_n-D: '<S4>/1-D Lookup Table2' incorporates:
   *  Inport: '<Root>/Generator_spd'
   */
  rtb_Switch1_c = look1_binlxpw(HEV_mode_U.Generator_spd, HEV_mode_P.f_mtr_w_bpt,
    HEV_mode_P.f_tmtr_max, 13U);

  /* Gain: '<S4>/Gain' incorporates:
   *  Inport: '<Root>/BrkTrq_Cmd'
   */
  rtb_Gain = HEV_mode_P.Gain_Gain_m * HEV_mode_U.BrkTrq_Cmd;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Product: '<S4>/Divide1'
   */
  if (!(rtb_Gain / rtb_Switch1_c > HEV_mode_P.Switch1_Threshold)) {
    rtb_Switch1_c = rtb_Gain;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Gain: '<S4>/Gain1' */
  rtb_Switch2 = HEV_mode_P.Gain1_Gain * rtb_Switch1_c;

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  RelationalOperator: '<S5>/LowerRelop1'
   *  RelationalOperator: '<S5>/UpperRelop'
   *  Switch: '<S5>/Switch'
   */
  if (rtb_Switch2 > HEV_mode_P.Constant4_Value_e) {
    /* Outport: '<Root>/Generator_Trq' */
    HEV_mode_Y.Generator_Trq = HEV_mode_P.Constant4_Value_e;
  } else if (rtb_Switch2 < HEV_mode_P.Constant5_Value) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Outport: '<Root>/Generator_Trq'
     */
    HEV_mode_Y.Generator_Trq = HEV_mode_P.Constant5_Value;
  } else {
    /* Outport: '<Root>/Generator_Trq' incorporates:
     *  Switch: '<S5>/Switch'
     */
    HEV_mode_Y.Generator_Trq = rtb_Switch2;
  }

  /* End of Switch: '<S5>/Switch2' */

  /* Outport: '<Root>/FrBrk_Cmd' incorporates:
   *  Gain: '<S4>/Gain2'
   *  Sum: '<S4>/Add3'
   */
  HEV_mode_Y.FrBrk_Cmd = (rtb_Gain - rtb_Switch1_c) * HEV_mode_P.Gain2_Gain;
}

/* Model update function */
static void HEV_mode_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++HEV_mode_M->Timing.clockTick0)) {
    ++HEV_mode_M->Timing.clockTickH0;
  }

  HEV_mode_M->Timing.t[0] = HEV_mode_M->Timing.clockTick0 *
    HEV_mode_M->Timing.stepSize0 + HEV_mode_M->Timing.clockTickH0 *
    HEV_mode_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void HEV_mode_initialize(void)
{
}

/* Model terminate function */
static void HEV_mode_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  HEV_mode_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  HEV_mode_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  HEV_mode_initialize();
}

void MdlTerminate(void)
{
  HEV_mode_terminate();
}

/* Registration function */
RT_MODEL_HEV_mode_T *HEV_mode(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HEV_mode_M, 0,
                sizeof(RT_MODEL_HEV_mode_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = HEV_mode_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "HEV_mode_M points to
       static memory which is guaranteed to be non-NULL" */
    HEV_mode_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    HEV_mode_M->Timing.sampleTimes = (&HEV_mode_M->Timing.sampleTimesArray[0]);
    HEV_mode_M->Timing.offsetTimes = (&HEV_mode_M->Timing.offsetTimesArray[0]);

    /* task periods */
    HEV_mode_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    HEV_mode_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(HEV_mode_M, &HEV_mode_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = HEV_mode_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    HEV_mode_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(HEV_mode_M, 10.0);
  HEV_mode_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    HEV_mode_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HEV_mode_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HEV_mode_M->rtwLogInfo, (NULL));
    rtliSetLogT(HEV_mode_M->rtwLogInfo, "tout");
    rtliSetLogX(HEV_mode_M->rtwLogInfo, "");
    rtliSetLogXFinal(HEV_mode_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HEV_mode_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HEV_mode_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(HEV_mode_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HEV_mode_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &HEV_mode_Y.Engine_Load,
        &HEV_mode_Y.Motor_Load,
        &HEV_mode_Y.Clutch,
        &HEV_mode_Y.Generator_Trq,
        &HEV_mode_Y.FrBrk_Cmd,
        &HEV_mode_Y.Generator2_TrqCmd,
        &HEV_mode_Y.Eng_Switch
      };

      rtliSetLogYSignalPtrs(HEV_mode_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "HEV_mode/Engine_Load",
        "HEV_mode/Motor_Load",
        "HEV_mode/Clutch",
        "HEV_mode/Generator_Trq",
        "HEV_mode/FrBrk_Cmd",
        "HEV_mode/Generator2_TrqCmd",
        "HEV_mode/Eng_Switch" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          7,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(HEV_mode_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
    }

    rtliSetLogY(HEV_mode_M->rtwLogInfo, "yout");
  }

  HEV_mode_M->solverInfoPtr = (&HEV_mode_M->solverInfo);
  HEV_mode_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&HEV_mode_M->solverInfo, 0.2);
  rtsiSetSolverMode(&HEV_mode_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  HEV_mode_M->defaultParam = ((real_T *)&HEV_mode_P);

  /* external inputs */
  HEV_mode_M->inputs = (((void*)&HEV_mode_U));
  (void)memset(&HEV_mode_U, 0, sizeof(ExtU_HEV_mode_T));

  /* external outputs */
  HEV_mode_M->outputs = (&HEV_mode_Y);
  (void)memset(&HEV_mode_Y, 0, sizeof(ExtY_HEV_mode_T));

  /* Initialize Sizes */
  HEV_mode_M->Sizes.numContStates = (0);/* Number of continuous states */
  HEV_mode_M->Sizes.numY = (7);        /* Number of model outputs */
  HEV_mode_M->Sizes.numU = (6);        /* Number of model inputs */
  HEV_mode_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  HEV_mode_M->Sizes.numSampTimes = (1);/* Number of sample times */
  HEV_mode_M->Sizes.numBlocks = (81);  /* Number of blocks */
  HEV_mode_M->Sizes.numBlockIO = (0);  /* Number of block outputs */
  HEV_mode_M->Sizes.numBlockPrms = (77);/* Sum of parameter "widths" */
  return HEV_mode_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

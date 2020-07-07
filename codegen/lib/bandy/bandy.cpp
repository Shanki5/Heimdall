/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bandy.cpp
 *
 * Code generation for function 'bandy'
 *
 */

/* Include files */
#include "bandy.h"

/* Type Definitions */
struct dsp_FIRFilter_0
{
  int S0_isInitialized;
  double W0_states[420];
  double P0_InitialStates;
  double P1_Coefficients[2];
};

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  dsp_FIRFilter_0 cSFunObject;
} dspcodegen_FIRFilter;

/* Function Definitions */
void bandy(const double x[420], double y[420])
{
  dspcodegen_FIRFilter HdG;
  dspcodegen_FIRFilter *obj;
  dsp_FIRFilter_0 *b_obj;
  int k;
  double acc2;
  double acc1;
  int i;
  HdG.matlabCodegenIsDeleted = true;

  /* BANDY Filters input x and returns output y. */
  /*  MATLAB Code */
  /*  Generated by MATLAB(R) 9.6 and DSP System Toolbox 9.8. */
  /*  Generated on: 23-Aug-2019 22:21:09 */
  /*  To generate C/C++ code from this function use the codegen command. Type */
  /*  'help codegen' for more information. */
  obj = &HdG;
  HdG.isInitialized = 0;

  /* System object Constructor function: dsp.FIRFilter */
  obj->cSFunObject.P0_InitialStates = 0.0;
  obj->cSFunObject.P1_Coefficients[0] = 0.5;
  obj->cSFunObject.P1_Coefficients[1] = 0.5;
  HdG.matlabCodegenIsDeleted = false;

  /*   */
  obj = &HdG;
  if (HdG.isInitialized != 1) {
    HdG.isSetupComplete = false;
    HdG.isInitialized = 1;
    HdG.isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 420; k++) {
      obj->cSFunObject.W0_states[k] = obj->cSFunObject.P0_InitialStates;
    }
  }

  b_obj = &HdG.cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  for (k = 0; k < 420; k++) {
    /* Consume delay line and beginning of input samples */
    acc2 = x[k] * b_obj->P1_Coefficients[0];
    acc1 = acc2;
    acc2 = b_obj->W0_states[k] * b_obj->P1_Coefficients[1];
    acc1 += acc2;
    y[k] = acc1;

    /* Update delay line for next frame */
    for (i = k - 1; i >= k; i--) {
      b_obj->W0_states[i + 1] = b_obj->W0_states[i];
    }

    b_obj->W0_states[k] = x[k];
  }

  /*  [EOF] */
  if (!HdG.matlabCodegenIsDeleted) {
    HdG.matlabCodegenIsDeleted = true;
    if (HdG.isInitialized == 1) {
      HdG.isInitialized = 2;
    }
  }
}

/* End of code generation (bandy.cpp) */

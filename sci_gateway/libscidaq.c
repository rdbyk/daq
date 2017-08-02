#include <mex.h> 
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc sci_DAQ;
extern Gatefunc sci_DAQ_Failed;
extern Gatefunc sci_DAQ_Success;
extern Gatefunc sci_DAQ_CfgAnlgEdgeRefTrig;
extern Gatefunc sci_DAQ_CfgAnlgEdgeStartTrig;
extern Gatefunc sci_DAQ_CfgDigEdgeRefTrig;
extern Gatefunc sci_DAQ_CfgDigEdgeStartTrig;
extern Gatefunc sci_DAQ_CfgImplicitTiming;
extern Gatefunc sci_DAQ_CfgInputBuffer;
extern Gatefunc sci_DAQ_CfgSampClkTiming;
extern Gatefunc sci_DAQ_ClearTask;
extern Gatefunc sci_DAQ_CreateAIThrmcplChan;
extern Gatefunc sci_DAQ_CreateAIVoltageChan;
extern Gatefunc sci_DAQ_CreateAOVoltageChan;
extern Gatefunc sci_DAQ_CreateCICountEdgesChan;
extern Gatefunc sci_DAQ_CreateCIPeriodChan;
extern Gatefunc sci_DAQ_CreateCIPulseWidthChan;
extern Gatefunc sci_DAQ_CreateCOPulseChanFreq;
extern Gatefunc sci_DAQ_CreateDIChan;
extern Gatefunc sci_DAQ_CreateDOChan;
extern Gatefunc sci_DAQ_CreateTask;
extern Gatefunc sci_DAQ_DisableRefTrig;
extern Gatefunc sci_DAQ_DisableStartTrig;
extern Gatefunc sci_DAQ_GetExtendedErrorInfo;
extern Gatefunc sci_DAQ_IsTaskDone;
extern Gatefunc sci_DAQ_LoadTask;
extern Gatefunc sci_DAQ_ReadAnalogF64;
extern Gatefunc sci_DAQ_ReadBinaryI16;
extern Gatefunc sci_DAQ_ReadBinaryI32;
extern Gatefunc sci_DAQ_ReadCounterF64;
extern Gatefunc sci_DAQ_ReadCounterScalarF64;
extern Gatefunc sci_DAQ_ReadCounterScalarU32;
extern Gatefunc sci_DAQ_ReadCounterU32;
extern Gatefunc sci_DAQ_ReadDigitalScalarU32;
extern Gatefunc sci_DAQ_ReadDigitalU32;
extern Gatefunc sci_DAQ_ReadDigitalU8;
extern Gatefunc sci_DAQ_ResetDevice;
extern Gatefunc sci_DAQ_StartTask;
extern Gatefunc sci_DAQ_StopTask;
extern Gatefunc sci_DAQ_WriteAnalogF64;
extern Gatefunc sci_DAQ_WriteDigitalScalarU32;
extern Gatefunc sci_DAQ_WriteDigitalU32;
extern Gatefunc sci_DAQ_WriteDigitalU8;
extern Gatefunc sci_daq_p;
extern Gatefunc sci_daq_n_s;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway,sci_DAQ,"DAQ"},
  {(Myinterfun)sci_gateway,sci_DAQ_Failed,"DAQ_Failed"},
  {(Myinterfun)sci_gateway,sci_DAQ_Success,"DAQ_Success"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgAnlgEdgeRefTrig,"DAQ_CfgAnlgEdgeRefTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgAnlgEdgeStartTrig,"DAQ_CfgAnlgEdgeStartTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgDigEdgeRefTrig,"DAQ_CfgDigEdgeRefTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgDigEdgeStartTrig,"DAQ_CfgDigEdgeStartTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgImplicitTiming,"DAQ_CfgImplicitTiming"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgInputBuffer,"DAQ_CfgInputBuffer"},
  {(Myinterfun)sci_gateway,sci_DAQ_CfgSampClkTiming,"DAQ_CfgSampClkTiming"},
  {(Myinterfun)sci_gateway,sci_DAQ_ClearTask,"DAQ_ClearTask"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateAIThrmcplChan,"DAQ_CreateAIThrmcplChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateAIVoltageChan,"DAQ_CreateAIVoltageChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateAOVoltageChan,"DAQ_CreateAOVoltageChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateCICountEdgesChan,"DAQ_CreateCICountEdgesChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateCIPeriodChan,"DAQ_CreateCIPeriodChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateCIPulseWidthChan,"DAQ_CreateCIPulseWidthChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateCOPulseChanFreq,"DAQ_CreateCOPulseChanFreq"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateDIChan,"DAQ_CreateDIChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateDOChan,"DAQ_CreateDOChan"},
  {(Myinterfun)sci_gateway,sci_DAQ_CreateTask,"DAQ_CreateTask"},
  {(Myinterfun)sci_gateway,sci_DAQ_DisableRefTrig,"DAQ_DisableRefTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_DisableStartTrig,"DAQ_DisableStartTrig"},
  {(Myinterfun)sci_gateway,sci_DAQ_GetExtendedErrorInfo,"DAQ_GetExtendedErrorInfo"},
  {(Myinterfun)sci_gateway,sci_DAQ_IsTaskDone,"DAQ_IsTaskDone"},
  {(Myinterfun)sci_gateway,sci_DAQ_LoadTask,"DAQ_LoadTask"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadAnalogF64,"DAQ_ReadAnalogF64"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadBinaryI16,"DAQ_ReadBinaryI16"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadBinaryI32,"DAQ_ReadBinaryI32"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadCounterF64,"DAQ_ReadCounterF64"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadCounterScalarF64,"DAQ_ReadCounterScalarF64"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadCounterScalarU32,"DAQ_ReadCounterScalarU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadCounterU32,"DAQ_ReadCounterU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadDigitalScalarU32,"DAQ_ReadDigitalScalarU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadDigitalU32,"DAQ_ReadDigitalU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_ReadDigitalU8,"DAQ_ReadDigitalU8"},
  {(Myinterfun)sci_gateway,sci_DAQ_ResetDevice,"DAQ_ResetDevice"},
  {(Myinterfun)sci_gateway,sci_DAQ_StartTask,"DAQ_StartTask"},
  {(Myinterfun)sci_gateway,sci_DAQ_StopTask,"DAQ_StopTask"},
  {(Myinterfun)sci_gateway,sci_DAQ_WriteAnalogF64,"DAQ_WriteAnalogF64"},
  {(Myinterfun)sci_gateway,sci_DAQ_WriteDigitalScalarU32,"DAQ_WriteDigitalScalarU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_WriteDigitalU32,"DAQ_WriteDigitalU32"},
  {(Myinterfun)sci_gateway,sci_DAQ_WriteDigitalU8,"DAQ_WriteDigitalU8"},
  {(Myinterfun)sci_gateway,sci_daq_p,"%daq_p"},
  {(Myinterfun)sci_gateway,sci_daq_n_s,"%daq_n_s"},
};
 
int C2F(libscidaq)()
{
  Rhs = Max(0, Rhs);
  (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  return 0;
}

// Acquire a finite amount of data from analog input channel

// Channel parameters
chan    = "Dev1/ai0";
minVal  = -10.0;
maxVal  = +10.0;

// Timing parameters
source         = "OnboardClock";
samplesPerChan = 1000;
rate           = 10000.0;

// Data read parameters
bufferSize   = 1000;
pointsToRead = -1;
timeout      = 10.0;

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateAIVoltageChan(task, chan, DAQ("Val_Cfg_Default"),...
        minVal, maxVal);
        DAQ_ErrChk(task,err);
        
[err] = DAQ_CfgSampClkTiming(task, source, rate,...
        DAQ("Val_Rising"), DAQ("Val_FiniteSamps"),samplesPerChan);
        DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);

[data,pointsRead,err] = DAQ_ReadAnalogF64(task,pointsToRead,timeout,...
                        DAQ("Val_GroupByChannel"),bufferSize);
                        DAQ_ErrChk(task, err);

DAQ_StopTask( task );
DAQ_ClearTask( task );

mprintf ("Acquired %d samples\n",pointsRead);
for i=1:10
  mprintf ("data[%d] = %f\n",i,data(i));
end

clear chan minVal maxVal samplesPerChan pointsToRead timeout;
clear task err data pointsRead i;


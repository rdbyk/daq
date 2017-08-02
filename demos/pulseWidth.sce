// Measure pulse width on a counter input channel

// Channel parameters
chan    = "Dev1/ctr0";
minVal  = 0.000000100;
maxVal  = 0.830000000;

// Data read parameters
timeout = 10.0;

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateCIPulseWidthChan(task,chan,minVal,maxVal,..
        DAQ("Val_Seconds"), DAQ("Val_Rising"));
        DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);


[data,err] = DAQ_ReadCounterScalarF64(task,timeout);
             DAQ_ErrChk(task,err);

DAQ_StopTask(task);
DAQ_ClearTask(task);

mprintf("Measured Pulse Width: %.9f sec\n",data);
                                             
clear chan minVal maxVal timeout task err data;


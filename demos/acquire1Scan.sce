// Take one sample from an analog input channel

// Channel parameters
chan    = "Dev1/ai0";
minVal  = -10.0;
maxVal  = +10.0;

// Timing parameters
samplesPerChan = 1;

// Data read parameters
pointsToRead = 1;
timeout      = 10.0;

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateAIVoltageChan(task, chan, DAQ("Val_Cfg_Default"),...
        minVal, maxVal);
        DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);

[data,pointsRead,err] = DAQ_ReadAnalogF64(task,pointsToRead,timeout,...
                        DAQ("Val_GroupByChannel"),samplesPerChan);
                        DAQ_ErrChk(task, err);

DAQ_StopTask( task );
DAQ_ClearTask( task );

mprintf ("Acquired reading: %f\n", data );
                                             
clear chan minVal maxVal samplesPerChan pointsToRead timeout;
clear task err data pointsRead;


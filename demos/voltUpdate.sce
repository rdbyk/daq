// output a single sample to an analog output channel

// Channel parameters
chan    = "Dev1/ao0";
minVal  = 0.0;
maxVal  = 5.0;

// Timing parameters
samplesPerChan = 1;

// Data write parameters
data    = 3.45;
timeout = 10.0;

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateAOVoltageChan(task,chan,minVal,maxVal);
        DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);

[pointsWritten,err] = DAQ_WriteAnalogF64(task,samplesPerChan,timeout,...
                      DAQ("Val_GroupByChannel"),data);
                      DAQ_ErrChk(task, err);

DAQ_StopTask( task );
DAQ_ClearTask( task );
                                             
clear chan minVal maxVal samplesPerChan timeout;
clear task err data pointsWritten;


// Write values from an digital input channel

// Channel parameters
chan    = "Dev1/port0";

// Data write parameters
pointsToWrite = 1;
timeout       = 10.0;
data          = uint32(85); // 0x55

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateDOChan(task,chan); DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);

[pointsWritten,err] = DAQ_WriteDigitalU32(task,1,%t,timeout,....
                                          DAQ("Val_GroupByChannel"),data);
                      DAQ_ErrChk(task, err);

DAQ_StopTask( task );
DAQ_ClearTask( task );
                                             
clear chan pointsToWrite timeout;
clear task err pointsWritten;

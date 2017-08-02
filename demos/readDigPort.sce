// Read values from an digital input channel

// Channel parameters
chan    = "Dev1/port0";

// Timing parameters
samplesPerChan = 1;

// Data read parameters
pointsToRead = 1;
timeout      = 10.0;

[task,err] = DAQ_CreateTask(""); DAQ_ErrChk(task,err);

[err] = DAQ_CreateDIChan(task,chan); DAQ_ErrChk(task,err);
        
[err] = DAQ_StartTask(task); DAQ_ErrChk(task,err);

[data,pointsRead,err] = DAQ_ReadDigitalU8(task,pointsToRead,timeout,...
                        DAQ("Val_GroupByChannel"),samplesPerChan);
                        DAQ_ErrChk(task, err);

DAQ_StopTask( task );
DAQ_ClearTask( task );

mprintf ("Acquired reading: 0x%X\n", data );
                                             
clear chan samplesPerChan pointsToRead timeout;
clear task err pointsRead;


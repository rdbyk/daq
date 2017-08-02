// DAQ Toolbox
// Copyright (C) 2008  Dirk Reusch, Kybernetik Dr. Reusch
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "sci_daq_task.h"

// DAQmxBaseClearTask
// [status] = DAQ_ClearTask( taskHandle )
DAQ_TASK_1( DAQ_ClearTask, DAQmxBaseClearTask );

// DAQmxBaseStartTask
// [status] = DAQ_StartTask( taskHandle )
DAQ_TASK_1( DAQ_StartTask, DAQmxBaseStartTask );

// DAQmxBaseStopTask
// [status] = DAQ_StopTask( taskHandle )
DAQ_TASK_1( DAQ_StopTask, DAQmxBaseStopTask );

// DAQmxBaseCreateTask
// [taskHandle, status] = DAQ_CreateTask( taskName )
DAQ_TASK_2( DAQ_CreateTask, DAQmxBaseCreateTask );

// DAQmxBaseLoadTask
// [taskHandle, status] = DAQ_LoadTask( taskName )
DAQ_TASK_2( DAQ_LoadTask, DAQmxBaseLoadTask );

// DAQmxBaseIsTaskDone
// [isTaskDone, status] = DAQ_IsTaskDone( taskHandle )
int sci_DAQ_IsTaskDone( char* fname )
{	
	TaskHandle taskHandle = 0;
	bool32 isTaskDone = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 1, 1 );
	CheckLhs( 1, 2 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	
	status = DAQmxBaseIsTaskDone( taskHandle, &isTaskDone );
	
	CreateBool32( 2, isTaskDone, m, n, l );
	CreateInt32( 3, status, m, n, l );

	LhsVar(1) = 2;
	LhsVar(2) = 3;
	
	return 0;
}

// DAQmxBaseResetDevice
// [status] = DAQ_ResetDevice( deviceName )
int sci_DAQ_ResetDevice( char* fname )
{
	char *deviceName = NULL;
	int32 status = 0;
	
	int m, n, l;
	
	CheckRhs( 1, 1 );
	CheckLhs( 1, 1 );
	
	GetRhsString( 1, deviceName, m, n, l );
	
	status = DAQmxBaseResetDevice( deviceName );
	
	CreateInt32( 2, status, m, n, l );
	
	LhsVar(1) = 2;
	
	return 0;
}

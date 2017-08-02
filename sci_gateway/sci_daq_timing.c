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

#include "sci_daq.h"

// DAQmxBaseCfgSampClkTiming
// [status] = DAQ_CfgSampClkTiming ( taskHandle, source, rate,
//                                   activeEdge, sampleMode,
//                                   sampsPerChanToAcquire )
int sci_DAQ_CfgSampClkTiming( char* fname )
{
	TaskHandle taskHandle = 0;
	char *source = NULL;
	float64 rate = 0.0;
	int32 activeEdge = 0;
	int32 sampleMode = 0;
	uInt64 sampsPerChanToAcquire = 0L;
	int32 status = 0;
	
	int m, n, l;
	
	CheckRhs( 6, 6 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsString( 2, source, m, n, l );
	GetRhsFloat64( 3, rate, m, n, l );
	GetRhsInt32( 4, activeEdge, m, n, l );
	GetRhsInt32( 5, sampleMode, m, n, l );
	// FIXME: GetRhsUInt64?
	GetRhsUInt32( 6, sampsPerChanToAcquire, m, n, l );
	
	status = DAQmxBaseCfgSampClkTiming( taskHandle, source, rate,
	                                     activeEdge, sampleMode,
	                                     sampsPerChanToAcquire );
	
	CreateInt32( 7, status, m, n, l );
	
	LhsVar(1) = 7;
	
	return 0;
}


// DAQmxBaseCfgImplicitTiming
// [status] = DAQ_CfgImplicitTiming ( taskHandle, sampleMode,
//                                    sampsPerChanToAcquire )
int sci_DAQ_CfgImplicitTiming( char* fname )
{
	TaskHandle taskHandle = 0;
	int32 sampleMode = 0;
	uInt64 sampsPerChanToAcquire = 0L;
	int32 status = 0;
	
	int m, n, l;
	
	CheckRhs( 3, 3 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsInt32( 2, sampleMode, m, n, l );
	// FIXME: GetRhsUInt64?
	GetRhsUInt32( 3, sampsPerChanToAcquire, m, n, l );
	
	status = DAQmxBaseCfgImplicitTiming( taskHandle, sampleMode,
	                                     sampsPerChanToAcquire );
	
	CreateInt32( 4, status, m, n, l );
	
	LhsVar(1) = 4;
	
	return 0;
}

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

#include "sci_daq_trigger.h"

// DAQmxBaseDisableStartTrig
// [status] = DAQ_DisableStartTrig( taskHandle )
DAQ_TRIGGER_1( DAQ_DisableStartTrig, DAQmxBaseDisableStartTrig );

// DAQmxBaseCfgDigEdgeStartTrig
// [status] = DAQ_CfgDigEdgeStartTrig( taskHandle, triggerSource,
//                                      triggerEdge )
int sci_DAQ_CfgDigEdgeStartTrig( char* fname )
{	
	TaskHandle taskHandle = 0;
	char* triggerSource =  NULL;
	int32 triggerEdge = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 3, 3 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsString( 2, triggerSource, m, n, l );
	GetRhsInt32( 3, triggerEdge, m, n, l );
	
	status = DAQmxBaseCfgDigEdgeStartTrig( taskHandle, triggerSource,
	                                       triggerEdge );
	
	CreateInt32( 4, status, m, n, l );

	LhsVar(1) = 4;
	
	return 0;
}


// DAQmxBaseCfgAnlgEdgeStartTrig
// [status] = DAQ_CfgAnlgEdgeStartTrig( taskHandle, triggerSource,
//                                      triggerSlope, triggerLevel )
int sci_DAQ_CfgAnlgEdgeStartTrig( char* fname )
{	
	TaskHandle taskHandle = 0;
	char* triggerSource =  NULL;
	int32 triggerSlope = 0;
	float64 triggerLevel = 0.0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsString( 2, triggerSource, m, n, l );
	GetRhsInt32( 3, triggerSlope, m, n, l );
	GetRhsFloat64( 4, triggerLevel, m, n, l );
	
	status = DAQmxBaseCfgAnlgEdgeStartTrig( taskHandle, triggerSource,
	                                       triggerSlope, triggerLevel );
	
	CreateInt32( 5, status, m, n, l );

	LhsVar(1) = 5;
	
	return 0;
}


// DAQmxBaseCfgAnlgEdgeRefTrig
// [status] = DAQ_CfgAnlgEdgeRefTrig( taskHandle, triggerSource,
//                                    triggerSlope, triggerLevel,
//                                    pretriggerSamples )
int sci_DAQ_CfgAnlgEdgeRefTrig( char* fname )
{	
	TaskHandle taskHandle = 0;
	char* triggerSource =  NULL;
	int32 triggerSlope = 0;
	float64 triggerLevel = 0.0;
	uInt32 pretriggerSamples = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 5, 5 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsString( 2, triggerSource, m, n, l );
	GetRhsInt32( 3, triggerSlope, m, n, l );
	GetRhsFloat64( 4, triggerLevel, m, n, l );
	GetRhsUInt32( 5, pretriggerSamples, m, n, l );
	
	status = DAQmxBaseCfgAnlgEdgeRefTrig( taskHandle, triggerSource,
	                                      triggerSlope, triggerLevel,
	                                      pretriggerSamples );
	
	CreateInt32( 6, status, m, n, l );

	LhsVar(1) = 6;
	
	return 0;
}


// DAQmxBaseCfgDigEdgeRefTrig
// [status] = DAQ_CfgDigEdgeRefTrig( taskHandle, triggerSource,
//                                   triggerEdge, pretriggerSamples )
int sci_DAQ_CfgDigEdgeRefTrig( char* fname )
{	
	TaskHandle taskHandle = 0;
	char* triggerSource =  NULL;
	int32 triggerEdge = 0;
	uInt32 pretriggerSamples = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsString( 2, triggerSource, m, n, l );
	GetRhsInt32( 3, triggerEdge, m, n, l );
	GetRhsUInt32( 4, pretriggerSamples, m, n, l );
	
	status = DAQmxBaseCfgDigEdgeRefTrig( taskHandle, triggerSource,
	                                     triggerEdge,
	                                     pretriggerSamples );
	
	CreateInt32( 5, status, m, n, l );

	LhsVar(1) = 5;
	
	return 0;
}


// DAQmxBaseDisableRefTrig
// [status] = DAQ_DisableRefTrig( taskHandle )
DAQ_TRIGGER_1( DAQ_DisableRefTrig, DAQmxBaseDisableRefTrig );

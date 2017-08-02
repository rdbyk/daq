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

#include "sci_daq_channel.h"

// DAQmxBaseCreateAIThrmcplChan
// [status] = DAQ_CreateAIThrmcplChan( taskHandle, physicalChannel,
//                                      minVal, maxVal, units,
//                                      thermocoupleType,
//                                      cjcSource, cjcVal, cjcChannel )
//
int sci_DAQ_CreateAIThrmcplChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *physicalChannel = NULL;
	float64 minVal = 0.0;
	float64 maxVal = 0.0;
	int32 units = 0;
	int32 thermocoupleType = 0;
	int32 cjcSource = 0;
	float64 cjcVal = 0.0;
	char *cjcChannel = NULL;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 9, 9 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, physicalChannel, m, n, l );
	GetRhsFloat64( 3, minVal, m, n, l );
	GetRhsFloat64( 4, maxVal, m, n, l );
	GetRhsInt32( 5, units, m, n, l );
	GetRhsInt32( 6, thermocoupleType, m, n, l );
	GetRhsInt32( 7, cjcSource, m, n, l );
	GetRhsFloat64( 8, cjcVal, m, n, l );
	GetRhsString( 9, cjcChannel, m, n, l );
	
	status = DAQmxBaseCreateAIThrmcplChan( taskHandle,
	                                        physicalChannel,
	                                        NULL,
	                                        minVal,
	                                        maxVal,
	                                        units,
	                                        thermocoupleType,
	                                        cjcSource,
	                                        cjcVal,
	                                        cjcChannel );

	CreateInt32( 10, status, m, n, l );

	LhsVar(1) = 10;
	
	return 0;
}


// DAQmxBaseCreateAIVoltageChan
// [status] = DAQ_CreateAIVoltageChan( taskHandle, physicalChannel,
//                                     terminalConfig, minVal, maxVal )
//
int sci_DAQ_CreateAIVoltageChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *physicalChannel = NULL;
	int32 terminalConfig = 0;
	float64 minVal = 0.0;
	float64 maxVal = 0.0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 5, 5 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, physicalChannel, m, n, l );
	GetRhsInt32( 3, terminalConfig, m, n, l );
	GetRhsFloat64( 4, minVal, m, n, l );
	GetRhsFloat64( 5, maxVal, m, n, l );
	
	status = DAQmxBaseCreateAIVoltageChan( taskHandle,
	                                       physicalChannel,
	                                       NULL,
	                                       terminalConfig,
	                                       minVal,
	                                       maxVal,
	                                       DAQmx_Val_Volts,
	                                       NULL );

	CreateInt32( 6, status, m, n, l );

	LhsVar(1) = 6;
	
	return 0;
}

// DAQmxBaseCreateAOVoltageChan
// [status] = DAQ_CreateAOVoltageChan( taskHandle, physicalChannel,
//                                      minVal, maxVal )
//
int sci_DAQ_CreateAOVoltageChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *physicalChannel = NULL;
	float64 minVal = 0.0;
	float64 maxVal = 0.0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, physicalChannel, m, n, l );
	GetRhsFloat64( 3, minVal, m, n, l );
	GetRhsFloat64( 4, maxVal, m, n, l );
	
	status = DAQmxBaseCreateAOVoltageChan( taskHandle,
	                                       physicalChannel,
	                                       NULL,
	                                       minVal,
	                                       maxVal,
	                                       DAQmx_Val_Volts,
	                                       NULL );

	CreateInt32( 5, status, m, n, l );

	LhsVar(1) = 5;
	
	return 0;
}


// DAQmxBaseCreateDIChan
// [ status ] = DAQ_CreateDIChan (taskHandle, lines )
DAQ_CHANNEL_1( DAQ_CreateDIChan, DAQmxBaseCreateDIChan );

// DAQmxBaseCreateDOChan
// [ status ] = DAQ_CreateDOChan (taskHandle, lines )
DAQ_CHANNEL_1( DAQ_CreateDOChan, DAQmxBaseCreateDOChan );

// DAQmxBaseCreateCIPeriodChan
// [status] = DAQ_CreateCIPeriodChan( taskHandle, counter,
//                                    minVal, maxVal, units, edge )
//
int sci_DAQ_CreateCIPeriodChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *counter = NULL;
	float64 minVal = 0.0;
	float64 maxVal = 0.0;
	int32 units = 0;
	int32 edge = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 6, 6 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, counter, m, n, l );
	GetRhsFloat64( 3, minVal, m, n, l );
	GetRhsFloat64( 4, maxVal, m, n, l );
	GetRhsInt32( 5, units, m, n, l );
	GetRhsInt32( 6, edge, m, n, l );
	
	status = DAQmxBaseCreateCIPeriodChan( taskHandle,
	                                      counter,
	                                      NULL,
	                                      minVal,
	                                      maxVal,
	                                      units,
	                                      edge,
	                                      DAQmx_Val_LowFreq1Ctr,
	                                      0,
	                                      1,
	                                      NULL );

	CreateInt32( 7, status, m, n, l );

	LhsVar(1) = 7;
	
	return 0;
}


// DAQmxBaseCreateCICountEdgesChan
// [status] = DAQ_CreateCICountEdgesChan( taskHandle, counter, edge,
//                                        initialCount,
//                                        countDirection )
//
int sci_DAQ_CreateCICountEdgesChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *counter = NULL;
	int32 edge = 0;
	uInt32 initialCount = 0;
	int32 countDirection = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 5, 5 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, counter, m, n, l );
	GetRhsInt32( 3, edge, m, n, l );
	GetRhsUInt32( 4, initialCount, m, n, l );
	GetRhsInt32( 5, countDirection, m, n, l );
	
	status = DAQmxBaseCreateCICountEdgesChan( taskHandle,
	                                          counter,
	                                          NULL,
	                                          edge,
	                                          initialCount,
	                                          countDirection );

	CreateInt32( 6, status, m, n, l );

	LhsVar(1) = 6;
	
	return 0;
}


// DAQmxBaseCreateCIPulseWidthChan
// [status] = DAQ_CreateCIPulseWidthChan( taskHandle, counter,
//                                        minVal, maxVal, units,
//                                        startingEdge )
//
int sci_DAQ_CreateCIPulseWidthChan( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *counter = NULL;
	float64 minVal = 0.0;
	float64 maxVal = 0.0;
	int32 units = 0;
	int32 startingEdge = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 6, 6 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, counter, m, n, l );
	GetRhsFloat64( 3, minVal, m, n, l );
	GetRhsFloat64( 4, maxVal, m, n, l );
	GetRhsInt32( 5, units, m, n, l );
	GetRhsInt32( 6, startingEdge, m, n, l );
	
	status = DAQmxBaseCreateCIPulseWidthChan( taskHandle,
	                                          counter,
	                                          NULL,
	                                          minVal,
	                                          maxVal,
	                                          units,
	                                          startingEdge,
	                                          NULL );

	CreateInt32( 7, status, m, n, l );

	LhsVar(1) = 7;
	
	return 0;
}


// DAQmxBaseCreateCOPulseChanFreq
// [status] = DAQ_CreateCOPulseChanFreq( taskHandle, counter,
//                                       idleState, initialDelay,
//                                       freq, dutyCycle )
//
int sci_DAQ_CreateCOPulseChanFreq( char* fname )
{	
	TaskHandle taskHandle = 0;
	char *counter = NULL;
	int32 idleState = 0;
	float64 initialDelay = 0.0;
	float64 freq = 0.0;
	float64 dutyCycle = 0.0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 6, 6 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsString( 2, counter, m, n, l );
	GetRhsInt32( 3, idleState, m, n, l );
	GetRhsFloat64( 4, initialDelay, m, n, l );
	GetRhsFloat64( 5, freq, m, n, l );
	GetRhsFloat64( 6, dutyCycle, m, n, l );
	
	status = DAQmxBaseCreateCOPulseChanFreq( taskHandle,
	                                         counter,
	                                         NULL,
	                                         DAQmx_Val_Hz,
	                                         idleState,
	                                         initialDelay,
	                                         freq,
	                                         dutyCycle );

	CreateInt32( 7, status, m, n, l );

	LhsVar(1) = 7;
	
	return 0;
}

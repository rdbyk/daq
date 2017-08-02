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

#include "sci_daq_read.h"

// DAQmxBaseReadAnalogF64
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadAnalogF64( taskHandle, numSampsPerChan, timeout, fillMode,
//                    arraySizeInSamps )
int sci_DAQ_ReadAnalogF64( char* fname )
{	
	TaskHandle taskHandle = 0;
	int32 numSampsPerChan = 0;
	float64 timeout = 0.0;
	bool32 fillMode = 0;
	float64 *readArray = NULL;
	uInt32 arraySizeInSamps = 0;
	int32 sampsPerChanRead = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 5, 5 );
	CheckLhs( 1, 3 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsInt32(2, numSampsPerChan, m, n, l );
	GetRhsFloat64( 3, timeout, m, n, l );
	GetRhsInt32( 4, fillMode, m, n, l );
	GetRhsUInt32( 5, arraySizeInSamps, m, n, l );

	m = 1;
	n = arraySizeInSamps;
	CreateVar( 6, "d" ,&m ,&n , &l);
	readArray = stk( l );
	
	status = DAQmxBaseReadAnalogF64( taskHandle, numSampsPerChan,
	                                 timeout, fillMode,
	                                 readArray, arraySizeInSamps,
	                                 &sampsPerChanRead,
	                                 ( bool32* )NULL );
	
	CreateInt32( 7, sampsPerChanRead, m, n, l );
	CreateInt32( 8, status, m, n, l );

	LhsVar( 1 ) = 6;
	LhsVar( 2 ) = 7;
	LhsVar( 3 ) = 8;
		
	return 0;
}


// DAQmxBaseReadBinaryI16
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadBinaryI16( taskHandle, numSampsPerChan, timeout, fillMode,
//                    arraySizeInSamps )
//
DAQ_READ_1( DAQ_ReadBinaryI16, INT16, DAQmxBaseReadBinaryI16, int16 );


// DAQmxBaseReadBinaryI32
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadBinaryI32( taskHandle, numSampsPerChan, timeout, fillMode,
//                    arraySizeInSamps )
//
DAQ_READ_1( DAQ_ReadBinaryI32, INT32, DAQmxBaseReadBinaryI32, int32 );


// DAQmxBaseReadCounterF64
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadCounterF64( taskHandle, numSampsPerChan, timeout,
//                     arraySizeInSamps )
int sci_DAQ_ReadCounterF64( char* fname )
{	
	TaskHandle taskHandle = 0;
	int32 numSampsPerChan = 0;
	float64 timeout = 0.0;
	float64 *readArray = NULL;
	uInt32 arraySizeInSamps = 0;
	int32 sampsPerChanRead = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 3 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsInt32(2, numSampsPerChan, m, n, l );
	GetRhsFloat64( 3, timeout, m, n, l );
	GetRhsUInt32( 4, arraySizeInSamps, m, n, l );

	m = 1;
	n = arraySizeInSamps;
	CreateVar( 5, "d" ,&m ,&n , &l);
	readArray = stk( l );
	
	status = DAQmxBaseReadCounterF64( taskHandle, numSampsPerChan,
	                                  timeout,
	                                  readArray, arraySizeInSamps,
	                                  &sampsPerChanRead,
	                                  ( bool32* )NULL );
	
	CreateInt32( 6, sampsPerChanRead, m, n, l );
	CreateInt32( 7, status, m, n, l );

	LhsVar( 1 ) = 5;
	LhsVar( 2 ) = 6;
	LhsVar( 3 ) = 7;
		
	return 0;
}


// DAQmxBaseReadCounterScalarF64
// [value, status] = DAQ_ReadCounterScalarF64( taskHandle, timeout )
int sci_DAQ_ReadCounterScalarF64( char* fname )
{	
	TaskHandle taskHandle = 0;
	float64 timeout = 0.0;
	float64 *value = NULL;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 2, 2 );
	CheckLhs( 1, 2 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsFloat64( 2, timeout, m, n, l );

	m = 1;
	n = 1;
	CreateVar( 3, "d" ,&m ,&n , &l);
	value = stk( l );
	
	status = DAQmxBaseReadCounterScalarF64( taskHandle,
	                                        timeout,
	                                        value,
	                                        ( bool32* )NULL );

	CreateInt32( 4, status, m, n, l );

	LhsVar( 1 ) = 3;
	LhsVar( 2 ) = 4;
		
	return 0;
}


// DAQmxBaseReadCounterScalarU32
// [value, status] = DAQ_ReadCounterScalarU32( taskHandle, timeout )
DAQ_READ_2( DAQ_ReadCounterScalarU32, DAQmxBaseReadCounterScalarU32 );


// DAQmxBaseReadCounterU32
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadCounterU32( taskHandle, numSampsPerChan, timeout,
//                     arraySizeInSamps )
int sci_DAQ_ReadCounterU32( char* fname )
{	
	TaskHandle taskHandle = 0;
	int32 numSampsPerChan = 0;
	float64 timeout = 0.0;
	uInt32 *readArray = NULL;
	uInt32 arraySizeInSamps = 0;
	int32 sampsPerChanRead = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 3 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsInt32(2, numSampsPerChan, m, n, l );
	GetRhsFloat64( 3, timeout, m, n, l );
	GetRhsUInt32( 4, arraySizeInSamps, m, n, l );

	m = 1;
	n = arraySizeInSamps;
	l = I_UINT32;
	CreateVar( 5, "I" ,&m ,&n , &l);
	readArray = IC_UINT32( istk( l ) );
	
	status = DAQmxBaseReadCounterU32( taskHandle, numSampsPerChan,
	                                  timeout,
	                                  readArray, arraySizeInSamps,
	                                  &sampsPerChanRead,
	                                  ( bool32* )NULL );
	
	CreateInt32( 6, sampsPerChanRead, m, n, l );
	CreateInt32( 7, status, m, n, l );

	LhsVar( 1 ) = 5;
	LhsVar( 2 ) = 6;
	LhsVar( 3 ) = 7;
		
	return 0;
}


// DAQmxBaseReadDigitalScalarU32
// [value, status] = DAQ_ReadDigitalScalarU32( taskHandle, timeout )
DAQ_READ_2( DAQ_ReadDigitalScalarU32, DAQmxBaseReadDigitalScalarU32 );


// DAQmxBaseReadDigitalU32
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadDigitalU32( taskHandle, numSampsPerChan, timeout, fillMode,
//                     arraySizeInSamps )
//
DAQ_READ_1( DAQ_ReadDigitalU32, UINT32, DAQmxBaseReadDigitalU32, uInt32 );


// DAQmxBaseReadDigitalU8
// [readArray, sampsPerChanRead, status] =
// DAQ_ReadDigitalU8( taskHandle, numSampsPerChan, timeout, fillMode,
//                    arraySizeInSamps )
//
DAQ_READ_1( DAQ_ReadDigitalU8, UCHAR, DAQmxBaseReadDigitalU8, uInt8 );

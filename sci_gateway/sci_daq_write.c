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

#include "sci_daq_write.h"

// DAQmxBaseWriteAnalogF64
// [sampsPerChanWritten, status] =
//  DAQ_WriteAnalogF64( taskHandle, numSampsPerChan, timeout,
//                      dataLayout, writeArray ) 
int sci_DAQ_WriteAnalogF64( char* fname )
{	
	TaskHandle taskHandle = 0;
	int32 numSampsPerChan = 0;
	float64 timeout = 0.0;
	bool32 dataLayout = 0;
	float64 *writeArray = NULL;
	int32 sampsPerChanWritten = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 5, 5 );
	CheckLhs( 1, 2 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsInt32(2, numSampsPerChan, m, n, l );
	GetRhsFloat64( 3, timeout, m, n, l );
	GetRhsInt32( 4, dataLayout, m, n, l );

//  FIXME: GetRhsArrayFloat64?
    GetRhsVar( 5, "d", &m, &n, &l);
	writeArray = stk( l );
	CheckVector( 5, m, n );
	
	status = DAQmxBaseWriteAnalogF64( taskHandle,  numSampsPerChan,
	                                  FALSE , timeout, dataLayout,
	                                  writeArray, &sampsPerChanWritten,
	                                  ( bool32* )NULL );
	
	CreateInt32( 6, sampsPerChanWritten, m, n, l );
	CreateInt32( 7, status, m, n, l );

	LhsVar( 1 ) = 6;
	LhsVar( 2 ) = 7;
		
	return 0;
}

// DAQmxBaseWriteDigitalU8
// [sampsPerChanWritten, status] =
//  DAQ_WriteDigitalU8( taskHandle, numSampsPerChan, autoStart,
//                      timeout, dataLayout, writeArray ) 
DAQ_WRITE_1( DAQ_WriteDigitalU8, UCHAR, DAQmxBaseWriteDigitalU8, uInt8 );
             

// DAQmxBaseWriteDigitalU32
// [sampsPerChanWritten, status] =
//  DAQ_WriteDigitalU32( taskHandle, numSampsPerChan, autoStart,
//                       timeout, dataLayout, writeArray ) 
DAQ_WRITE_1( DAQ_WriteDigitalU32, UINT32,
             DAQmxBaseWriteDigitalU32, uInt32 );


// DAQmxBaseWriteDigitalScalarU32
// [status] =
//  DAQ_WriteDigitalScalarU32( taskHandle, autoStart, timeout, value )
int sci_DAQ_WriteDigitalScalarU32( char* fname )
{	
	TaskHandle taskHandle = 0;
	bool32 autoStart = FALSE;
	float64 timeout = 0.0;
	uInt32 value = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 4, 4 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );
	GetRhsBool32( 2, autoStart, m, n, l );
	GetRhsFloat64( 3, timeout, m, n, l );
	GetRhsUInt32( 4, value, m, n, l );
	
	status = DAQmxBaseWriteDigitalScalarU32( taskHandle,  autoStart,
	                                         timeout, value,
	                                         ( bool32* ) NULL );
	
	CreateInt32( 5, status, m, n, l );

	LhsVar( 1 ) = 5;
		
	return 0;
}

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

// [readArray, sampsPerChanRead, status] = NAME( taskHandle,
//                                               numSampsPerChan,
//                                               timeout,
//                                               fillMode,
//                                               arraySizeInSamps )

#define DAQ_READ_1(NAME,TYPE,NI_NAME,NI_TYPE)                        \
                                                                     \
int sci_##NAME( char* fname )                                        \
{                                                                    \
	TaskHandle taskHandle = 0;                                       \
	int32 numSampsPerChan = 0;                                       \
	float64 timeout = 0.0;                                           \
	bool32 fillMode = 0;                                             \
	NI_TYPE *readArray = NULL;                                       \
	uInt32 arraySizeInSamps = 0;                                     \
	int32 sampsPerChanRead = 0;                                      \
	int32 status = 0;                                                \
                                                                     \
	int m, n, l;                                                     \
	                                                                 \
	CheckRhs( 5, 5 );                                                \
	CheckLhs( 1, 3 );                                                \
	                                                                 \
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );                     \
	GetRhsInt32(2, numSampsPerChan, m, n, l );                       \
	GetRhsFloat64( 3, timeout, m, n, l );                            \
	GetRhsInt32( 4, fillMode, m, n, l );                             \
    GetRhsUInt32( 5, arraySizeInSamps, m, n, l );                    \
                                                                     \
	m = 1;                                                           \
	n = arraySizeInSamps;                                            \
	l = I_##TYPE;                                                    \
	CreateVar( 6,"I" ,&m ,&n , &l);                                  \
	readArray = IC_##TYPE( istk( l ) );                              \
                                                                     \
	status = NI_NAME( taskHandle, numSampsPerChan,                   \
	                  timeout, fillMode,                             \
	                  readArray, arraySizeInSamps,                   \
	                  &sampsPerChanRead,                             \
	                  ( bool32* )NULL );                             \
                                                                     \
	CreateInt32( 7, sampsPerChanRead, m, n, l );                     \
	CreateInt32( 8, status, m, n, l );                               \
                                                                     \
	LhsVar( 1 ) = 6;                                                 \
	LhsVar( 2 ) = 7;                                                 \
	LhsVar( 3 ) = 8;                                                 \
                                                                     \
	return 0;                                                        \
}


// [value, status] = NAME( taskHandle, timeout )

#define DAQ_READ_2(NAME,NI_NAME)                                     \
                                                                     \
int sci_##NAME( char* fname )                                        \
{                                                                    \
	TaskHandle taskHandle = 0;                                       \
	float64 timeout = 0.0;                                           \
	uInt32 *value = NULL;                                            \
	int32 status = 0;                                                \
                                                                     \
	int m, n, l;                                                     \
	                                                                 \
	CheckRhs( 2, 2 );                                                \
	CheckLhs( 1, 2 );                                                \
	                                                                 \
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );                     \
	GetRhsFloat64( 2, timeout, m, n, l );                            \
                                                                     \
	m = 1;                                                           \
	n = 1;                                                           \
	l = I_UINT32;                                                    \
	CreateVar( 3, "I" , &m , &n , &l);                               \
	value = IC_UINT32( istk( l ) );                                  \
	                                                                 \
	status = NI_NAME( taskHandle, timeout, value, ( bool32* )NULL ); \
                                                                     \
	CreateInt32( 4, status, m, n, l );                               \
                                                                     \
	LhsVar( 1 ) = 3;                                                 \
	LhsVar( 2 ) = 4;                                                 \
                                                                     \
	return 0;                                                        \
}

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

// [sampsPerChanWritten, status] = NAME( taskHandle,
//                                       numSampsPerChan,
//                                       autoStart,
//                                       timeout,
//                                       dataLayout,
//                                       writeArray )

#define DAQ_WRITE_1(NAME,TYPE,NI_NAME,NI_TYPE)                       \
                                                                     \
int sci_##NAME( char* fname )                                        \
{                                                                    \
	TaskHandle taskHandle = 0;                                       \
	int32 numSampsPerChan = 0;                                       \
	bool32 autoStart = FALSE;                                        \
	float64 timeout = 0.0;                                           \
	bool32 dataLayout = 0;                                           \
	NI_TYPE *writeArray = NULL;                                      \
	int32 sampsPerChanWritten = 0;                                   \
	int32 status = 0;                                                \
                                                                     \
	int m, n, l;                                                     \
	SciIntMat L;                                                     \
	                                                                 \
	CheckRhs( 6, 6 );                                                \
	CheckLhs( 1, 2 );                                                \
                                                                     \
	GetRhsTaskHandle( 1, taskHandle,  m, n, l );                     \
	GetRhsInt32( 2, numSampsPerChan, m, n, l );                      \
	GetRhsBool32( 3, autoStart, m, n, l );                           \
	GetRhsFloat64( 4, timeout, m, n, l );                            \
	GetRhsInt32( 5, dataLayout, m, n, l );                           \
                                                                     \
    GetRhsVar( 6, "I", &m, &n, &L);                                  \
    CheckVector( 6, m, n );                                          \
    if ( L.it != I_##TYPE ) {                                        \
    	Scierror( 999,                                               \
    	          "%s: argument has wrong integer type!", fname );   \
    	return 0;                                                    \
	}                                                                \
	writeArray = ( NI_TYPE * ) ( L.D );                              \
                                                                     \
	status = NI_NAME( taskHandle,  numSampsPerChan, autoStart,       \
	                  timeout, dataLayout, writeArray,               \
	                  &sampsPerChanWritten, ( bool32* )NULL );       \
                                                                     \
	CreateInt32( 7, sampsPerChanWritten, m, n, l );                  \
	CreateInt32( 8, status, m, n, l );                               \
                                                                     \
	LhsVar( 1 ) = 7;                                                 \
	LhsVar( 2 ) = 8;                                                 \
                                                                     \
	return 0;                                                        \
}

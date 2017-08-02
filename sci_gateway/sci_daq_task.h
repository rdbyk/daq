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

// [status] = NAME( taskHandle )

#define DAQ_TASK_1(NAME,NI_NAME)                                     \
                                                                     \
int sci_##NAME ( char* fname )                                       \
{	                                                                 \
	TaskHandle taskHandle = 0;                                       \
	int32 status = 0;                                                \
	                                                                 \
	int m, n, l;                                                     \
	                                                                 \
	CheckRhs( 1, 1 );                                                \
	CheckLhs( 1, 1 );                                                \
	                                                                 \
	GetRhsTaskHandle( 1, taskHandle, m, n, l );                      \
	                                                                 \
	status = NI_NAME ( taskHandle );                                 \
  	                                                                 \
  	CreateInt32( 2, status, m, n, l );                               \
	                                                                 \
	LhsVar(1) = 2;                                                   \
	                                                                 \
	return 0;                                                        \
}


// [taskHandle, status] = NAME( taskName )

#define DAQ_TASK_2(NAME,NI_NAME)                                     \
                                                                     \
int sci_##NAME( char* fname )                                        \
{                                                                    \
	char *taskName = NULL;                                           \
	TaskHandle taskHandle = 0;                                       \
	int32 status = 0;                                                \
	                                                                 \
	int m, n, l;                                                     \
	                                                                 \
	CheckRhs( 1, 1 );                                                \
	CheckLhs( 1, 2 );                                                \
	                                                                 \
	GetRhsString( 1, taskName, m, n, l );                            \
	                                                                 \
	status = NI_NAME( taskName, &taskHandle );                       \
                                                                     \
    CreateTaskHandle( 2, taskHandle, m, n, l );                      \
  	CreateInt32( 3, status, m, n, l );                               \
	                                                                 \
	LhsVar(1) = 2;                                                   \
	LhsVar(2) = 3;                                                   \
	                                                                 \
	return 0;                                                        \
}

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

#include "stack-c.h"
#include <string.h>

#ifndef USE_DAQMX
#include <NIDAQmxBase.h>
#else
#include <NIDAQmx.h>
#include "use_daqmx.h"
#endif

static char *DAQ_MLIST[] = { "daq", NULL };

#define GetRhsTaskHandle( POS, VAR, M, N, L )          \
GetRhsVar( POS, "m", &( M ), &( N ), &( L ) );         \
CheckLength( POS, m, 2 );                              \
GetListRhsVar( POS, 2, "p" , &( M ), &( N ), &( L ) ); \
VAR = ( TaskHandle ) ((unsigned long int) *stk( L ));

#define CreateTaskHandle( POS, VAR, M, N, L );                  \
M = 2; N = 1;                                                   \
CreateVar( POS, "m", &( M ), &( N ), &( L ) );                  \
M = 1; N = 1;                                                   \
CreateListVarFromPtr( POS, 1, "S", &( M ), &( N ), DAQ_MLIST ); \
M = 1; N = 1;                                                   \
CreateListVarFromPtr( POS, 2, "p", &( M ), &( N ), VAR );


#define GetRhsInt32( POS, VAR, M, N, L )       \
GetRhsVar( POS, "i", &( M ), &( N ), &( L ) ); \
VAR = *istk( L );

#define CreateInt32( POS, VAR, M, N, L )       \
M = 1; N = 1;                                  \
CreateVar( POS, "i", &( M ), &( N ), &( L ) ); \
*istk( L ) = VAR;


#define GetRhsUInt32( POS, VAR, M, N, L )                       \
GetRhsVar( POS, "i", &( M ), &( N ), &( L ) );                  \
if ( *istk( L ) >= 0 )                                          \
	VAR = *istk( L );                                           \
else {                                                          \
	Scierror( 999, "%s: %i is negative!", fname, *istk ( L ) ); \
    return 0;                                                   \
}


#define GetRhsBool32( POS, VAR, M, N, L )       \
GetRhsVar( POS, "b", &( M ), &( N ), &( L ) );  \
VAR = *istk( L );


#define GetRhsFloat64( POS, VAR, M, N, L )     \
GetRhsVar( POS, "d", &( M ), &( N ), &( L ) ); \
VAR = *stk( L );


#define GetRhsString( POS, VAR, M, N, L )      \
GetRhsVar( POS, "c", &( M ), &( N ), &( L ) ); \
VAR = cstk( l );

#define CreateString( POS, VAR, M, N, L )              \
M = strlen( VAR );                                     \
N = 1;                                                 \
L = ( int ) VAR;                                       \
CreateVarFromPtr( POS , "c", &( M ), &( N ), &( L ) );


#define CreateBool32( POS, VAR, M, N, L )      \
M = 1; N = 1;                                  \
CreateVar( POS, "b", &( M ), &( N ), &( L ) ); \
*istk( L ) = VAR;

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
#include "os_specific/sci_mem_alloc.h" // MALLOC & FREE

// DAQmxBaseGetExtendedErrorInfo
// [errorString, status] = DAQ_GetExtendedErrorInfo()
int sci_DAQ_GetExtendedErrorInfo( char* fname )
{
	char *errorString = NULL;
	uInt32 bufferSize = 0;
	int32 status = 0;
	int m, n, l;
	
	CheckRhs( 0, 0 );
	CheckLhs( 1, 2 );
	
	// determine bufferSize 
  	bufferSize = DAQmxBaseGetExtendedErrorInfo( NULL, 0 );
  	
  	errorString = (char *) MALLOC( bufferSize * sizeof( char ) );
  	if ( errorString == NULL) {
  		Scierror( 999, "%s: malloc failed!", fname );
    	return 0;
	}
	
	status = DAQmxBaseGetExtendedErrorInfo( errorString, bufferSize );
	
	CreateString( 1, errorString, m, n, l );
	FREE( errorString );
	
	CreateInt32( 2, status, m, n, l );
	
	LhsVar( 1 ) = 1;
	LhsVar( 2 ) = 2;
	
  return 0;
}

// DAQmxFailed
// [ hasFailed ] = DAQ_Failed( status )
int sci_DAQ_Failed( char* fname )
{	
	int32 status = 0;
	bool32 hasFailed = 0;

	int m, n, l;
	
	CheckRhs( 1, 1 );
	CheckLhs( 1, 1 );
	
	GetRhsInt32( 1, status, m, n, l );
	
	hasFailed = DAQmxFailed( status );
	
	CreateBool32( 2, hasFailed, m, n, l );

	LhsVar(1) = 2;
	
	return 0;
}

// DAQmxSuccess
// [ successStatus ] = DAQ_Success()
int sci_DAQ_Success( char* fname )
{	
	int32 successStatus = 0;

	int m, n, l;
	
	CheckRhs( 0, 0 );
	CheckLhs( 1, 1 );
	
	successStatus = DAQmxSuccess;
	
	CreateInt32( 1, successStatus, m, n, l );

	LhsVar(1) = 1;
	
	return 0;
}

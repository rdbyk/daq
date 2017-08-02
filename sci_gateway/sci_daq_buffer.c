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

// DAQmxBaseCfgInputBuffer
// [status] = DAQ_CfgInputBuffer ( taskHandle, numSampsPerChan )
int sci_DAQ_CfgInputBuffer( char* fname )
{	
	TaskHandle taskHandle = 0;
	uInt32 numSampsPerChan = 0;
	int32 status = 0;

	int m, n, l;
	
	CheckRhs( 2, 2 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	GetRhsUInt32( 2, numSampsPerChan, m, n, l );
	
	status = DAQmxBaseCfgInputBuffer( taskHandle, numSampsPerChan );
	
	CreateInt32( 3, status, m, n, l );

	LhsVar(1) = 3;
	
	return 0;
}

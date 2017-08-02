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

// print
int sci_daq_p( char* fname )
{
	TaskHandle taskHandle = 0;

	int m, n, l;
	
	CheckRhs( 1, 1 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	
	sciprint( "DAQ task handle <0x%X>\n", taskHandle );
	 
	return 0;
}

// not-equal-relation ( taskHandle ~= value )
int sci_daq_n_s( char* fname )
{
	TaskHandle taskHandle = 0;
	int value = 0;

	int m, n, l;
	
	CheckRhs( 2, 2 );
	CheckLhs( 1, 1 );
	
	GetRhsTaskHandle( 1, taskHandle, m, n, l );
	
	GetRhsVar( 2, "i", &m, &n, &l );
	value = *istk( l );
	
	m = 1; n = 1;
	CreateVar( 3, "b", &m, &n, &l );
	*istk( l ) = ( taskHandle != value );

	LhsVar(1) = 3;
	    
	return 0;
}

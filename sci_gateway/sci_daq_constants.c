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

int sci_DAQ( char* fname )
{
  char *name;
  int32 value;

  int m, n, l;

  CheckRhs( 1, 1 );
  CheckLhs( 1, 1 );

  GetRhsString( 1, name, m, n, l );

  if ( strcmp( name, "Val_Auto" ) == 0 )
    value = DAQmx_Val_Auto;
  else if ( strcmp( name, "Val_B_Type_TC") == 0 )
    value = DAQmx_Val_B_Type_TC;
  else if ( strcmp( name, "Val_BuiltIn") == 0 )
    value = DAQmx_Val_BuiltIn;
  else if ( strcmp( name, "Val_Cfg_Default") == 0 )
    value = DAQmx_Val_Cfg_Default;
  else if ( strcmp( name, "Val_Chan") == 0 )
    value = DAQmx_Val_Chan;
  else if ( strcmp( name, "Val_ChanForAllLines") == 0 )
    value = DAQmx_Val_ChanForAllLines;
  else if ( strcmp( name, "Val_ConstVal") == 0 )
    value = DAQmx_Val_ConstVal;
  else if ( strcmp( name, "Val_ContSamps") == 0 )
    value = DAQmx_Val_ContSamps;
  else if ( strcmp( name, "Val_CountDown") == 0 )
    value = DAQmx_Val_CountDown;
  else if ( strcmp( name, "Val_CountUp") == 0 )
    value = DAQmx_Val_CountUp;
  else if ( strcmp( name, "Val_DegC") == 0 )
    value = DAQmx_Val_DegC;
  else if ( strcmp( name, "Val_DegF") == 0 )
    value = DAQmx_Val_DegF;
  else if ( strcmp( name, "Val_DegR") == 0 )
    value = DAQmx_Val_DegR;
  else if ( strcmp( name, "Val_Diff") == 0 )
    value = DAQmx_Val_Diff;
  else if ( strcmp( name, "Val_E_Type_TC") == 0 )
    value = DAQmx_Val_E_Type_TC;
  else if ( strcmp( name, "Val_ExtControlled") == 0 )
    value = DAQmx_Val_ExtControlled;
  else if ( strcmp( name, "Val_Falling") == 0 )
    value = DAQmx_Val_Falling;
  else if ( strcmp( name, "Val_FallingSlope") == 0 )
    value = DAQmx_Val_FallingSlope;
  else if ( strcmp( name, "Val_FiniteSamps") == 0 )
    value = DAQmx_Val_FiniteSamps;
  else if ( strcmp( name, "Val_GroupByChannel") == 0 )
    value = DAQmx_Val_GroupByChannel;
  else if ( strcmp( name, "Val_GroupByScanNumber") == 0 )
    value = DAQmx_Val_GroupByScanNumber;
  else if ( strcmp( name, "Val_High") == 0 )
    value = DAQmx_Val_High;
  else if ( strcmp( name, "Val_Hz") == 0 )
    value = DAQmx_Val_Hz;
  else if ( strcmp( name, "Val_J_Type_TC") == 0 )
    value = DAQmx_Val_J_Type_TC;
  else if ( strcmp( name, "Val_K_Type_TC") == 0 )
    value = DAQmx_Val_K_Type_TC;
  else if ( strcmp( name, "Val_Kelvins") == 0 )
    value = DAQmx_Val_Kelvins;
  else if ( strcmp( name, "Val_Low") == 0 )
    value = DAQmx_Val_Low;
  else if ( strcmp( name, "Val_LowFreq1Ctr") == 0 )
    value = DAQmx_Val_LowFreq1Ctr;
  else if ( strcmp( name, "Val_NRSE") == 0 )
    value = DAQmx_Val_NRSE;
  else if ( strcmp( name, "Val_N_Type_TC") == 0 )
    value = DAQmx_Val_N_Type_TC;
  else if ( strcmp( name, "Val_RSE") == 0 )
    value = DAQmx_Val_RSE;
  else if ( strcmp( name, "Val_R_Type_TC") == 0 )
    value = DAQmx_Val_R_Type_TC;
  else if ( strcmp( name, "Val_Rising") == 0 )
    value = DAQmx_Val_Rising;
  else if ( strcmp( name, "Val_RisingSlope") == 0 )
    value = DAQmx_Val_RisingSlope;
  else if ( strcmp( name, "Val_S_Type_TC") == 0 )
    value = DAQmx_Val_S_Type_TC;
  else if ( strcmp( name, "Val_Seconds") == 0 )
    value = DAQmx_Val_Seconds;
  else if ( strcmp( name, "Val_T_Type_TC") == 0 )
    value = DAQmx_Val_T_Type_TC;
  else if ( strcmp( name, "Val_Ticks") == 0 )
    value = DAQmx_Val_Ticks;
  else if ( strcmp( name, "Val_Volts") == 0 )
    value = DAQmx_Val_Volts;
  else {
    Scierror( 999, "%s: unknown/unimplemented constant", fname );
    return 0;
  }

  CreateInt32( 2, value, m, n, l );

  LhsVar(1) = 2;

  return 0;
}

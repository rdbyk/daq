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
    
function [] = DAQ_ErrChk( taskHandle, status )
  if DAQ_Failed( status ) then
    errorString = DAQ_GetExtendedErrorInfo();
    if taskHandle ~= 0 then
      DAQ_StopTask( taskHandle );
      DAQ_ClearTask( taskHandle );
    end
    mprintf( 'DAQmx Base Error: %d: %s\n', status, errorString );
    error( 10000 );
  end
endfunction


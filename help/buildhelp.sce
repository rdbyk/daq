mode(-1) //force silent execution

help_pathB=get_absolute_file_path('builhelp.sce');//get the absolute path of this file

if %f then
    mprintf( ' %s\n', 'Building help pages in ' + help_pathB );
    xmltohtml(help_pathB,"DAQ Toolbox");
else
    mprintf( ' %s\n', 'Usage of pre-built help pages in ' + help_pathB );
end
  
mprintf( ' %s\n', 'Adding help chapter ""DAQ Toolbox""');
add_help_chapter("DAQ Toolbox",help_pathB);//add help chapter


//clear the variable stack
clear help_pathB


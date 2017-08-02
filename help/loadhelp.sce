mode(-1) //force silent execution

help_pathL=get_absolute_file_path('loadhelp.sce');//get the absolute path of this file

mprintf( ' %s\n', 'Adding help chapter ""DAQ Toolbox""');
add_help_chapter("DAQ Toolbox",help_pathL);//add help chapter

clear help_pathL


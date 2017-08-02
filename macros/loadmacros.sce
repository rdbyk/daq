mode(-1)

macros_pathL=get_absolute_file_path('loadmacros.sce')

mprintf( ' %s\n', 'Loading macros in ' + macros_pathL );
load(macros_pathL+'/lib')

clear macros_pathL


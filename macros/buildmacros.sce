mode(-1)

toolboxname='daq';
macros_pathB=get_absolute_file_path('buildmacros.sce');

mprintf(' %s\n', 'Building macros in ' + macros_pathB );
genlib(toolboxname+'lib',macros_pathB,%t);

clear macros_pathB toolboxname


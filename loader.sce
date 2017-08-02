mode(-1);

savepathL=pwd();

mainpathL=get_absolute_file_path('loader.sce');
chdir(mainpathL);

mprintf('DAQ Toolbox version %s\n', stripblanks(read("VERSION",1,1,'(a)')) );
mprintf('Copyright (C) 2008-2011 Dirk Reusch, Kybernetik Dr. Reusch\n\n' );

if isdir('sci_gateway') then
chdir('sci_gateway');
exec('loader.sce');
chdir('..');
end
if isdir('macros') then
chdir('macros');
exec('loadmacros.sce');
chdir('..');
end
if isdir('help') then
chdir('help');
exec('loadhelp.sce');
chdir('..');
end

chdir(savepathL);

clear mainpathL savepathL


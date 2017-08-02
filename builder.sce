mode(-1);

savepathB=pwd();

mainpathB=get_absolute_file_path('builder.sce');
chdir(mainpathB);

mprintf('DAQ Toolbox version %s\n', stripblanks(read("VERSION",1,1,'(a)')) );
mprintf('Copyright (C) 2008-2011 Dirk Reusch, Kybernetik Dr. Reusch\n\n' );

if isdir('src') then
chdir('src');
exec('buildsrc.sce');
chdir('..');
end
if isdir('sci_gateway') then
chdir('sci_gateway');
exec('buildsci_gateway.sce');
chdir('..');
end
if isdir('macros') then
chdir('macros');
exec('buildmacros.sce');
chdir('..');
end
if isdir('help') then
chdir('help');
exec('buildhelp.sce');
chdir('..');
end

chdir(savepathB);

clear mainpathB savepathB

== Compilation instructions for UnNetHackPlus ==

Windows user need to install an development environment as detailed in 
the NetHack-Cygwin-MinGW HOWTO[1] - cygwin patch is already applied.


On Linux and MacOSX for a single-user installation (a Linux Debian
 or Ubuntu system needs the packages gcc, flex, bison, make and
 libncurses5-dev installed):

 ./configure --prefix=$HOME/unnethackplus --with-owner=`id -un` --with-group=`id -gn` && make && make install

 The game will be started with ~/unnethackplus/bin/unnethackplus


On Windows for a tty build:
 ./configure --with-owner=Username --with-group=Usergroup --build=mingw32 --prefix=/opt/unnethackplus --without-compression --enable-tty-graphics  --disable-file-areas && make && make install

On Windows for a tile build:

 ./configure --with-owner=Username --with-group=Usergroup --build=mingw32 --prefix=/opt/unnethackplus --without-compression --enable-mswin-graphics --disable-tty-graphics  --disable-file-areas && make && make install

It is necessary to manually copy tiles

 1) convert \tilesets\unchozo32b.png to bmp 
 2) copy \tilesets\unchozo32b.bmp to folder with compiled tile version

or

 1) before compiling delete .bmp files from \dat\ folder (otherwise make will skip producing new files)
 2) copy \dat\tiles.bmp to folder with compiled tile version
 3) in defaults.nh change "OPTIONS=tile_file:unchozo32b.bmp,tile_width:32,tile_height:32" to "OPTIONS=tile_file:tiles.bmp,tile_width:16,tile_height:16"

== Regenerating configure file ==

To regenerate configure file from /sys/autoconf/configure.ac run /sys/autoconf/bootstrap.sh

== Contact info ==

Please direct bugs, questions or suggestions to <https://github.com/Bulwersator/UnNetHackPlus/issues> or post them to the
http://www.reddit.com/r/nethack/.


[1] http://www.crawfords.de/nh-cygwin-mingw-howto/

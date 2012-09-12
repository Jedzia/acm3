#################### GLOBALS  #######################################
if DEBUG
AM_CFLAGS = -ggdb -DDEBUG -D_DEBUG -DFDEBUG -Wall
else
AM_CFLAGS = -O3 -Wall
endif

if USE_DLLVERSIONHEADER
VersionSource=win32/version.rc
endif

.rc.lo:
	$(LIBTOOL) --tag=RC --mode=compile $(WINDRES) $< -o $@ 

#################### ACME LIB #######################################
if BUILD_ACMEEXE_SHARED

lib_LTLIBRARIES=libacme.la

libacme_la_SOURCES	= $(VersionSource) acme.c alu.c basics.c cliargs.c cpu.c dynabuf.c encoding.c flow.c global.c input.c label.c macro.c mnemo.c platform.c section.c tree.c output.c 
libacme_la_LDFLAGS	= -no-undefined @lt_enable_auto_import@ -release @release_info@ -version-info @version_info@
libacme_la_CFLAGS	= $(AM_CFLAGS) @pg_use_mingw@ @pg_use_win@ 

endif
#################### ACME MAIN PROGRAM ##############################

bin_PROGRAMS	= acme
acme_LDFLAGS	= $(LIBS) @lt_enable_auto_import@
acme_CFLAGS	= $(AM_CFLAGS) @pg_use_mingw@

if BUILD_ACMEEXE_SHARED
acme_SOURCES	= acme.c
else
acme_SOURCES	= acme.c alu.c basics.c cliargs.c cpu.c dynabuf.c encoding.c flow.c global.c input.c label.c macro.c mnemo.c platform.c section.c tree.c output.c
endif


if USE_DLLVERSIONHEADER
acme_LDADD	= win32/version.lo 

if BUILD_ACMEEXE_SHARED
acme_LDADD	+= libacme.la
endif

else

if BUILD_ACMEEXE_SHARED
acme_LDADD	= libacme.la
endif

endif


#################### DISTRIBUTION FILES #############################
EXTRA_DIST=_amiga.h _std.h alu.h config.h encoding.h input.h mnemo.h section.h _dos.h     _win32.h  basics.h   cpu.h      flow.h      label.h  output.h    tree.h _riscos.h  acme.h    cliargs.h  dynabuf.h  global.h    macro.h  platform.h _dos.c _riscos.c _std.c

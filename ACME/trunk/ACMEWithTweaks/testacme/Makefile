 

# hier den Pfad zu exomizer
exomizer = bin/exomizer.exe
# hier den Pfad zu ACME
#AS = bin/acme.exe
AS = acme.exe

ASFLAGS = -f cbm

all:  endprg.pak exomizer.prg
allx: exomizer.prg goblins zaxxon

VS: clean
	make allx AS=../Debug/ACME.exe

MSYS: clean
	make allx AS=../msysbuild/acme.exe

CYG: clean
	make allx AS=../build/acme.exe


rev:  clean endprg.pak exomizer.prg



exomizer.prg: exomizer.s decrunch.s endprg.pak
	${AS} ${ASFLAGS} -o exomizer.prg exomizer.s

endprg.pak: sprtest.prg.bin
#	exomizer -omenu.pak -r -m1024 -p1 menu.prg
#	exomizer -oendprg.pak -r -m1024 -p1 sprtest.prg.bin
#	exomizer -oendprg.pak sprtest.prg.bin
	${exomizer} -l auto -oendprg.pak sprtest.prg.bin
	echo "PROGSTART = 5360" > start.s

goblins: goblins.pak 
	${AS} ${ASFLAGS} -o goblins.prg exomizer.s 

zaxxon: zaxxon.pak 
	${AS} ${ASFLAGS} -o zaxxon.prg exomizer.s 
	
goblins.pak: goblins.prg.bin
	${exomizer} -l auto -oendprg.pak goblins.prg.bin
	echo "PROGSTART = 0x081b" > start.s

zaxxon.pak: zaxxon.prg.bin
	${exomizer} -l auto -oendprg.pak zaxxon.prg.bin
	echo "PROGSTART = 2064" > start.s

clean:
	$(RM) *.prg
	$(RM) *.bak
	$(RM) *.pak
	$(RM) *.lbl
	$(RM) *~

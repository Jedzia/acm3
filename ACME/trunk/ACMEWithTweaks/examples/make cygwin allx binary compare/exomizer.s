;##############################################################################################
; Exomizer Beispiel von Jedzia 
; Montag, 18. Mai 2009
;##############################################################################################

	!to "exomizer.prg",cbm		; ziel filename und -format
	!cpu 6502			; ziel CPU
	!convtab pet			; umschalten auf CBM-Zeichen Konvertierung
	;!sal
	!sl "Labels.lbl"		; LabelDump, man kann ja nie wissen.
	!svl "global.lbl"		; produce global label dump after assembly
	
	; basic "stub" - ein kleines basic program das es erlaubt das asm programm
	; per "run" zu starten
			
	*=$0801				; Basic-Start
	!word $080b			; Zeiger auf nächste Basiczeile
	!word 2029			; Basic Zeilennummer
	!byte $9e			; Basic-Token für "SYS"
	!text "2064"			; Startadresse des Assemblerprogramms (2064 = $0810)
	!byte 0				; Ende der Basiczeile
	!byte 0,0			; Ende des Basicprogramms

	; und hier der eigentliche assemblercode
			
	*=$0810

	lda #0
	sta $d021			; Bildschirm hintergrund auf schwarz

	
	sei
	inc $01				; Alle Banks auf RAM
	jmp UpackDecrunch
	
	;jsr decrunch 			; BLOS NICHT ;) Diesen Code gibt es hoechstwarscheinlich
					; nicht mehr nach dem entpacken. ( kommt auf die Addresse an).
	;dec $01
	;cli
	;rts

;****************************** GEPACKTE DATEN ********************************************
;*=$2600

!align 255,0
PRGData:
!bin "endprg.pak",,2
PRGDataEnd:
;pdiff = $0801 - $07fd
psize = PRGDataEnd - PRGData	; Groesse der gepackten Daten.

EXO_OPTIMAL_START:		; exomizer optimized offset.
!bin "endprg.pak",2,0		; Dieses Word koennte benutzt werden um zur Laufzeit
				; die optimale Startaddresse der gepackten Daten festzulegen.

progbestaddr = $07fd		; Wir nehmen sie aber lieber hier als festen Wert damit der
				; Assembler die Werte als Konstanten berechnen kann.

;end_of_data = PRGDataEnd 	
end_of_data = progbestaddr + psize ;end variable fuer exomizer decruncher

;*********************************************************************************************



;************************************* PSEUDOCODE ********************************************
shifted_start:
;	!pseudopc $C000 {
	!pseudopc $0410 {	; heute schon im Bildschirmspeicher entpackt?

targetstart:			; Ab hier laeuft nach dem kopieren unsere Depackroutine
				; im Bildschirmspeicher.
	jsr decrunch		; entpacken
	dec $01			; Prozessorregister wieder herstellen, also die ROMs wieder einblenden.
	cli

;PROGSTART = 0x081b		;Startaddresse des gepackten programms (Gn&G)
;PROGSTART = 0x0828		;Startaddresse des gepackten programms (paradroid)
;PROGSTART = 0x0810		;Startaddresse des gepackten programms (sys 2064 Gerald/sauhund)
!source "start.s"		;Startaddresse vom Makefile gesetzt.

	jmp PROGSTART		
	;jmp $0828		
	;jsr $0810		
        inc 53280

        ;jsr $FF81         	; Bildschirm init/löschen ( das währe das ende wenn wir uns im
        			; Bildschirmpuffer befinden! (Hint: $20 $20 $20 $20 $20 ...
        			; soweit das Auge reicht = JSR $2020 steht hier ueberall wenn
        			; $FF81 zurueckkehrt:) )
        			
	;jmp $FF81		; ein jump ist okay.
	rts			;oder zuruck zu basic ...

get_crunched_byte:		; Diese Routine wird vom decruncher aus aufgerufen.
				; Sie muss das jeweils aktuelle byte der gepackten Daten zurueckliefern.
				; Deswegen ist "end_of_data" auf das letzte byte der Packdaten zu setzen.
				; - end_of_data wird bei jedem aufruf dekrementiert. Selbstveraenderlicher
				;   Code.
	lda _byte_lo
	bne _byte_skip_hi
	dec _byte_hi
_byte_skip_hi:
	dec $01
	sta $d020
	eor $0402		; Screen-Effekt, damit man sieht, das sich etwas tut.
	sta $0402
	inc $01

dec _byte_lo:
_byte_lo = * + 1
_byte_hi = * + 2
	lda end_of_data		; needs to be set correctly before
	rts			; decrunch_file is called.
; end_of_data needs to point to the address just after the address
; of the last byte of crunched data.
; -------------------------------------------------------------------


target:	; Hier binden wir den eigentlichen decruncher aus decrunch.s ein.
	; Pseudocode! wie alles zwischen shifted_start und shifted_end.
	; Es muss an seine richtige Adresse kopiert werden und kann danach
	; gestartet werden. 
	;
	; shifted_start und shifted_end befinden sich ausserhalb der !pseudopc
	; Definition und beinhalten die "echten" Addressen, wie sie auch zur Ladezeit
	; im Ram vorliegen. 
	; Die labels targetstart, get_crunched_byte oder target beziehen sich auf die
	; angegebene Pseudoaddresse. Mag auf den ersten Blick etwas verwirrend sein, aber 
	; ist es nicht wunderschoen das der Assembler alles selbst ausrechnet? Sonnst muessten
	; wir uns ja selbst immer mit einem Offset im Hinterkopf herumschlagen. Wie gesagt, eins
	; nicht vergessen: Den Pseudocode vor Aufruf zuerst an die dafuer vorgesehene Addresse 
	; kopieren ;)
	
	;!set decrunch_table_extern = 1		; crunchtable im Kasettenpuffer
	;!set decrunch_table = $033c		; kasettenpuffer
	!source "decrunch.s"
	}
shifted_end:

;*********************************************************************************************




;*=$4200

UpackDecrunch:	

; ***************************** Depacker in den Bildschirmpuffer sichern **************
; Zuerst den depacker sichern. Er wuerde sonnst vom CRUNCHMEMCPY ueberschrieben.
; besteht aber natuerlich die Moeglichkeit den shifted_start/shifted_end hier nach hinten zu holen.
; Wieso einfach wenn es auch kompliziert geht? ... natuerlich dient das nur der verdeutlichung
; das hier einiges im ram herumgeschoben werden muss und wo frau aufpassen muss.

decrunchdelta = shifted_end - shifted_start ; zum checken im labeldump.
;decrunchdelta = PRGDataEnd - PRGData

MEMFROM = $fb
MEMTO	= $fd

;Kopiere den pseudo-depack-code an seine Zieladdresse.
;Da es ein Kurs ist darf es hier viele Einwaende geben.
;Das geht naemlich auch besser:)
;Wichtig: Das hier MUSS addressmaessig hinten liegen,
;weil wir den block der gecrunchten daten nun an die von exomizer
;vorgeschlagene addresse ( option -l auto ) kopieren.

COPYshifted_end = shifted_end + 1

        ldy     #<shifted_start
        sty	smcopy_from_byte_lo
        ldx     #>shifted_start 
        stx     smcopy_from_byte_hi

        ldy     #<targetstart
        sty	smcopy_to_byte_lo
        ldx     #>targetstart 
        stx     smcopy_to_byte_hi
        
        ldy     #<COPYshifted_end
        sty	smcopy_ENDfrom_byte_lo
        ldx     #>COPYshifted_end 
        stx     smcopy_ENDfrom_byte_hi

	jsr	smcopy        


; Kopiere die gepackten Daten an die von exomizer vorgeschlagene Zieladdresse.

; exomizer -l auto schlaegt maximal $07fe vor. Das ist notwendig weil die Startadresse
; unseres gepackten Programms bei $0801 liegt. Der decrunch Algorythmus geht folgendermassen vor:
; von oben nach unten (Speicheraddresse), also rueckwaerts, wird entpackt. Es wuerde dann ein
; gepackter Bereich der grade bei $1000-$10ff liegt nach $3800-$39ff entpackt. Dies waehre dann eine
; hypothetische kompressionsrate von 50% ... mal so nebenbei. Und bitte "rueckwaerts" denken. 
; -> $0f00-$0fff wird in unserem szenario dann nach $3600-$37ff entpackt. Nun wird klar, dass langsam,
; aber zweifelsfrei unaufhaltsam die addresse an die entpackt wird immer naeher an die addresse der 
; packdaten kommt. Exomizer gibt dabei einen offset mit der oben genannten option aus, der sicherstellt
; das sich zu schreibende Daten und zu lesende Archivdaten niemals ueberlappen.

; Das ganze geht natuerlich auch spiegelverkehrt. Dazu muessen dann die gepackten Daten im oberen Bereich
; mit entsprechendem Sicherheitsoffset vorliegen und der decruncher muss 'vorwaerts' entpacken.

; Am schoensten ist es natuerlich wenn man seinen code einfach so schreibt und die einzelnen Stueckchen 
; mundgerecht vom exomizer selbst an die richtigen Adressen schreiben laesst. Das geht natuerlich auch.
; Es soll hier nur gezeigt werden, wie der exomizer das macht. 
; mfg. Jedzia

COPYPRGDataEnd = PRGDataEnd + 1

        ldy     #<PRGData
        sty	smcopy_from_byte_lo
        ldx     #>PRGData 
        stx     smcopy_from_byte_hi

        ldy     #<progbestaddr
        sty	smcopy_to_byte_lo
        ldx     #>progbestaddr 
        stx     smcopy_to_byte_hi
        
        ldy     #<COPYPRGDataEnd
        sty	smcopy_ENDfrom_byte_lo
        ldx     #>COPYPRGDataEnd
        stx     smcopy_ENDfrom_byte_hi
        
	jsr	smcopy        

	jmp targetstart

	;jmp CRUNCHMEMCPY2


;Kopierroutine

smcopy_ENDfrom_byte_lo = * 
smcopy_ENDfrom_byte_hi = * + 1
!word 0x000

smcopy:
	;dec $01
	jmp smcopy_check
smcopy_continue: 	
smcopy_from_byte_lo = * + 1
smcopy_from_byte_hi = * + 2
	lda $0000
smcopy_to_byte_lo = * + 1
smcopy_to_byte_hi = * + 2
	sta $0000
	sta $0403		; Screen-Effekt, damit man sieht, das sich etwas tut.
	inc smcopy_from_byte_lo
	bne smcopy_2
	inc smcopy_from_byte_hi
smcopy_2:
	inc smcopy_to_byte_lo
	bne smcopy_check
	inc smcopy_to_byte_hi

smcopy_check:
	lda smcopy_ENDfrom_byte_hi
	cmp smcopy_from_byte_hi
	bne smcopy_continue
	lda smcopy_ENDfrom_byte_lo
	cmp smcopy_from_byte_lo
	bne smcopy_continue

smcopy_end: 
	;inc $01
	rts


!EOF

; Testroutinen ....  nicht gebraucht


; ***************************** Depacker in den Bildschirmpuffer sichern **************
; Zuerst den depacker sichern. Er wuerde sonnst vom CRUNCHMEMCPY ueberschrieben.
; besteht aber natuerlich die Moeglichkeit den shifted_start/shifted_end hier nach hinten zu holen.
; Wieso einfach wenn es auch kompliziert geht? ... natuerlich dient das nur der verdeutlichung
; das hier einiges im ram herumgeschoben werden muss und wo frau aufpassen muss.
        ldy     #<targetstart
        sty	MEMTO
        ldx     #(>targetstart) - 1
        stx     MEMTO+1
	        
        ldy     #<shifted_start
        sty	MEMFROM
        ldx     #(>shifted_start) - 1
        stx     MEMFROM+1

	ldx #0
	ldy #0
        
kcpylp1:       
        inc     MEMFROM+1
        inc     MEMTO+1
kcpylp:
        lda     (MEMFROM),y
        sta     (MEMTO),y
        iny
        bne     kcpylp
        inx
        cpx 	#(>shifted_end) + 1 - (>shifted_start)
        bne     kcpylp1

;		ldx # decrunchdelta
;-		lda shifted_start-1,x
;			sta target-1,x
;			dex
;			bne -
;rts

;	jmp targetstart		; jmp without a copy ... disabled

; ***************************** *********************************************** **************




CRUNCHMEMCPY2
; ***************************** Gecrunchtes an vorgeschlagene addresse kopieren **************
; Move memory down
;
; FROM = source start address
;   TO = destination start address
; SIZE = number of bytes to move
;
progcopysize = PRGDataEnd - PRGData

SIZEH = >progcopysize
SIZEL = <progcopysize

;        ldy     PRGData
        ldy     #<progbestaddr
        sty	MEMTO
;        ldx     PRGData + 1
        ldx     #>progbestaddr
        stx     MEMTO+1

        ldy     #<PRGData
        sty	MEMFROM
        ldx     #>PRGData
        stx     MEMFROM+1

	

MOVEDOWN LDY #0
         LDX SIZEH
         BEQ MD2
MD1      LDA (MEMFROM),Y ; move a page at a time
         STA (MEMTO),Y
	 sta $0400
         INY
         BNE MD1
         INC MEMFROM+1
         INC MEMTO+1
         DEX
         BNE MD1
MD2      LDX SIZEL
         BEQ MD4
MD3      LDA (MEMFROM),Y ; move the remaining bytes
         STA (MEMTO),Y
         INY
         DEX
         BNE MD3
MD4      NOP 
	jmp targetstart


; ***************************** *********************************************** **************





print_byte
	pha
	lsr
	lsr
	lsr
	lsr
	tax
	lda hextab,x
	jsr $ffd2
	pla
	and #$0f
	tax
	lda hextab,x
	jsr $ffd2
	rts
hextab
	!tx "0123456789ABCDEF"













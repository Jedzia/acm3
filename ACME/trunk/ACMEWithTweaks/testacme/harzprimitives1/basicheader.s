!to "basicfoo.prg",cbm
*=$0801                           ; Basic-Start
!byte <finalezeile, >finalezeile  ; Zeiger auf naechste Basiczeile
!word 2029                        ; Basic Zeilennummer
!byte $9e                         ; Basic-Token f<FC>r "SYS"
!text "2064"                      ; Startadresse des Assemblerprogramms (2064 = $0810)
!byte 0                           ; Ende der Basiczeile
letztezeile: !byte 0,0            ; Ende des Basicprogramms
jmp code
code:   lda #$01
        sta $d021
done:
	sei
	eor $dc01
        sta $d021
moo:    asl $dc00
	inc $d020
        bne moo
        jmp done
finalezeile: 
!byte <letztezeile, >letztezeile  ; Zeiger auf naechste Basiczeile
!word 2030
!byte $9e
!text "2074"
!byte 0
;        lda #$07
;        and xcoord
;        tax
;        lda powers, x
;        sta $fe


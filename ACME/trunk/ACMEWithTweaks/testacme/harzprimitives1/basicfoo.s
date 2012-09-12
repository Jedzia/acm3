;EXAMPLE
;	Dieses Beispiel erklaert wie es der BASIC interpreter sowieso macht
;	und wie wir es mit ACME nachbilden koennen.
;Author: Harzilein
;Profi
;Links: C64-Intern S. 162, http://www.sys64738.eu/basic.html, 
;       http://www.c64-wiki.com/index.php/BASIC_token

!to "basicfoo.prg",cbm
!svl "basicfoo.txt"
*=$0801                           ; Basic-Start
!byte <finalezeile, >finalezeile  ; Zeiger auf naechste Basiczeile
!word 2029                        ; Basic Zeilennummer
!byte $97                         ; Basic-Token f<FC>r "POKE"
!text "2086,3 "                      ; Startadresse des Assemblerprogramms (2064 = $0810)
!byte 0                           ; Ende der Basiczeile
naechstezeile: !byte <letztezeile, >letztezeile  ; Zeiger auf naechste Basiczeile
!word 2030                        ; Basic Zeilennummer
!byte $97                         ; Basic-Token f<FC>r "POKE"
!text "2087,5"                      ; Startadresse des Assemblerprogramms (2064 = $0810)
!byte 0                           ; Ende der Basiczeile
finalezeile: !byte <naechstezeile, >naechstezeile  ; Zeiger auf naechste Basiczeile
!word 2031
!byte $9e
!text "2088"
!byte 0
letztezeile: !byte 0,0            ; Ende des Basicprogramms
coords: !byte 0,0
code:   lda coords
        sta $d021
done:
        rts

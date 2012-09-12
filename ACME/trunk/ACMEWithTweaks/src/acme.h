//
// ACME - a crossassembler for producing 6502/65c02/65816 code.
// Copyright (C) 1998-2006 Marco Baye
// Have a look at "acme.c" for further info
//
// Main definitions
#ifndef acme_H
#define acme_H

#include "config.h"

// Exports
#ifdef _WIN32
#  ifdef DLL_EXPORT
#    define ACME_SCOPE         __declspec(dllexport)
#  else
#    ifdef LIBACME_DLL_IMPORT
#      define ACME_SCOPE       extern __declspec(dllimport)
#    endif
#  endif
#endif
#ifndef ACME_SCOPE
#  define ACME_SCOPE           extern
#endif

//ACME_SCOPE const char *XYZ;
//__declspec(dllexport) const char *XYZ;

// Variables
extern const char*	labeldump_filename;
extern const char*	vicelabeldump_filename;
extern const char*	output_filename;
extern int	labeldump_allSections;
// maximum recursion depth for macro calls and "!source"
extern signed long	macro_recursions_left;
extern signed long	source_recursions_left;
extern zone_t		zone_max;

//__declspec( dllexport ) int i;

// Prototypes

// Tidy up before exiting by saving label dump
extern int	ACME_finalize(int exit_code);


#endif

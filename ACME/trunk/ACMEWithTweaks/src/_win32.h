//
// ACME - a crossassembler for producing 6502/65c02/65816 code.
// Copyright (C) 1998-2006 Marco Baye
// Have a look at "acme.c" for further info
//
// Platform specific stuff (in this case, for DOS, OS/2 and Windows)
#ifndef _win32_H
#define _win32_H

#define inline

// Removes a lot of warnings from the compile.
// MPi: TODO: Really fix these warnings in the source instead of silently turning them off.
#pragma warning (disable : 4305 4244 4761 4018)

// The rest of _std.h is compatible with Win32
#include "_std.h"

#if _MSC_VER >= 1400

	//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
	#define _CRT_SECURE_NO_WARNINGS 1

	//#define USE_FOPEN_S
    #define ferr(a,b) ((int)a) && !b
	#define fnerr(a,b) (a == NULL) || (b != NULL)
#endif //#if _MSC_VER >= 1400

#endif

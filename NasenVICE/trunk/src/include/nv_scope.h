/*
 * nv_scope.h
 *
 *  Created on: 26.07.2009
 *      Author: root
 */

#ifndef NV_SCOPE_H_
#define NV_SCOPE_H_

#ifdef _WIN32
#  ifdef DLL_EXPORT
#    define CLASS_SCOPE         __declspec(dllexport)
#  else
//#    ifdef LIBHELLO_DLL_IMPORT
#      define CLASS_SCOPE       __declspec(dllimport)
//#    endif
#  endif
#endif

#ifndef CLASS_SCOPE
//#  define HELLO_SCOPE           extern
#  define CLASS_SCOPE
#endif



#endif /* NV_SCOPE_H_ */

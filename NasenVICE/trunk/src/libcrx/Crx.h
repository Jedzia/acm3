/*
 * Crx.h
 *
 *  Created on: 26.07.2009
 *      Author: root
 */

#ifndef CRX_H_
#define CRX_H_

#if HAVE_CONFIG_H
#	include <nv_config.h>
#endif

#include <iostream>
using namespace std;


class CLASS_SCOPE Crx {
public:
	Crx();
	virtual ~Crx();

	int xhello (const char *who);

};

//extern "C" __declspec( dllexport ) int xhello (const char *who);

#endif /* CRX_H_ */

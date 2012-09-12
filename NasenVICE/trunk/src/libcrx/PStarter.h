/*
 * PStarter.h
 *
 *  Created on: 27.07.2009
 *      Author: Jedzia
 */

#ifndef PSTARTER_H_
#define PSTARTER_H_

#if HAVE_CONFIG_H
#	include <nv_config.h>
#endif

#include <iostream>
using namespace std;


namespace crx {

class PStarter {
public:
	PStarter(string &pname, string &parameter);
	virtual ~PStarter();

private:
	string m_pname;
	string m_parameter;

};

}

#endif /* PSTARTER_H_ */

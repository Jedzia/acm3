/*
 * TestClass.h
 *
 *  Created on: 26.07.2009
 *      Author: root
 */
#if HAVE_CONFIG_H
#	include <nv_config.h>
#endif

#include <string>

using namespace std;

#ifndef TESTCLASS_H_
#define TESTCLASS_H_

class TestClass {
public:
	TestClass();
	virtual ~TestClass();

	string moep();
};

#endif /* TESTCLASS_H_ */

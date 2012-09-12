#if HAVE_CONFIG_H
#	include <nv_config.h>
#endif

//extern int xhello (const char *who);

#include <iostream>
#include "TestClass.h"
#include "Crx.h"

#include <cstdlib>

using namespace std;

int main()
{

	TestClass *tc = new TestClass();
	cout << "Hello World!" << tc->moep() << endl;
	cout << "Hello World!" << endl;

	Crx testding;
	testding.xhello("*Trallaaah*");

	char *env = getenv("APPDATA");
	cout << "Env: "<< env << endl;
	//xhello("Mich latuernich");

	system("vice.bat");
}

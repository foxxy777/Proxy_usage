#include <iostream>
#include "subject.h"

int main()
{
	Subject* subject;
	subject = new Proxy();
	subject->method();

	printf("\n\n");

	system("pause");
	return 0;
}
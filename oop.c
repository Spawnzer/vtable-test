#include "oop.h"
#include <stdio.h>
#include <stdlib.h>

int addi(int a, int b)
{
	return a+b;
}

int subs(int a, int b)
{
	return a-b;
}

int mult(int a, int b)
{
	return a*b;
}

int divi(int a, int b)
{
	return a/b;
}

void freeVtable(OPERATION_VTABLE *self)
{
	free(self);
}

OPERATION_VTABLE *init_vtable()
{
	OPERATION_VTABLE *vtable = malloc(sizeof(OPERATION_VTABLE));

	vtable->add = addi;
	vtable->div = divi;
	vtable->sub = subs;
	vtable->mul = mult;
	vtable->free = freeVtable;
	return vtable;
}

fcn *get_fcn(void)
{
	static fcn test;

	if (test.init != 1)
	{
		test.vtable = init_vtable();
		test.init = 1;
		test.res = 0;
	}
	return (&test);
}

int main(void)
{
	printf("res is %d \n", get_fcn()->vtable->add(20, 5));
	printf("res is %d \n", get_fcn()->vtable->sub(20, 5));
	printf("res is %d \n", get_fcn()->vtable->mul(20, 5));
	printf("res is %d \n", get_fcn()->vtable->div(20, 5));
	get_fcn()->vtable->free(get_fcn()->vtable);
}

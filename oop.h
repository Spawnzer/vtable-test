typedef struct OPERATION_VTABLE {
	int (*add)(int a, int b);
	int (*sub)(int a, int b);
	int (*mul)(int a, int b);
	int (*div)(int a, int b);
} OPERATION_VTABLE;

typedef struct fnc
{
	int res;
	int init;
	OPERATION_VTABLE *vtable;
} fcn;

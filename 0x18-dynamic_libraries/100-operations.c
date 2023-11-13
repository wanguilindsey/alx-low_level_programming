#include "100-operations.h"

int add(int a, int b)
{
	return (a + b);
}

int sub(int a, int b)
{
	return (a - b);
}

int mul(int a, int b)
{
	return (a * b);
}

int div(int a, int b)
{
	if (b != 0)
	{
		return (a / b);
	} else
	{
		return (0); // handle division by zero as needed
	}
}

int mod(int a, int b)
{
	if (b != 0)
	{
		return (a % b);
	} else
	{
		return (0); // handle modulo by zero as needed
	}
}

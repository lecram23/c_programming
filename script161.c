#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON

int main(void)
{
	double d1=0, d2=1.0, dges;
	fexcept_t flagp;
	// Exception-Stausflags sichern
	fegetexceptflag(&flagp, FE_ALL_EXCEPT);
	// On purpose
	dges = d2/d1;
	if(fetestexcept(FE_DIVBYZERO)){
		printf("Exception ausgelöst: Division durch 0!\n")
	}		

	fsetexceptflat(&flagp, FE_ALL_EXCEPT);
	if(fetestexcept(FE_DIVBYZERO))
		printf("Exception ausgelöst: Division durch 0!\n");

	return EXIT_SUCCESS;
}

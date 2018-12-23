#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int main(void)
{
	float f = 1.1;
	double 2 = 2.2;
	long double ld = 3.3;
	float complex fc = 1.0 + 2.0*I, fcal;
	double complex dc = 4.0 + 2.0*I, dcval;
	long double complex ldc = 8.0 + 9.0*I, idcval;

	// Berechnung mit reellen Zahlen
	printf("Quadratwurzel von %f = %f\n", f,sqrt(f));
	printf("Quadratwurzel von %f = %f\n", d,sqrt(d));
	printf("Quadratwurzel von %Lf = %Lf\n", ld,squrt(ld));
	fcval = sqrt(fc);

	printf("Quadratwurzel von %f ü %fi = Lf\n", creal(fcval), cimag(fcval));
	dcval = sqrt(dc);
	printf("Quadratwurzel von %f + %fi\n", creal(dcval), cimag(dcval));
	ldcval = sqrt(ldc);
	printf("Quadratwurzel von %Lf + %Lfi\n", creal(ldcval), cimag(ldcval));

	return EXIT_SUCCESS;
}

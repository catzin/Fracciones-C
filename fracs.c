#include"fracs.h"

fraccion 
lee_fraccion(void)
{

	fraccion	a;

	scanf("%d", &a.e);
	scanf("%d", &a.n);
	scanf("%d", &a.d);
	return a;
}

void 
imp_fraccion(fraccion a)
{

	printf("%d[%d/%d]\n", a.e, a.n, a.d);

}

fraccion 
a_impropia(fraccion a)
{

	fraccion	b;
	b.e = 0;
	b.n = (a.e * a.d) + a.n;
	b.d = a.d;
	return b;
}
void 
acomoda(int *a, int *b)
{

	int		aux = 0;
	aux = *a;
	*a = *b;
	*b = aux;
}

int 
mcd(int a, int b)
{
	int		r = 0;

	while (b != 0) {

		r = a % b;
		a = b;
		b = r;

	}
	return a;
}
int 
mcd_fraccion(fraccion a, fraccion b)
{

	int		x = 0;
	int		y = 0;
	int		r = 0;
	x = a.d;
	y = b.d;

	if (x < y) {
		acomoda(&x, &y);
	}
	r = mcd(x, y);
	return r;
}

int 
mcm_fraccion(fraccion a, fraccion b, int r)
{

	int		mcm = 0;
	mcm = (a.d * b.d) / r;

	return mcm;
}

fraccion 
suma_fraccion(fraccion a, fraccion b)
{

	fraccion	r;
	int		aux = 0;
	r.e = 0;
	aux = mcd(a.d, b.d);
	r.d = mcm_fraccion(a, b, aux);
	r.n = ((r.d / a.d) * a.n) + ((r.d / b.d) * b.n);

	return r;
}

fraccion 
multiplica_fraccion(fraccion a, fraccion b)
{
	fraccion	r;
	r.e = 0;
	r.n = (a.n * b.n);
	r.d = (a.d * b.d);
	return r;

}

fraccion 
divide_fraccion(fraccion a, fraccion b)
{
	fraccion	r;
	r.e = 0;
	r.n = (b.d * a.n);
	r.d = (a.d * b.n);

	return r;

}

fraccion 
resta_fraccion(fraccion a, fraccion b)
{

	fraccion	r;
	int		aux = 0;
	r.e = 0;
	aux = mcd(a.d, b.d);
	r.d = mcm_fraccion(a, b, aux);
	r.n = ((r.d / a.d) * a.n) - ((r.d / b.d) * b.n);

	return r;
}

fraccion 
transforma(fraccion a)
{
	fraccion	aux;

	if (a.e != 0) {
		aux = a_impropia(a);

		return aux;
	} else {

		return a;
	}
}


void 
menu(void)
{
	printf("¿Que quieres hacer?, elige una opcion.\n");
	printf("\n");
	printf("1.Sumar\n");
	printf("2.Restar\n");
	printf("3.Multiplicar\n");
	printf("4.Dividir\n");
	printf("5.Mixta a impropia\n");
}

int 
lee_opcion(void)
{
	int		op = 0;
	scanf("%d", &op);
	return op;
}
void 
ejecuta_opcion(int opcion)
{

	fraccion	a     , b, r;

	switch (opcion) {

	case 1:
		printf("Ingresa primera fraccion:\n");

		do {
			a = lee_fraccion();
			a = transforma(a);
		} while (a.d == 0);

		printf("\n");
		printf("Ingresa segunda fraccion:\n");


		do {
			b = lee_fraccion();
			b = transforma(b);
		} while (b.d == 0);
		printf("\n");
		r = suma_fraccion(a, b);
		printf("El resultado es:\n");
		printf("\n");
		imp_fraccion(r);
		break;

	case 2:
		printf("Ingresa primera fraccion:\n");
		do {
			a = lee_fraccion();
			a = transforma(a);
		} while (a.d == 0);

		printf("\n");
		printf("Ingresa segunda fraccion:\n");

		do {
			b = lee_fraccion();
			b = transforma(b);
		} while (b.d == 0);
		r = resta_fraccion(a, b);
		printf("El resultado es:\n");
		imp_fraccion(r);
		break;

	case 3:
		printf("Ingresa primera fraccion:\n");

		do {
			a = lee_fraccion();
			a = transforma(a);
		} while (a.d == 0);

		printf("\n");
		printf("Ingresa segunda fraccion:\n");

		do {
			b = lee_fraccion();
			b = transforma(b);
		} while (b.d == 0);

		r = multiplica_fraccion(a, b);
		printf("El resultado es:\n");
		imp_fraccion(r);
		break;

	case 4:
		printf("Ingresa primera fraccion:\n");

		do {
			a = lee_fraccion();
			a = transforma(a);
		} while (a.d == 0);

		printf("\n");
		printf("Ingresa segunda fraccion:\n");

		do {
			b = lee_fraccion();
			b = transforma(b);
		} while (b.d == 0);

		r = divide_fraccion(a, b);
		printf("El resultado es:\n");
		imp_fraccion(r);
		break;

	case 5:
		printf("Ingresa fraccion mixta:\n");

		do {
			a = lee_fraccion();
			a = transforma(a);
		} while (a.d == 0);
		printf("Fraccion impropia:\n");
		imp_fraccion(a);

	}
}

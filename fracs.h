
#include<stdio.h>

typedef struct {
	int		e;
	int		n;
	int		d;
}		fraccion;

fraccion	lee_fraccion(void);
void		imp_fraccion(fraccion);
fraccion	a_impropia(fraccion);
void		acomoda   (int *, int *);
fraccion	suma_fraccion(fraccion, fraccion);
fraccion	resta_fraccion(fraccion, fraccion);
fraccion	divide_fraccion(fraccion, fraccion);
fraccion	multiplica_fraccion(fraccion, fraccion);
int		mcd        (int, int);
int		mcd_fraccion(fraccion, fraccion);
int		mcm_fraccion(fraccion, fraccion, int);
fraccion	transforma(fraccion);
void		menu      (void);
int		lee_opcion (void);
void		ejecuta_opcion(int);

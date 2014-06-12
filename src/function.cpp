#include"function.h"

double SphereFunction::run(int dim, double *tab) {
	double sum=0;
	for (int i=0; i<dim; ++i){
		sum+=tab[i]*tab[i];
	}
	return sum;
}

double RosenbrockFunction::run(int dim, double *tab) {
	double sum=0;
	for (int i=0; i<dim-1; ++i){
		sum+=100*(tab[i+1]-tab[i]*tab[i])*(tab[i+1]-tab[i]*tab[i])+(tab[i]-1)*(tab[i]-1);
	}
	return sum;
}

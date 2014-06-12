/*
 * function.h
 */

#ifndef FUNCTION
#define FUNCTION

class Function {
public:
	virtual double run(int dim, double *tab){return 0;};
};

class SphereFunction : public Function {
public:
	virtual double run(int dim, double *tab);
};

class RosenbrockFunction : public Function {
public:
	virtual double run(int dim, double *tab);
};

#endif

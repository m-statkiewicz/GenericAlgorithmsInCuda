/*
 * strategy.h
 */

#include"function.h"
#ifndef STRATEGY
#define STRATEGY

class Strategy {
public:
	virtual double run(int dim, int iterations, Function *f){return 0;};
	virtual void setLambda(int l) {};
	virtual void setMi(int m) {};
};

class OnePlusOneStrategy : public Strategy {
public:
	virtual double run(int dim, int iterations, Function *f);
};

class OnePlusLambdaStrategy : public Strategy {
private:
	int lambda;
public:
	virtual void setLambda(int l);
	virtual double run(int dim, int iterations, Function *f);
};

class MiPlusLambdaStrategy : public Strategy {
private:
	int mi;
	int lambda;
public:
	virtual double run(int dim, int iterations, Function *f);
};

class MiLambdaStrategy : public Strategy {
private:
	int mi;
	int lambda;
public:
	virtual double run(int dim, int iterations, Function *f);
};


double* generateVector(int dim, double variance);
double* add(int dim, double* v1, double* v2);
double* mutate(int dim, double* v, double variance);


#endif

#include<iostream>
#include"function.h"
#include"strategy.h"
#include<stdlib.h>
#include<time.h>
#define DIM 8

int main (){

Function* rf = new RosenbrockFunction();
Function* sf = new SphereFunction();
Strategy* oos = new OnePlusOneStrategy();
Strategy* ols = new OnePlusLambdaStrategy();
ols->setLambda(5);
srand(time(NULL));
ols->run(DIM,100,sf);

delete rf,sf,oos,ols;
return 0;
}

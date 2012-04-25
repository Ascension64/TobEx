#ifndef SCRIPTCOMMON_H
#define SCRIPTCOMMON_H

#include "scrcore.h"

class EvalOp {
public:
	EvalOp();
	EvalOp(int v, unsigned int o);
	EvalOp(const EvalOp& e);
	static int Operate(int n, EvalOp& op);
protected:
	int nValue;
	unsigned int nOp;
};

#endif //SCRIPTCOMMON_H
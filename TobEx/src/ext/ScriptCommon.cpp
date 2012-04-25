#include "ScriptCommon.h"

EvalOp::EvalOp() : nValue(0), nOp(0) {};
EvalOp::EvalOp(int v, unsigned int o) : nValue(v), nOp(o) {};
EvalOp::EvalOp(const EvalOp& e) : nValue(e.nValue), nOp(e.nOp) {};

int EvalOp::Operate(int n, EvalOp& op) {
	switch (op.nOp) {
	case EVALUATE_MODE_SET:
		return op.nValue;
	case EVALUATE_MODE_ADD:
		return n + op.nValue;
	case EVALUATE_MODE_MUL:
		return n * op.nValue;
	case EVALUATE_MODE_DIV:
		return (op.nValue > 0) ? n * op.nValue : INT_MAX;
	case EVALUATE_MODE_MOD:
		return (op.nValue > 0) ? n % op.nValue : INT_MAX;
	case EVALUATE_MODE_PC:
		return n * op.nValue / 100;
	default:
		return n;
	}
}
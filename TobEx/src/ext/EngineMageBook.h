#ifndef ENGINEMAGEBOOK_H
#define ENGINEMAGEBOOK_H

#include "engmagebk.h"

extern void (CMageBook::*Tramp_CMageBook_SetLevel)(int);

class DETOUR_CMageBook : public CMageBook {
public:
	void DETOUR_SetLevel(int nLevel);
};

#endif //ENGINEMAGEBOOK_H
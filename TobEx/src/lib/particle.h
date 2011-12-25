#ifndef PARTICLE_H
#define PARTICLE_H

//0
//1
//2
#define PARTICLETYPE_BLOOD_LARGE	3
#define PARTICLETYPE_BLOOD_MEDIUM	4
#define PARTICLETYPE_BLOOD_SMALL	5
#define PARTICLETYPE_BLOOD_CR		6
//7

#define GORETYPE_BLOOD	0
#define GORETYPE_FIRE	1
#define GORETYPE_SHOCK	2
#define GORETYPE_COLD	3

typedef IECPtrList CParticleList; //AA9D10

struct CParticle { //Size 7Ah
//Constructor: 0x5F2A40
	CArea* pArea; //0h
	IECPtrList u4; //AABA88
	IECPtrList u20; //AABA88
	int u3c;
	int u40;
	POINT pt; //44h
	int m_HalfHeight; //4ch
	short u50;
	int u52;
	int u56;
	int u5a;
	int u5e;
	int u62;
	int u66;
	int u6a;
	short orientation; //6eh
	short u70;
	short m_wType; //72h, particle type?
	int m_nHeight; //74h
	char u78;
	char u79; //pad
};

#endif //PARTICLE_H
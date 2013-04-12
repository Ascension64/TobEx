#ifndef FILEVVC_H
#define FILEVVC_H

#include "stdafx.h"
#include "resref.h"

#define CVEFVIDCELL_BLT_BRIGHTEST 0x00000008
#define CVEFVIDCELL_BLT_MIRROR_LR 0x00000010
#define CVEFVIDCELL_BLT_MIRROR_UD 0x00000020
#define CVEFVIDCELL_BLT_GLOW      0x00000200

#define CVEFVIDCELL_LOOP				0x00000001
#define CVEFVIDCELL_GLOW				0x00000002
#define CVEFVIDCELL_HEIGHT				0x00000004
#define CVEFVIDCELL_RENDER				0x00000008
#define CVEFVIDCELL_NEWPALETTE			0x00000010
#define CVEFVIDCELL_DELETED				0x00000020 //Used by linked effects
#define CVEFVIDCELL_DONOTCLIP			0x00000040
#define CVEFVIDCELL_BRIGHTEN3DONLYOFF	0x00000080
#define CVEFVIDCELL_BRIGHTENIFFAST		0x00000100

#define CVEFVIDCELL_OFFSET_ROTATE	0x00000001

//#define VVCORIENTATION_PREVIOUS			0x00000000
#define CVEFVIDCELL_FACE_TARGET				0x00000001 //VVCORIENTATION_ORIGIN 
#define CVEFVIDCELL_FACE_TARGET_DIRECTION	0x00000002 //VVCORIENTATION_PARENT
#define CVEFVIDCELL_FACE_TRAVEL_DIRECTION	0x00000004
#define CVEFVIDCELL_FACE_DO_NOT_CHANGE		0x00000008 //VVCORIENTATION_IGNORE

#define CVEFVIDCELL_SEQUENCE_PLAY_ALL	0x00000001  //Change sequence until run out.

//Vef
struct VefFileComponent { //Size E0h
	int m_nStartDelay; //0h, CVisualEffect frame to start
	//the specific AiUpdate to reload the animation
	//i.e. compares to CVisualEffect.u272, when u272 == this, then is reloaded

	int u4; //unused
	int m_nRestartTime; //8h, how many ticks to reload
	//if 0, purge this VefComponent; otherwise, u0+=u8

	int m_nType; //ch, 1 = load Vvc/Bam, 2 = CreateVisualEffect() from resref (Vef/Vvc/Bam), else = play sound in resref
	ResRef m_res; //10h, vvc/bam/wav
	unsigned int m_dwFlags; //18h, bit0: multicycle, sets uae of CVefVidCell
	int u1c[49]; //unmarshalled but unused?
};

struct VvcFileBase { //Size 1E4h
	ResRef	m_cVidCellRef; //0h, anim1
	ResRef	m_cShadowVidCellRef; //8h, anim2
	DWORD	m_bltFlags; //10h, displayFlags
	DWORD	m_bltInfo; //14h, tranparency amount etc.
	DWORD	m_bltFlagsExtra; //18h, seqFlags, including whether to loop at end or not
	DWORD	m_bltInfoExtra; //1ch
	CPoint	m_offset; //20h, from parent
	DWORD	m_offsetFlags;  //28h, bUseOrientation, maybe we could rotate offset based on direction
	LONG	m_animationSpeed; //2ch, nFrameRate, max 30
	LONG	m_numDirections; //30h, nOrientations
	LONG	m_direction; //34h, nBaseOrientation
	DWORD	m_directionFlags; //38h, posFlags
	ResRef	m_cNewPaletteRef; //3ch, nameBitmapPalette
	LONG	m_height; //44h, zPos, height
	CPoint	m_glowSize; //48h, ptCentre
	DWORD	m_glowIntensity; //50h, glowBrightness
	LONG	m_nDuration; //54h, -1 for infinite
	ResRef	m_cVVCResRes; //58h, name, that's me
	LONG	m_nStartSequence; //50h, animCycleBegin, 1 indexed
	LONG	m_nLoopSequence; //64h, animCycleMiddle, 1 indexed, 0 or less for none
	LONG	m_nCurrentSequence; //68h, currCycle, 1 indexed
	DWORD	m_sequenceFlags; //6ch, bMultiCycle
	ResRef	m_cStartSoundRef; //70h, soundBegin
	ResRef	m_cLoopSoundRef; //78h, soundMiddle
	ResRef	m_cAlphaBamRef; //80h, anim3
	LONG	m_nEndSequence; //88h, cycleAnimEnd
	ResRef	m_cEndSoundRef; //8ch, soundEnd

	DWORD	m_extra[84]; //94h
};

#endif //FILEVVC_H
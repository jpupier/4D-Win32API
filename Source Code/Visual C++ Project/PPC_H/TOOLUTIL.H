/*
	File:		ToolUtils.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __TOOLUTILS__
#define __TOOLUTILS__

#ifdef	_MSC_VER
#pragma warning( disable : 4237 )	// nonstandard extension used : 'false' keyword is reserved for future use
#endif

#ifndef __TYPES__
#include <MacTypes.H>
#endif

#ifndef __QUICKDRAW__
#if LONG_FILENAMES
#include <Quickdraw.H>
#else
#include <Quickdra.H>
#endif
#endif

#ifndef __TEXTUTILS__
#if LONG_FILENAMES
#include <TextUtils.H>
#else
#include <TextUtil.H>
#endif
#endif

#ifndef __FIXMATH__
#include <FixMath.H>
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
	#pragma pack(2)
#endif

enum  {
	sysPatListID			= 0,
	iBeamCursor			= 1,
	crossCursor			= 2,
	plusCursor			= 3,
	watchCursor			= 4
};

struct Int64Bit {
	long			hiLong;
	unsigned long			loLong;
};
typedef struct Int64Bit Int64Bit;

#ifdef __cplusplus
extern "C" {
#endif

extern Fixed pascal FixRatio(short numer, short denom);
extern Fixed pascal FixMul(Fixed a, Fixed b);
extern short pascal FixRound(Fixed x);
extern void pascal PackBits(Ptr *srcPtr, Ptr *dstPtr, short srcBytes);
extern void pascal UnpackBits(Ptr *srcPtr, Ptr *dstPtr, short dstBytes);
extern Boolean pascal BitTst(const void *bytePtr, long bitNum);
extern void pascal BitSet(void *bytePtr, long bitNum);
extern void pascal BitClr(void *bytePtr, long bitNum);
extern long pascal BitAnd(long value1, long value2);
extern long pascal BitOr(long value1, long value2);
extern long pascal BitXor(long value1, long value2);
extern long pascal BitNot(long value);
extern long pascal BitShift(long value, short count);
#if !defined(powerc) && !defined(__powerc)
extern void pascal LongMul(long a, long b, Int64Bit *result);
#else
#define LongMul(a, b, result) ((void) WideMultiply((a), (b), (wide*)(result)))

#endif

extern Handle pascal GetIcon(short iconID);
extern void pascal PlotIcon(const Rect *theRect, Handle theIcon);
extern PatHandle pascal GetPattern(short patternID);
extern CursHandle pascal GetCurso(short cursorID);
extern PicHandle pascal GetPicture(short pictureID);
extern Fixed pascal SlopeFromAngle(short angle);
extern short pascal AngleFromSlope(Fixed slope);
extern long pascal DeltaPoint(Point ptA, Point ptB);
extern void pascal ShieldCursor(const Rect *shieldRect, Point offsetPt);
extern void pascal ScreenRes(short *scrnHRes, short *scrnVRes);
extern void pascal GetIndPattern(Pattern *thePat, short patternListID, short index);
extern void shieldcursor(const Rect *shieldRect, Point *offsetPt);
extern long deltapoint(Point *ptA, Point *ptB);

/* Obsolete Math Routines */

#if FALSE
extern short pascal HiWord(long x);
#endif

#define HiWord(x) ((short)((long)(x) >> 16))

#if FALSE
extern short pascal LoWord(long x);
#endif

#define LoWord(x) ((short)(x))

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
	#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif



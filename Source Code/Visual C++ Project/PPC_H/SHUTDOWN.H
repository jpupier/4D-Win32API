/*
	File:		ShutDown.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __SHUTDOWN__
#define __SHUTDOWN__

#ifndef __TYPES__
#include <MacTypes.H>
#endif

enum  {
	sdOnPowerOff			= 1,			/*call procedure before power off.*/
	sdOnRestart			= 2,			/*call procedure before restart.*/
	sdOnUnmount			= 4,			/*call procedure before unmounting.*/
	sdOnDrivers			= 8,			/*call procedure before closing drivers.*/
	sdRestartOrPower			= 3			/*call before either power off or restart.*/
};


/*
	ShutDownProcs cannot be written in or called from a high-level
	language without the help of mixed mode or assembly glue because they
	use the following parameter-passing convention:

	typedef pascal void (*ShutDwnProcPtr)(short shutDownStage);

		In:
			=>	shutDownStage			D0.W
		Out:
			none
*/

enum  {
	uppShutDwnProcInfo			= kRegisterBased|REGISTER_ROUTINE_PARAMETER(1,kRegisterD0,kTwoByteCode)
};

#if USESROUTINEDESCRIPTORS
typedef void (pascal *ShutDwnProcPtr)(short shutDownStage);

typedef UniversalProcPtr ShutDwnUPP;

#define CallShutDwnProc(userRoutine, shutDownStage)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppShutDwnProcInfo, (shutDownStage))

#define NewShutDwnProc(userRoutine)  \
	(ShutDwnUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppShutDwnProcInfo, GetCurrentISA())

#else
typedef ProcPtr ShutDwnUPP;

#define NewShutDwnProc(userRoutine)  \
	(ShutDwnUPP)(userRoutine)

#endif

#ifdef __cplusplus
extern "C" {
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

extern void pascal ShutDwnPower(void);
extern void pascal ShutDwnStart(void);
extern void pascal ShutDwnInstall(ShutDwnUPP shutDownProc, short flags);
extern void pascal ShutDwnRemove(ShutDwnUPP shutDownProc);
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



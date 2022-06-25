/**
 * @file stealthdbgctrl.h
 * @author anonymous
 * @brief Main interface to connect applications to driver headers
 * @details
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//
// The following ifdef block is the standard way of creating macros which make
// exporting from a DLL simpler. All files within this DLL are compiled with the
// stealthdbgCTRL_EXPORTS symbol defined on the command line. This symbol should not
// be defined on any project that uses this DLL. This way any other project
// whose source files include this file see stealthdbgCTRL_API functions as being
// imported from a DLL, whereas this DLL sees symbols defined with this macro as
// being exported.
//

#ifdef stealthdbgCTRL_EXPORTS
#    define stealthdbgCTRL_API __declspec(dllexport)
#else
#    define stealthdbgCTRL_API __declspec(dllimport)
#endif

//
// This class is exported from the dll
//
class stealthdbgCTRL_API Cstealthdbgctrl
{
public:
    Cstealthdbgctrl(void);
    //
    // TODO: add your methods here.
    //
};

extern stealthdbgCTRL_API int nstealthdbgctrl;

stealthdbgCTRL_API int
fnstealthdbgctrl(void);

//////////////////////////////////////////////////
//					Installer
////
//////////////////////////////////////////////////

#define DRIVER_FUNC_INSTALL 0x01
#define DRIVER_FUNC_STOP    0x02
#define DRIVER_FUNC_REMOVE  0x03

BOOLEAN
ManageDriver(_In_ LPCTSTR DriverName, _In_ LPCTSTR ServiceName, _In_ UINT16 Function);

BOOLEAN
SetupDriverName(_Inout_updates_bytes_all_(BufferLength) PCHAR DriverLocation,
                _In_ ULONG                                    BufferLength);

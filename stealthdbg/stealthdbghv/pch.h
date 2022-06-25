/**
 * @file pch.h
 * @author anonymous
 * @author anonymous
 * @brief Pre-compiled headers
 * @details
 *
 * @version 0.1
 * @date 2020-07-13
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

#define _NO_CRT_STDIO_INLINE

#pragma warning(disable : 4201) // suppress nameless struct/union warning

//
// Windows defined functions
//
#include <ntifs.h>
#include <ntddk.h>
#include <wdf.h>
#include <wdm.h>
#include <ntstrsafe.h>
#include <Windef.h>
#include <intrin.h>

//
// Scope definitions
//
#define SCRIPT_ENGINE_KERNEL_MODE
#define StealthDbg_KERNEL_MODE

//
// External headers
//
#include "ia32-doc/out/ia32.h"

//
// StealthDbg Kernel-mode headers
//
#include "Definition.h"
#include "Configuration.h"
#include "platform/CrossApi.h"
#include "platform/Environment.h"
#include "platform/MetaMacros.h"

#include "..\stealthdbghv\header\vmm\vmx\VmxBroadcast.h"
#include "..\stealthdbghv\header\common\Dpc.h"
#include "..\stealthdbghv\header\common\LengthDisassemblerEngine.h"
#include "..\stealthdbghv\header\common\Logging.h"
#include "..\stealthdbghv\header\memory\MemoryMapper.h"
#include "..\stealthdbghv\header\common\Msr.h"
#include "..\stealthdbghv\header\debugger\tests\KernelTests.h"
#include "..\stealthdbghv\header\memory\PoolManager.h"
#include "..\stealthdbghv\header\common\Trace.h"
#include "..\stealthdbghv\header\debugger\broadcast\DpcRoutines.h"
#include "..\stealthdbghv\header\misc\InlineAsm.h"
#include "..\stealthdbghv\header\vmm\ept\Vpid.h"
#include "..\stealthdbghv\header\vmm\ept\Ept.h"
#include "..\stealthdbghv\header\common\Common.h"
#include "..\stealthdbghv\header\vmm\vmx\Events.h"
#include "..\stealthdbghv\header\debugger\core\Debugger.h"
#include "..\stealthdbghv\header\devices\Apic.h"
#include "..\stealthdbghv\header\debugger\kernel-level\Kd.h"
#include "..\stealthdbghv\header\debugger\user-level\Ud.h"
#include "..\stealthdbghv\header\vmm\vmx\Mtf.h"
#include "..\stealthdbghv\header\debugger\core\DebuggerEvents.h"
#include "..\stealthdbghv\header\debugger\features\Hooks.h"
#include "..\stealthdbghv\header\vmm\vmx\Counters.h"
#include "..\stealthdbghv\header\debugger\transparency\Transparency.h"
#include "..\stealthdbghv\header\vmm\vmx\IdtEmulation.h"
#include "..\stealthdbghv\header\vmm\ept\Invept.h"
#include "..\stealthdbghv\header\debugger\broadcast\Broadcast.h"
#include "..\stealthdbghv\header\vmm\vmx\Vmcall.h"
#include "..\stealthdbghv\header\vmm\vmx\ManageRegs.h"
#include "..\stealthdbghv\header\vmm\vmx\Vmx.h"
#include "..\stealthdbghv\header\debugger\commands\BreakpointCommands.h"
#include "..\stealthdbghv\header\debugger\commands\DebuggerCommands.h"
#include "..\stealthdbghv\header\debugger\commands\ExtensionCommands.h"
#include "..\stealthdbghv\header\debugger\commands\Callstack.h"
#include "..\stealthdbghv\header\debugger\communication\SerialConnection.h"
#include "..\stealthdbghv\header\debugger\objects\Process.h"
#include "..\stealthdbghv\header\debugger\objects\Thread.h"
#include "..\stealthdbghv\header\components\registers\DebugRegisters.h"
#include "..\stealthdbghv\header\vmm\vmx\Hv.h"
#include "..\stealthdbghv\header\vmm\vmx\MsrHandlers.h"
#include "..\stealthdbghv\header\vmm\vmx\ProtectedHv.h"
#include "..\stealthdbghv\header\vmm\vmx\IoHandler.h"
#include "..\stealthdbghv\header\vmm\vmx\VmxMechanisms.h"
#include "..\stealthdbghv\header\debugger\user-level\Attaching.h"
#include "..\stealthdbghv\header\debugger\core\Termination.h"
#include "..\stealthdbghv\header\debugger\user-level\UserAccess.h"
#include "..\stealthdbghv\header\debugger\user-level\ThreadHolder.h"
#include "ScriptEngineCommonDefinitions.h"

//
// Global Variables should be the last header to include
//
#include "..\stealthdbghv\header\globals\GlobalVariableManagement.h"
#include "..\stealthdbghv\header\globals\GlobalVariables.h"

/**
 * @file exports.h
 * @author anonymous
 * @brief StealthDbg exported functions
 * @details
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//////////////////////////////////////////////////
//					  Exports                   //
//////////////////////////////////////////////////

//
// Exports
//
extern "C" {
extern bool inline AsmVmxSupportDetection();

__declspec(dllexport) int StealthDbgInterpreter(char * Command);
__declspec(dllexport) int StealthDbgLoadVmm();
__declspec(dllexport) int StealthDbgUnload();
__declspec(dllexport) int StealthDbgInstallVmmDriver();
__declspec(dllexport) int StealthDbgUninstallDriver();
__declspec(dllexport) int StealthDbgStopDriver();
__declspec(dllexport) void StealthDbgShowSignature();
__declspec(dllexport) void StealthDbgSetTextMessageCallback(Callback handler);
__declspec(dllexport) void StealthDbgScriptReadFileAndExecuteCommand(vector<string> & PathAndArgs);
__declspec(dllexport) bool StealthDbgContinuePreviousCommand();
__declspec(dllexport) bool StealthDbgCheckMultilineCommand(std::string & CurrentCommand, bool Reset);
}

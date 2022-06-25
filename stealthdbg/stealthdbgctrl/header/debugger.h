/**
 * @file debugger.h
 * @author anonymous
 * @brief General debugger functions
 * @details
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//////////////////////////////////////////////////
//            	    Structures                  //
//////////////////////////////////////////////////

/**
 * @brief In debugger holds the state of events
 *
 */
typedef struct _DEBUGGER_SYNCRONIZATION_EVENTS_STATE
{
    HANDLE  EventHandle;
    BOOLEAN IsOnWaitingState;
} DEBUGGER_SYNCRONIZATION_EVENTS_STATE, *PDEBUGGER_SYNCRONIZATION_EVENTS_STATE;

//////////////////////////////////////////////////
//				    Functions                   //
//////////////////////////////////////////////////

VOID
InterpreterRemoveComments(char * CommandText);

BOOLEAN
ShowErrorMessage(UINT32 Error);

BOOLEAN
IsConnectedToAnyInstanceOfDebuggerOrDebuggee();

BOOLEAN
IsTagExist(UINT64 Tag);

UINT64
DebuggerGetNtoskrnlBase();

BOOLEAN
DebuggerPauseDebuggee();

BOOLEAN
InterpretConditionsAndCodes(vector<string> * SplittedCommand,
                            vector<string> * SplittedCommandCaseSensitive,
                            BOOLEAN          IsConditionBuffer,
                            PUINT64          BufferAddress,
                            PUINT32          BufferLength);

VOID
FreeEventsAndActionsMemory(PDEBUGGER_GENERAL_EVENT_DETAIL Event,
                           PDEBUGGER_GENERAL_ACTION       ActionBreakToDebugger,
                           PDEBUGGER_GENERAL_ACTION       ActionCustomCode,
                           PDEBUGGER_GENERAL_ACTION       ActionScript);

BOOLEAN
SendEventToKernel(PDEBUGGER_GENERAL_EVENT_DETAIL Event,
                  UINT32                         EventBufferLength);

BOOLEAN
RegisterActionToEvent(PDEBUGGER_GENERAL_EVENT_DETAIL Event,
                      PDEBUGGER_GENERAL_ACTION       ActionBreakToDebugger,
                      UINT32                         ActionBreakToDebuggerLength,
                      PDEBUGGER_GENERAL_ACTION       ActionCustomCode,
                      UINT32                         ActionCustomCodeLength,
                      PDEBUGGER_GENERAL_ACTION       ActionScript,
                      UINT32                         ActionScriptLength);

BOOLEAN
InterpretGeneralEventAndActionsFields(
    vector<string> *                    SplittedCommand,
    vector<string> *                    SplittedCommandCaseSensitive,
    DEBUGGER_EVENT_TYPE_ENUM            EventType,
    PDEBUGGER_GENERAL_EVENT_DETAIL *    EventDetailsToFill,
    PUINT32                             EventBufferLength,
    PDEBUGGER_GENERAL_ACTION *          ActionDetailsToFillBreakToDebugger,
    PUINT32                             ActionBufferLengthBreakToDebugger,
    PDEBUGGER_GENERAL_ACTION *          ActionDetailsToFillCustomCode,
    PUINT32                             ActionBufferLengthCustomCode,
    PDEBUGGER_GENERAL_ACTION *          ActionDetailsToFillScript,
    PUINT32                             ActionBufferLengthScript,
    PDEBUGGER_EVENT_PARSING_ERROR_CAUSE ReasonForErrorInParsing);

BOOLEAN
CallstackReturnAddressToCallingAddress(UCHAR * ReturnAddress, PUINT32 IndexOfCallFromReturnAddress);

VOID
CallstackShowFrames(PDEBUGGER_SINGLE_CALLSTACK_FRAME  CallstackFrames,
                    UINT32                            FrameCount,
                    DEBUGGER_CALLSTACK_DISPLAY_METHOD DisplayMethod,
                    BOOLEAN                           Is32Bit);

UINT64
GetNewDebuggerEventTag();

DWORD WINAPI
ListeningSerialPauseDebuggeeThread(PVOID Param);

DWORD WINAPI
ListeningSerialPauseDebuggerThread(PVOID Param);

VOID
LogopenSaveToFile(const char * Text);

BOOL
BreakController(DWORD CtrlType);

VOID
CommandEventsShowEvents();

BOOLEAN
CommandEventsModifyAndQueryEvents(UINT64                      Tag,
                                  DEBUGGER_MODIFY_EVENTS_TYPE TypeOfAction);

VOID
CommandEventsHandleModifiedEvent(
    UINT64                  Tag,
    PDEBUGGER_MODIFY_EVENTS ModifyEventRequest);

VOID
CommandEventsClearAllEventsAndResetTags();

VOID
CommandFlushRequestFlush();

UINT64
GetCommandAttributes(const string & FirstCommand);

VOID
DetachFromProcess();

BOOLEAN
CommandLoadVmmModule();

VOID
ShowAllRegisters();

VOID
CommandPauseRequest();

VOID
CommandGRequest();

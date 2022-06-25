/**
 * @file script-engine.h
 * @author anonymous
 * @brief Script engine parser and codegen
 * @details
 * @version 0.1
 * @date 2020-10-22
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

#ifndef SCRIPT_ENGINE_H
#    define SCRIPT_ENGINE_H

//
// *** import pdb parser functions ***
//
__declspec(dllimport) VOID SymSetTextMessageCallback(PVOID Handler);
__declspec(dllimport) UINT64 SymConvertNameToAddress(const char * FunctionOrVariableName, PBOOLEAN WasFound);
__declspec(dllimport) UINT32 SymLoadFileSymbol(UINT64 BaseAddress, const char * PdbFileName);
__declspec(dllimport) UINT32 SymUnloadAllSymbols();
__declspec(dllimport) UINT32 SymUnloadModuleSymbol(char * ModuleName);
__declspec(dllimport) UINT32 SymSearchSymbolForMask(const char * SearchMask);
__declspec(dllimport) BOOLEAN ScriptEngineGetFieldOffset(CHAR * TypeName, CHAR * FieldName, UINT32 * FieldOffset);
__declspec(dllimport) BOOLEAN ScriptEngineGetDataTypeSize(CHAR * TypeName, UINT64 * TypeSize);
__declspec(dllimport) BOOLEAN SymGetFieldOffset(CHAR * TypeName, CHAR * FieldName, UINT32 * FieldOffset);
__declspec(dllimport) BOOLEAN SymGetDataTypeSize(CHAR * TypeName, UINT64 * TypeSize);
__declspec(dllimport) BOOLEAN SymCreateSymbolTableForDisassembler(void * CallbackFunction);
__declspec(dllimport) BOOLEAN SymConvertFileToPdbPath(const char * LocalFilePath, char * ResultPath);
__declspec(dllimport) BOOLEAN SymConvertFileToPdbFileAndGuidAndAgeDetails(const char * LocalFilePath, char * PdbFilePath, char * GuidAndAgeDetails);
__declspec(dllimport) BOOLEAN SymbolInitLoad(PVOID BufferToStoreDetails, UINT32 StoredLength, BOOLEAN DownloadIfAvailable, const char * SymbolPath, BOOLEAN IsSilentLoad);
__declspec(dllimport) BOOLEAN SymShowDataBasedOnSymbolTypes(const char * TypeName, UINT64 Address, BOOLEAN IsStruct, PVOID BufferAddress, const char * AdditionalParameters);
__declspec(dllimport) BOOLEAN SymQuerySizeof(_In_ const char * StructNameOrTypeName, _Out_ UINT32 * SizeOfField);
__declspec(dllimport) BOOLEAN SymCastingQueryForFiledsAndTypes(_In_ const char * StructName, _In_ const char * FiledOfStructName, _Out_ PBOOLEAN IsStructNamePointerOrNot, _Out_ PBOOLEAN IsFiledOfStructNamePointerOrNot, _Out_ char ** NewStructOrTypeName, _Out_ UINT32 * OffsetOfFieldFromTop, _Out_ UINT32 * SizeOfField);

//
// *** export pdb wrapper as script engine function ***
//
__declspec(dllexport) VOID ScriptEngineSetTextMessageCallback(PVOID Handler);
__declspec(dllexport) UINT64
    ScriptEngineConvertNameToAddress(const char * FunctionOrVariableName, PBOOLEAN WasFound);
__declspec(dllexport) UINT32
    ScriptEngineLoadFileSymbol(UINT64 BaseAddress, const char * PdbFileName);
__declspec(dllexport) UINT32
    ScriptEngineUnloadAllSymbols();
__declspec(dllexport) UINT32
    ScriptEngineUnloadModuleSymbol(char * ModuleName);
__declspec(dllexport) UINT32
    ScriptEngineSearchSymbolForMask(const char * SearchMask);
__declspec(dllexport) BOOLEAN
    ScriptEngineGetFieldOffset(CHAR * TypeName, CHAR * FieldName, UINT32 * FieldOffset);
__declspec(dllexport) BOOLEAN
    ScriptEngineGetDataTypeSize(CHAR * TypeName, UINT64 * TypeSize);
__declspec(dllexport) BOOLEAN
    ScriptEngineCreateSymbolTableForDisassembler(void * CallbackFunction);
__declspec(dllexport) BOOLEAN
    ScriptEngineConvertFileToPdbPath(const char * LocalFilePath, char * ResultPath);
__declspec(dllexport) BOOLEAN
    ScriptEngineConvertFileToPdbFileAndGuidAndAgeDetails(const char * LocalFilePath, char * PdbFilePath, char * GuidAndAgeDetails);
__declspec(dllexport) BOOLEAN
    ScriptEngineSymbolInitLoad(PVOID BufferToStoreDetails, UINT32 StoredLength, BOOLEAN DownloadIfAvailable, const char * SymbolPath, BOOLEAN IsSilentLoad);
__declspec(dllexport) BOOLEAN
    ScriptEngineShowDataBasedOnSymbolTypes(const char * TypeName, UINT64 Address, BOOLEAN IsStruct, PVOID BufferAddress, const char * AdditionalParameters);
__declspec(dllexport) VOID
    ScriptEngineSymbolAbortLoading();

typedef enum _SCRIPT_ENGINE_ERROR_TYPE
{
    SCRIPT_ENGINE_ERROR_FREE,
    SCRIPT_ENGINE_ERROR_SYNTAX,
    SCRIPT_ENGINE_ERROR_UNKOWN_TOKEN,
    SCRIPT_ENGINE_ERROR_UNRESOLVED_VARIABLE,
    SCRIPT_ENGINE_ERROR_UNHANDLED_SEMANTIC_RULE,
    SCRIPT_ENGINE_ERROR_TEMP_LIST_FULL
} SCRIPT_ENGINE_ERROR_TYPE,
    *PSCRIPT_ENGINE_ERROR_TYPE;

PSYMBOL
NewSymbol(void);

PSYMBOL
NewStringSymbol(char * value);

unsigned int
GetStringSymbolSize(PSYMBOL Symbol);

void
RemoveSymbol(PSYMBOL * Symbol);

__declspec(dllexport) void PrintSymbol(PSYMBOL Symbol);

PSYMBOL_BUFFER
NewSymbolBuffer(void);

__declspec(dllexport) void RemoveSymbolBuffer(PSYMBOL_BUFFER SymbolBuffer);

PSYMBOL_BUFFER
PushSymbol(PSYMBOL_BUFFER SymbolBuffer, const PSYMBOL Symbol);

__declspec(dllexport) void PrintSymbolBuffer(const PSYMBOL_BUFFER SymbolBuffer);

PSYMBOL
ToSymbol(PTOKEN PTOKEN, PSCRIPT_ENGINE_ERROR_TYPE Error);

__declspec(dllexport) PSYMBOL_BUFFER ScriptEngineParse(char * str);

void
ScriptEngineBooleanExpresssionParse(
    UINT64                    BooleanExpressionSize,
    PTOKEN                    FirstToken,
    PTOKEN_LIST               MatchedStack,
    PSYMBOL_BUFFER            CodeBuffer,
    char *                    str,
    char *                    c,
    PSCRIPT_ENGINE_ERROR_TYPE Error);

UINT64
BooleanExpressionExtractEnd(char * str, BOOL * WaitForWaitStatementBooleanExpression, PTOKEN CurrentIn);

void
CodeGen(PTOKEN_LIST MatchedStack, PSYMBOL_BUFFER CodeBuffer, PTOKEN Operator, PSCRIPT_ENGINE_ERROR_TYPE Error);

unsigned long long int
RegisterToInt(char * str);

unsigned long long int
PseudoRegToInt(char * str);

unsigned long long int
SemanticRuleToInt(char * str);

char *
HandleError(PSCRIPT_ENGINE_ERROR_TYPE Error, char * str);

int
GetGlobalIdentifierVal(PTOKEN PTOKEN);

int
GetLocalIdentifierVal(PTOKEN PTOKEN);

int
NewGlobalIdentifier(PTOKEN PTOKEN);

int
NewLocalIdentifier(PTOKEN PTOKEN);

int
LalrGetRhsSize(int RuleId);

BOOL
LalrIsOperandType(PTOKEN PTOKEN);

#endif

? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide
{ This is OsPasProcs.Inc~Text~ }
{ Updated for 3.1 release 2/24/84 }

PUBLIC OS;

{ Processor management routines }

FUNCTION OsCreateProcess (VAR commandLine : BYTES; priority : BYTE; 
                         uses8087 : BOOLEAN; VAR error : WORD) : WORD;

PROCEDURE OsDeleteProcess (pid : WORD; VAR error : WORD);

FUNCTION OsForkProcess (VAR entryPoint : BYTES; priority : BYTE; 
                        uses8087 : BOOLEAN; stackSize : WORD;
                        VAR error : WORD) : WORD;

PROCEDURE OsSend (destPid, class, note : WORD; VAR message : BYTES;
                 VAR error : WORD);


FUNCTION OsReceive (sourcePid, class, timeLimit : WORD;
                   VAR note, error : WORD) : Pointer;

FUNCTION OsCreateSemaphore (VAR error : WORD) : WORD;

PROCEDURE OsDeleteSemaphore (sid : WORD; VAR error : WORD);

FUNCTION OsWait (sid, timeLimit : WORD; VAR error : WORD) : WORD;

PROCEDURE OsSignal (sid : WORD; mode : BYTE; note : WORD; VAR error : WORD);

FUNCTION OsWhoAmI : WORD;

PROCEDURE OsDelay (timeLimit : WORD);

PROCEDURE OsSetPriority (pid : WORD; priority : BYTE; VAR error : WORD);

PROCEDURE OsExit (code : WORD);

{ Memory management routines }

FUNCTION OsAllocate (length : WORD; VAR error : WORD) : Pointer;

PROCEDURE OsFree (block: Pointer; VAR error : WORD);

FUNCTION OsGetSize (block : Pointer; VAR error : WORD) : WORD;

PROCEDURE OsGetMemStatus (pid : WORD; VAR status : MemStatusType;
                         VAR error : WORD);

{ File system routines }

PROCEDURE OsDelete (conn : WORD; VAR error : WORD);

PROCEDURE OsRename (conn : WORD; VAR newName : BYTES; VAR error : WORD);

FUNCTION OsAttach (VAR pathName : BYTES; fileMode : BYTE;
                  VAR reserved : BYTES;
                  accessMode : BYTE; VAR error : WORD) : WORD;

PROCEDURE OsOpen (conn : WORD; numBuf : BYTE; VAR error : WORD);

PROCEDURE OsClose (conn : WORD; VAR error : WORD);

PROCEDURE OsDetach (conn : WORD; VAR error : WORD);

FUNCTION OsRead (conn : WORD; VAR buffer : BYTES; length : WORD;
                VAR error : WORD) : WORD;

PROCEDURE OsWrite (conn : WORD; VAR buffer : BYTES; length : WORD;
                VAR error : WORD);

PROCEDURE OsSeek (conn : WORD; mode : BYTE; length : LONGINT; VAR error : WORD);

PROCEDURE OsTruncate (conn : WORD; VAR error : WORD);

PROCEDURE OsGetStatus (conn : WORD; VAR status : BYTES; 
                      length : WORD; VAR error : WORD);

PROCEDURE OsSetStatus (conn : WORD; VAR status : BYTES; 
                      length : WORD; VAR error : WORD);


PROCEDURE OsChangeExtension (VAR pathName : BYTES; extNum : BYTE;
                            VAR extension : BYTES; VAR error : WORD);

PROCEDURE OsFlushAllBuffers (conn : WORD; VAR error : WORD);

{ Miscellaneous routines }

PROCEDURE OsOverlay (VAR name : BYTES; pid : WORD; VAR error : WORD);

FUNCTION OsGetArgument (short : BOOLEAN; VAR argument : BYTES) : CHAR;

FUNCTION OsSwitchBuffer (VAR buffer : BYTES) : WORD;

PROCEDURE OsRegisterName (VAR name : BYTES; token : LONGINT; 
                         mode : BYTE; VAR error : WORD);

FUNCTION OsLookupName (VAR name : BYTES; VAR error : WORD) : LONGINT;

PROCEDURE OsDecodeException (code : WORD; VAR name : BYTES);

PROCEDURE OsHandleCancel (mode : BOOLEAN);

PROCEDURE OsGetTime (mode : BYTE; VAR time : TimeType);

PROCEDURE OsGetSystemID (VAR systemID : BYTES);

FUNCTION OsGetPrefix: ShortStringPtr;

FUNCTION OsGetWork: ShortStringPtr;

FUNCTION GetConsoleState: ConsoleStatePtr;

PROCEDURE OsGetProperty (tag : WORD; VAR length : WORD;
                         VAR buffer : BYTES; VAR error : WORD);

PROCEDURE OsPutProperty (tag, length: WORD; VAR buffer : BYTES;
                         VAR error : WORD);

PROCEDURE OsMatchWildCard (VAR testStr: BYTES; strLen: WORD; 
                           VAR matchStr: BYTES; matchLen: WORD;
                           indepOfCase: BOOLEAN; fullMatch: BOOLEAN;
                           VAR length: WORD);

PROCEDURE OsAddDevice (VAR pathName: BYTES; VAR name: BYTES;
                       VAR entryPoint: BYTES; intAddr: BYTE;
                       mass: BOOLEAN; mode: WORD; VAR error: WORD);

PROCEDURE OsRemoveDevice (VAR name: BYTES; VAR error: WORD);

PROCEDURE OsCallDriver (VAR pathName: BYTES; level: BYTE; request: WORD;
                        VAR paramList: ParamListType; VAR error: WORD);


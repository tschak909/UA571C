? a?R ? w Q? m
Z<     ? h?	 oP    ? nSystem-wide
/* This is OsPlmProcs.Inc~Text~ */
/* Updated for 3.1 release 2/24/84 */

/* Processor management routines */

OsCreateProcess: PROCEDURE (pCommandLine, priority, uses8087, 
                            pError) WORD EXTERNAL;
    DCL (pCommandLine, pError) PTR;
    DCL (priority, uses8087) BYTE;
    END;

OsDeleteProcess: PROCEDURE (pid, pError) EXTERNAL;
    DCL pid WORD;
    DCL pError PTR;
    END;

OsForkProcess: PROCEDURE (entryPoint, priority, uses8087, stackSize, 
                          pError) WORD EXTERNAL;
    DCL (entryPoint, pError) PTR;
    DCL priority BYTE;
    DCL uses8087 BOOLEAN;
    DCL stackSize WORD;
    END;

OsSend: PROCEDURE (destPid, class, note, pMessage, pError) EXTERNAL;
    DCL destPid WORD;
    DCL (class, note) WORD;
    DCL (pMessage, pError) PTR;
    END;

OsReceive: PROCEDURE (sourcePid, class, timeLimit, pNote, pError) PTR EXTERNAL;
    DCL sourcePid WORD;
    DCL (class, timeLimit) WORD;
    DCL (pNote, pError) PTR;
    END;

OsCreateSemaphore: PROCEDURE (pError) WORD EXTERNAL;
    DCL pError PTR;
    END;

OsDeleteSemaphore: PROCEDURE (sid, pError) EXTERNAL;
    DCL sid WORD;
    DCL pError PTR;
    END;

OsWait: PROCEDURE (sid, timeLimit, pError) WORD EXTERNAL;
    DCL sid WORD;
    DCL timeLimit WORD;
    DCL pError PTR;
    END;

OsSignal: PROCEDURE (sid, mode, note, pError) EXTERNAL;
    DCL sid WORD;
    DCL mode BYTE;
    DCL note WORD;
    DCL pError PTR;
    END;

OsWhoAmI: PROCEDURE WORD EXTERNAL;
    END;
    
OsDelay: PROCEDURE (timeLimit) EXTERNAL;
    DCL timeLimit WORD;
    END;

OsSetPriority: PROCEDURE (pid, priority, pError) EXTERNAL;
    DCL pid WORD;
    DCL priority BYTE;
    DCL pError PTR;
    END;

OsExit: PROCEDURE (code) EXTERNAL;
    DCL code WORD;
    END;

/* Memory management routines */

OsAllocate: PROCEDURE (length, pError) PTR EXTERNAL;
    DCL length WORD;
    DCL pError PTR;
    END;

OsFree: PROCEDURE (block, pError) EXTERNAL;
    DCL block PTR;
    DCL pError PTR;
    END;

OsGetSize: PROCEDURE (block, pError) WORD EXTERNAL;
    DCL block PTR;
    DCL pError PTR;
    END;

OsGetMemStatus: PROCEDURE (pid, pStatus, pError) EXTERNAL;
    DCL pid WORD;
    DCL (pStatus, pError) PTR;
    END;

/* File system routines */

OsDelete: PROCEDURE (conn, pError) EXTERNAL;
    DCL conn WORD;
    DCL pError PTR;
    END;

OsRename: PROCEDURE (conn, pNewName, pError) EXTERNAL;
    DCL conn WORD;
    DCL (pNewName, pError) PTR;
    END;

OsAttach: PROCEDURE (pPathName, fileMode, pReserved, accessMode, 
                     pError) WORD EXTERNAL;
    DCL (pPathName, pReserved, pError) PTR;
    DCL (fileMode, accessMode) BYTE;
    END;

OsOpen: PROCEDURE (conn, numbuf, pError) EXTERNAL;
    DCL conn WORD;
    DCL numbuf BYTE;
    DCL pError PTR;
    END;

OsClose: PROCEDURE (conn, pError) EXTERNAL;
    DCL conn WORD;
    DCL pError PTR;
    END;

OsDetach: PROCEDURE (conn, pError) EXTERNAL;
    DCL conn WORD;
    DCL pError PTR;
    END;

OsRead: PROCEDURE (conn, pBuf, length, pError) WORD EXTERNAL;
    DCL conn WORD;
    DCL length WORD;
    DCL (pBuf, pError) PTR;
    END;

OsWrite: PROCEDURE (conn, pBuf, length, pError) EXTERNAL;
    DCL conn WORD;
    DCL length WORD;
    DCL (pBuf, pError) PTR;
    END;

OsSeek: PROCEDURE (conn, mode, length, pError) EXTERNAL;
    DCL conn WORD;
    DCL length DWORD;
    DCL mode BYTE;
    DCL pError PTR;
    END;

OsTruncate: PROCEDURE (conn, pError) EXTERNAL;
    DCL conn WORD;
    DCL pError PTR;
    END;

OsGetStatus: PROCEDURE (conn, pStatus, length, pError) EXTERNAL;
    DCL conn WORD;
    DCL length WORD;
    DCL (pStatus, pError) PTR;
    END;

OsSetStatus: PROCEDURE (conn, pStatus, length, pError) EXTERNAL;
    DCL conn WORD;
    DCL length WORD;
    DCL (pStatus, pError) PTR;
    END;

OsChangeExtension: PROCEDURE (pPathName, extNum, pExtension, pError) EXTERNAL;
    DCL (pPathName, pExtension, pError) PTR;
    DCL extNum BYTE;
    END;

OsFlushAllBuffers: PROCEDURE (conn, pError) EXTERNAL;
    DCL conn WORD;
    DCL pError PTR;
    END;


/* Miscellaneous routines */

OsOverlay: PROCEDURE (pName, pid, pError) EXTERNAL;
    DCL (pName, pError) PTR;
    DCL pid WORD;
    END;

OsGetArgument: PROCEDURE (short, pArgument) BYTE EXTERNAL;
    DCL short BOOLEAN;
    DCL pArgument PTR;
    END;

OsSwitchBuffer: PROCEDURE (pBuffer) WORD EXTERNAL;
    DCL pBuffer PTR;
    END;

OsRegisterName: PROCEDURE (pName, token, mode, pError) EXTERNAL;
    DCL (pName, pError) PTR;
    DCL token DWORD;
    DCL mode BYTE;
    END;

OsLookupName: PROCEDURE (pName, pError) DWORD EXTERNAL;
    DCL (pName, pError) PTR;
    END;

OsDecodeException: PROCEDURE (code, pName) EXTERNAL;
    DCL code WORD;
    DCL pName PTR;
    END;

OsHandleCancel: PROCEDURE (mode) EXTERNAL;
    DCL mode BOOLEAN;
    END;

OsGetTime: PROCEDURE (mode, pTime) EXTERNAL;
    DCL mode BYTE;
    DCL pTime PTR;
    END;

OsGetSystemID: PROCEDURE (pSystemID) EXTERNAL;
    DCL pSystemID PTR;
    END;

OsGetPrefix: PROCEDURE PTR EXTERNAL;
  END;

OsGetWork: PROCEDURE PTR EXTERNAL;
  END;

GetConsoleState: PROCEDURE PTR EXTERNAL;
  END;

OsGetProperty: PROCEDURE (tag, pLength, pBuffer, pError) EXTERNAL;
  DCL tag       WORD;
  DCL pLength   PTR;
  DCL pBuffer   PTR;
  DCL pError    PTR;
  END;

OsPutProperty: PROCEDURE (tag, length, pBuffer, pError) EXTERNAL;
  DCL tag       WORD;
  DCL length    WORD;
  DCL pBuffer   PTR;
  DCL pError    PTR;
  END;

OsMatchWildCard: PROCEDURE 
   (pTestStr, strLen, pMatchStr, matchLen, indepOfCase, 
    fullMatch, pLength) EXTERNAL;
  DCL indepOfCase BOOLEAN;    
  DCL fullMatch   BOOLEAN;
  DCL matchLen    WORD;
  DCL strLen      WORD;
  DCL pTestStr    PTR;
  DCL pMatchStr   PTR;
  DCL pLength     PTR;
  END;

OsAddDevice: PROCEDURE (pPathName, pName, entryPoint, intAddr, mass, 
                        mode, pError) EXTERNAL;
  DCL mass        BOOLEAN;
  DCL intAddr     BYTE;
  DCL mode        WORD;
  DCL pPathName   PTR;
  DCL pName       PTR;
  DCL entryPoint  PTR;
  DCL pError      PTR;
  END;

OsRemoveDevice: PROCEDURE (pName, pError) EXTERNAL;
    DCL pName     PTR;
    DCL pError    PTR;
    END;

OsCallDriver: PROCEDURE (pPathName, level, request, pPl, pError) EXTERNAL;
  DCL level      BYTE;
  DCL request    WORD;
  DCL pPathName  PTR;
  DCL pPl        PTR;
  DCL pError     PTR;
  END;


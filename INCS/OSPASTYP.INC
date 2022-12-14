? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide
{ This is OsPasTypes.Inc~Text~ }
{ Updated for 3.1 release 2/24/84 }

PUBLIC OS;

CONST
    oldFileMode = 1;
    updateFileMode = 2;
    newFileMode = 3;

    readAccess = 1;
    writeAccess = 2;
    updateAccess = 3;
    partialDirAccess = 5;
    completeDirAccess = 6;

    changeType = 1;
    changeSubtype = 2;
    changePassword = 3;
    returnType = 41h;
    returnSubType = 42h;
    returnPassword = 43h;
    changeIfNoType = 81h;
    changeIfNoSubtype = 82h;
    changeIfNoPassword = 83h;

    seekBackwards = 1;
    seekToHere = 2;
    seekForward = 3;
    seekFromEnd = 4;

    GreenwichMeanTime = 1;
    CompassRelativeTime = 2;

    registerName = 1;
    unRegisterName = 2;

    signalNormal = 1;
    signalEvent = 2;
    signalAllWaiters = 3;

TYPE

    Pointer = ^CHAR;

    MemStatusType =
      RECORD
        freeBytes : LONGINT;
        freeBlocks,
        largestFree : WORD;
        allocBytes : LONGINT;
        allocBlocks,
        largestAlloc : WORD;
      END;

    StatusType = 
      RECORD
        open : BOOLEAN;
        access,
        seek : BYTE;
        filePosition,
        fileLength : LONGINT;
        numPages,
        numAllocatedPages : WORD;
      END;

    ShortString =
      RECORD
        length : BYTE;
        chars : ARRAY [0..255] OF CHAR;
      END;

    ShortStringPtr = ^ShortString;

   	ConsoleStateType = 
      RECORD
      		xLoc : Integer;
	      	yLoc : Integer;
		      cState : Byte;
		      scroll : Byte;
  		    curChar : Byte;
		      upperFlag : Byte;
		      NMIFlag : Byte;
  		  END;

	  ConsoleStatePtr = ^ConsoleStateType;

   ParamListType = 
     RECORD
       conn:  Word;
       buffer: Pointer;
       position: LongInt;
       length: Word;
       mode: Byte;
       numBuf: Byte;
       intAddr: Byte;
       overflow: Pointer;
     END;


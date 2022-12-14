? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide
/* This is OsPlmTypes.Inc~Text~ */
/* Updated for 3.1 release 2/24/84 */

/* constants */

DCL okCode LIT '0';

DCL oldFile    LIT '1';
DCL updateFile LIT '2';
DCL newFile    LIT '3';

DCL readAccess        LIT '1';
DCL writeAccess       LIT '2';
DCL updateAccess      LIT '3';
DCL partialDirAccess  LIT '5';
DCL completeDirAccess LIT '6';

DCL changeType         LIT '1';
DCL changeSubtype      LIT '2';
DCL changePassword     LIT '3';
DCL returnType         LIT '41h';
DCL returnSubType      LIT '42h';
DCL returnPassword     LIT '43h';
DCL changeIfNoType     LIT '81h';
DCL changeIfNoSubtype  LIT '82h';
DCL changeIfNoPassword LIT '83h';

DCL BackwardSeek LIT '1';
DCL AbsoluteSeek LIT '2';
DCL ForwardSeek  LIT '3';
DCL seekFromEnd  LIT '4';

DCL GreenwichMeanTime   LIT '1';
DCL CompassRelativeTime LIT '2';

DCL registerName   LIT '1';
DCL unRegisterName LIT '2';

DCL signalNormal     LIT '1';
DCL signalEvent      LIT '2';
DCL signalAllWaiters LIT '3';

/* types */

DCL MemStatusType LIT 'STRUCTURE
  (freeBytes    DWORD,
   freeBlocks   WORD,
   largestFree  WORD,
   allocBytes   DWORD,
   allocBlocks  WORD,
   largestAlloc WORD)';

DCL StatusType LIT 'STRUCTURE
  (open              BOOLEAN,
   access            BYTE,
   seek              BYTE,
   filePosition      DWORD,
   fileLength        DWORD,
   numPages          WORD,
   numAllocatedPages WORD)';

DCL TimeType LIT 'STRUCTURE
  (year       WORD, 
   month      BYTE, 
   day        BYTE,
   hour       BYTE, 
   minute     BYTE, 
   second     BYTE,
   tenthOfSec BYTE, 
   dayOfWeek  BYTE, 
   dayOfYear  WORD)';

DCL ShortString LIT 'STRUCTURE
  (length      BYTE,
   chars (255) BYTE)';

DCL ConsoleStateType LIT 'STRUCTURE
 (xLoc      WORD, 
  yLoc      WORD,
  cState    BYTE, 
  scroll    BYTE, 
  curChar   BYTE, 
  upperFlag BYTE, 
  NMIFlag   BYTE)';

DCL ParamListType LIT 'STRUCTURE
 (conn       WORD,
  pBuffer    PTR,
  position   DWORD,
  length     WORD,
  mode       BYTE,
  numBuf     BYTE,
  intAddr    BYTE,
  pOverflow  PTR)';


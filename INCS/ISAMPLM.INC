? a?R ? w Q? m^9     ? h?	 oP    ? nSystem-wide/* ISAM.PLM.inc~Text~ 
   PLM include file for the ISAM common code package.


   Copyright (c) 1982, 1983 GRiD Systems Corporation 

   GRiD proprietary

*/


DECLARE DCL           LITERALLY 'DECLARE';
DCL LIT               LITERALLY 'LITERALLY';
DCL BOOLEAN           LIT 'BYTE';
DCL stringType        LIT 'Structure
  (len Word,
   max Word,
   chars (1) CHAR)';
DCL info              LIT 'Structure
  (numIndexes Byte,
   numCols Integer,
   numDeletedrecords Integer)';
 

ISAMInit: PROCEDURE EXTERNAL;
END;

ISAMAppendRecord: PROCEDURE (fileNumber, pNewRecord, pRecordID, pStatus)
                  EXTERNAL;
  DCL fileNumber Integer;
  DCL pNewRecord Pointer;
  DCL pRecordID Pointer;
  DCL pStatus Pointer;
END;

ISAMAttach: PROCEDURE (pFileName, pDummy, pStatus) Integer EXTERNAL;
  DCL pFileName Pointer;
  DCL pDummy    Pointer;
  DCL pStatus Pointer;
END;

ISAMChangeColumns: PROCEDURE(fileNumber, fromColumn, toColumn, columns,
                   eraseOriginal, pStatus) External;
  DCL fileNumber Integer;
  DCL (fromColumn, toColumn, columns) Integer;
  DCL eraseOriginal Boolean;
  DCL pStatus Pointer;
END;

ISAMClose: PROCEDURE (fileNumber, pStatus) EXTERNAL;
  DCL fileNumber Integer;
  DCL pStatus Pointer;
END;

ISAMCloseIndex: PROCEDURE (fileNumber, columnNumber, pStatus) External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pStatus Pointer;
END;

ISAMCompress: PROCEDURE(fileNumber, pstatus) External;
  DCL fileNumber Integer;
  DCL pStatus Pointer;
END;

ISAMCreate: PROCEDURE (pFileName, pDummy, numberColumns, 
                       pStatus) Integer EXTERNAL;
  DCL pFileName Pointer;
  DCL pDummy Pointer;
  DCL pStatus Pointer;
  DCL numberColumns Integer;
END;

ISAMCreateIndex: PROCEDURE (fileNumber, columnNumber, keysAreUnique, 
                            format, pstatus) EXTERNAL;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL keysAreUnique Boolean;
  DCL format Byte;
  DCL pStatus Pointer;
END;

ISAMDecodeError: PROCEDURE(status) Pointer External;
  DCL status Word;
END;
  
ISAMDeleteIndex: PROCEDURE(fileNumber, columnNumber, pStatus) EXTERNAL;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pStatus Pointer;
END;

ISAMDeleteRecord: PROCEDURE (fileNumber, recordID, pStatus) External;
  DCL fileNumber Integer;
  DCL recordID  DWord;
  DCL pStatus Pointer;
END;

ISAMDetach: PROCEDURE (fileNumber, pStatus) EXTERNAL;
  DCL fileNumber Integer;
  DCL pStatus Pointer;
END;
  
ISAMExit: PROCEDURE External;
END;

ISAMFind: PROCEDURE(fileNumber, columnNumber, pValueToFind, pUnique, format,
                    pRecordID, pStatus) External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pValueToFind Pointer;
  DCL pUnique Pointer;
  DCL format Byte;
  DCL pRecordID Pointer;
  DCL pStatus Pointer;
END;

ISAMFindGeneric: PROCEDURE(fileNumber, columnNumber, pValueToFind, pUnique, 
                           pRecordID, pStatus) Pointer External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pValueToFind Pointer;
  DCL pUnique Pointer;
  DCL pRecordID Pointer;
  DCL pStatus Pointer;
END;

ISAMFindNext: PROCEDURE(fileNumber, columnNumber, pUnique, pRecordID,
                        pStatus) Pointer External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pUnique Pointer;
  DCL pRecordID Pointer;
  DCL pStatus Pointer;
END;

ISAMGetStatus: PROCEDURE(fileNumber, pInfo, len, pStatus) Integer External;
  DCL fileNumber Integer;
  DCL pInfo Pointer;
  DCL len Integer;
  DCL pStatus Pointer;
END;

ISAMOpen: PROCEDURE (fileNumber, pStatus) EXTERNAL;
  DCL fileNumber Integer;
  DCL pStatus Pointer;
END;

ISAMOpenIndex: PROCEDURE (fileNumber, columnNumber, pstatus) External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pStatus Pointer;
END;

ISAMRead: PROCEDURE (fileNumber, recordID, pStatus) Pointer EXTERNAL;
  DCL fileNumber Integer;
  DCL recordID DWord;
  DCL pStatus Pointer;
END;

ISAMReplaceRecord: PROCEDURE (fileNumber, pNewRecord, pRecordID, 
                              pStatus) External;
  DCL fileNumber Integer;
  DCL pNewRecord Pointer;
  DCL pRecordID Pointer;
  DCL pStatus Pointer;
END;

ISAMResetFile: PROCEDURE(fileNumber, columnNumber, pStatus) External;
  DCL fileNumber Integer;
  DCL columnNumber Integer;
  DCL pStatus Pointer;
END;


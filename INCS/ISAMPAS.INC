? a?R ? w ?? mP9     ? h?	 o     ? nSystem-wide{ isam.inc 
  Pascal include file for the ISAM common code package.


   Copyright (c) 1982, 1983 GRiD Systems Corporation 

   GRiD proprietary


}


PUBLIC ISAM;
  TYPE
    UniqueType = (keyIsUnique, keyIsNotUnique, UnKnown);
    ISAMInfoType = Record
                   numIndexes: Byte;
                   numCols: Integer;
                   numDeletedRecords: Integer;
                   END;

  PROCEDURE ISAMInit;

  PROCEDURE ISAMAppendRecord (fileNumber: Integer;
                              newRecord: StringPtr;
                              VAR recordID: LongInt;
                              VAR status: Word);

  FUNCTION ISAMAttach (fileName: StringPtr;
                       dummy: StringPtr;
                       VAR status: Word): 
                       Integer;

  PROCEDURE ISAMChangeColumns (fileNumber: Integer;
                               fromColumn: Integer; 
                               toColumn: Integer;
                               columns: Integer;
                               eraseOriginal: Boolean;
                               VAR status: Word);

  PROCEDURE ISAMClose (fileNumber: Integer;
                       VAR status: Word);

  PROCEDURE ISAMCloseIndex (fileNumber: Integer; 
                            columnNum: Integer; 
                            VAR status: Word);

  PROCEDURE ISAMCompress (fileNumber: Integer; 
                          VAR status: Word);

  FUNCTION ISAMCreate (fileName: StringPtr;
                       dummy: StringPtr;
                       numberColumns: Integer;
                       VAR status: Word): 
                       Integer;

  PROCEDURE ISAMCreateIndex (fileNumber: Integer; 
                             columnNumber: Integer;
                             keysAreUnique: Boolean; 
                             format: Byte;
                             VAR status: Word);

  FUNCTION ISAMDecodeError (status: Word):
                            StringPtr;

  PROCEDURE ISAMDeleteIndex (fileNumber: Integer;
                             columnNumber: Integer; 
                             VAR status: Word);

  PROCEDURE ISAMDeleteRecord (fileNumber: Integer;
                              recordID: LongInt;
                              VAR status: Word);

  PROCEDURE ISAMDetach (fileNumber: Integer; 
                        VAR status: Word);

  PROCEDURE ISAMExit;

  PROCEDURE ISAMFind (fileNumber: Integer; 
                      columnNumber: Integer;
                      valueToFind: StringPtr; 
                      VAR unique: UniqueType; 
                      format: Byte;
                      VAR recordID: LongInt; 
                      VAR status: Word);

  FUNCTION ISAMFindGeneric (fileNumber: Integer; 
                            columnNumber: Integer; 
                            valueToFind: stringPtr;
                            VAR unique: uniqueType; 
                            VAR recordID: LongInt; 
                            VAR status: Word): 
                            stringPtr; 

  FUNCTION ISAMFindNext (fileNumber: Integer; 
                         columnNumber: Integer; 
                         VAR unique: uniqueType; 
                         VAR recordID: LongInt; 
                         VAR status: Word): 
                         stringPtr;

  PROCEDURE ISAMGetStatus (fileNumber: Integer; 
                           VAR Info: ISAMInfoType; 
                           len: Integer; 
                           VAR status: Word);

  PROCEDURE ISAMOpen (fileNumber: Integer;
                      VAR status: Word);

  PROCEDURE ISAMOpenIndex (fileNumber: Integer; 
                           columnNumber: Integer; 
                           VAR status: Word); 

  FUNCTION ISAMRead (fileNumber: Integer; 
                     recordID: LongInt;
                     VAR status: Word): 
                     stringPtr;

  PROCEDURE ISAMReplaceRecord (fileNumber: Integer;
                               newRecord: stringPtr;
                               VAR recordID: LongInt;
                               VAR status: Word); 

  PROCEDURE ISAMResetFile (fileNumber: Integer; 
                           columnNumber: Integer; 
                           VAR status: Word);

  
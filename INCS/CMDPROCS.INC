? a?R ? w 4? m
Z<     ? h?	 o     ? nSystem-wide{FILE: `w`incs`CommandProcs.inc~text~}
{ Updated for 3.0 release 6/30/83 }

PUBLIC Erase;
  PROCEDURE CmdErase(conn : Word;
                      msg : MessagePtr;  
                VAR error : Word);

  PROCEDURE CmdMediaUsage(pathName : StringPtr;
                      initialUsage : LongInt;
                               msg : messagePtr;
                       VAR refresh : Rectangle;
                         VAR error : Word);

  PROCEDURE CmdProperties(pathName : StringPtr;
                               msg : MessagePtr;
                       VAR refresh : Rectangle;
                         VAR error : Word);

  FUNCTION GetVersionString(PID : WORD) : StringPtr;

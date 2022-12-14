? a?R ? w Q? m
Z<     ? h?	 oP    ? nSystem-wide{ MessageProcs.inc~text~ }
{ Update for 3.0 release 7/1/83 }


PUBLIC Message;

FUNCTION MsgInit: MessagePtr;


FUNCTION MsgShowPrompt(msg: MessagePtr; str: StringPtr): Boolean;
FUNCTION MsgShowMessage(msg: MessagePtr; str: StringPtr): Boolean;
FUNCTION MsgShowError(msg: MessagePtr; str: StringPtr): Boolean;
FUNCTION MsgShowDecoded(msg: MessagePtr; errorCode: Integer): Boolean;
FUNCTION MsgClearPrompt(msg: MessagePtr): Boolean;
FUNCTION MsgClearMessage(msg: MessagePtr): Boolean;
FUNCTION MsgStackMessage(msg: MessagePtr; str: StringPtr) : Boolean;
FUNCTION MsgStackPrompt(msg: MessagePtr; str: StringPtr) : Boolean;


{------ Usage command ----------}

FUNCTION MsgInitialUsage: LongInt;
FUNCTION UnusedHeapSpace: LongInt;

{------ Exception handling -------}
PROCEDURE MsgTrapException (VAR proc: Bytes);
PROCEDURE MsgExit (code: Word; msg: MessagePtr);

? a?R ? w 4? mP9     ? h?	 o     ? nSystem-wide{Message.inc - Messages, prompts, etc.}
{ Updated for 3.0 release 7/1/83 }

PUBLIC CommonTypes;
TYPE MessageStatus =
       RECORD
       messageShowing: Boolean;
       stackSize : Byte;
       field: FieldPtr;
       rect: Rectangle;     {area to be updated}
       anythingShowing : Boolean;
       END;

     MessagePtr = ^MessageStatus;



? a?R ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide{ File: FieldProcs.inc~text~ }
{ Updated for 3.0 release 6/30/83 }


PUBLIC FieldEdit;

PROCEDURE FldStartKeys(VAR cur: CursorDescriptor);

FUNCTION FldReadKey(VAR cur: CursorDescriptor): Word;

FUNCTION FldKeyInSet(ch : Key; st : SetType) : Boolean;

FUNCTION FldEditField(VAR cur: CursorDescriptor;
                      ch: Word): FieldEditResult;

PROCEDURE FldSetCursor(VAR cur: CursorDescriptor;
                       field: FieldPtr);

PROCEDURE FldSetPos(VAR cur: CursorDescriptor; pos: Word);

PROCEDURE FldDrawCursor(VAR cur: CursorDescriptor);

PROCEDURE FldEraseCursor(VAR cur: CursorDescriptor);

FUNCTION FldInsertInField(VAR cur: CursorDescriptor;
                          ch: Char): Boolean;

PROCEDURE FldDrawField(VAR field: FieldDescriptor);

PROCEDURE FldDrawFieldChars(VAR field:
                                  FieldDescriptor);

FUNCTION FldFormatLine(VAR field: FieldDescriptor;
                       charIndex: Word;
                       VAR limPos: Word;
                       VAR leftEdge: Integer): Boolean;

PROCEDURE FldInvertChar(field: FieldPtr; pos: Word);

PROCEDURE FldHilightField(VAR field: FieldDescriptor);

PROCEDURE FldDimHilightField(VAR field: FieldDescriptor);


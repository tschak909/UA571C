? a?R ? w Q? m
Z<     ? h?	 oP    ? nSystem-wide{ StringProcs.inc~text~ }
{ Updated for 3.0 release 7/1/83 }


PUBLIC StringProcs;

FUNCTION NewString(maxLength: Word): StringPtr;

PROCEDURE FreeString(VAR str: StringPtr);


PROCEDURE CopyString(source,dest: StringPtr);

FUNCTION CopyOfString(str: StringPtr): StringPtr;

FUNCTION ConcatStrings(str1,str2: StringPtr): StringPtr;

PROCEDURE AppendString(dest,source: StringPtr);

PROCEDURE AppendChar(dest: StringPtr; ch: Char);

PROCEDURE AppendAnyChar(VAR str: StringPtr; ch: Char);


FUNCTION UpperCase(ch: Char): Char;

FUNCTION EqualStrings(str1,str2: StringPtr): Boolean;

FUNCTION CompareStrings(str1,str2: StringPtr): Comparison;


FUNCTION SubStringLit(VAR lit: Bytes; delim: Char; count: Word): StringPtr;

FUNCTION NewStringLit(VAR lit: Bytes): StringPtr;

FUNCTION ConcatLits (VAR lit1, lit2: Bytes): StringPtr;


PROCEDURE DeleteFromString(str: StringPtr;
                        firstPos, lastPos: Word);

FUNCTION InsertInString(piece,str: StringPtr;
                        pos: Word): Boolean;

FUNCTION InsertCharInString(ch: Char;
                            str: StringPtr;
                            pos: Word): Boolean;


FUNCTION StringToInteger(str: StringPtr;
                         VAR converted: Boolean): Integer;

FUNCTION IntegerToString(int: Integer): StringPtr;

FUNCTION TimeToString(format : Byte; tt : TimeType) : StringPtr;

FUNCTION TranslateHeading(inputStr : StringPtr;
                           width : Integer;
                         pageNum : Integer) : StringPtr;       

FUNCTION SubProperty(MenuString : StringPtr;
                          index : Integer) : StringPtr;

PROCEDURE SetPrefix (fileName: StringPtr);

PROCEDURE ExpandHeading (inStr, outStr, pageStr: StringPtr);

FUNCTION RealToString(aReal: LongReal; fracDigits: Integer): StringPtr;

FUNCTION StringToReal(str: StringPtr; VAR converted: Boolean): LongReal;


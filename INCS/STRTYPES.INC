? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide{FILE: StringTypes.inc~text~ }
{ Updated for 3.0 release 6/30/83 }


PUBLIC CommonTypes;


TYPE
  Literal = Array [1..maxInt] OF Char;

  StringDescriptor = RECORD 
                       len  : Word;
                       max  : Word;
                       dummy: Byte;
                       chars: ARRAY [1..65535] OF Char;
                     END;
  
  StringPtr = ^StringDescriptor;


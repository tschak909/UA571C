? a?R ? d ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide
{ This is Common.Inc }
{ Updated for 3.0 release 6/28/83 }


PUBLIC Common;

CONST okCode = 0;

TYPE Byte = 0..255;
     Comparison = (less, equal, greater);
     
     Key = 0..255;
     Keys = SET OF Key;

     TimeType =
       RECORD
         year : WORD; month, day : BYTE;
         hour, minute, second : BYTE;
         tenthOfSec, dayOfWeek : BYTE;
         dayOfYear : WORD;
       END;


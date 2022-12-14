? a?R ? d ? w *?? m
Z<     ? h?	 o     ? nSystem-wide
{ FILE: WindowTypes.inc~text~ }
{ Updated for 3.1 release 2/24/84 }

PUBLIC CommonTypes;

TYPE	Point = RECORD
		x : Integer;
		y : Integer;
		END;

	Rectangle = RECORD
		topLeft : Point;
		extent : Point;
		END;

	Direction = (up,down,left,right);

	FontInfoRecord = RECORD
		charWidth : Byte;
		charHeight : Byte;
		lineHeight : Byte;
		baseLine : Byte;
		END;
		       
	FontPointer = ^BYTE;

       windowFormat = (screenFormat, GRiDFormat);

       WindowRegion = RECORD
	                 format: WindowFormat;
		           width:  Integer;
		           height: Integer;
		           bufLength: WORD;
		           buf:    Pointer;
		           bitsPerPel: BYTE;
		           bytesPerLine: WORD;
		         END;

	WindowRegionPtr = ^WindowRegion;


? a?R ? d ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide{ FontProcs.Inc - Interface to common font procedures }
{ Updated for 3.0 release 6/30/83 }

PUBLIC FontManager;

FUNCTION FontCount: Integer;

FUNCTION FontNthName(index: Integer): StringPtr;

PROCEDURE FontSetName(name: StringPtr; VAR error: Word);

PROCEDURE FontSetNth(index: Integer; VAR error: Word);

FUNCTION FontCurrentNth: Integer;


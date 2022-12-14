? a?R ?
 w ? mP9     ? h?	 oP     ? nSystem-wide{ CommonPropsProcs.Inc -- definitions for files containing common properties. }
{ Updated for 3.0 release 6/30/83 }

PUBLIC CommonPropsExt;

PROCEDURE FinalizePropertiesLength(conxn: Word; VAR error: Integer);

PROCEDURE GetPropertiesConnection(path: StringPtr;
		VAR fileConxn: Word;
		VAR propertiesLength: Longint;
		VAR error: word);

FUNCTION AuthorOfThisFile(conxn: Word; VAR authorProductCode: Word;
		VAR versionOfThisFile: Byte; VAR error: Integer ): AuthorType;

FUNCTION GetNextRecord(conxn: Word;
			VAR gRecord: GeneralRecordPointer;
			VAR gRecordLength: Word;
			thisIsTheAuthorCalling: Boolean;
			VAR error: Integer): Boolean;

PROCEDURE SkipProperties(conxn: Word; VAR error: Word);

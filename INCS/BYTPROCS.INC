? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide{ Bytes.inc~text~}
{ Updated for 3.0 release 6/30/83 }


PUBLIC ByteProcs;

PROCEDURE MoveBytes (VAR source: Bytes; VAR dest: Bytes; length: Word);
PROCEDURE MoveReverseBytes (VAR source: Bytes; VAR dest: Bytes; 
                            length: Word);
FUNCTION FindByte (VAR source: Bytes; byteToFind: Char; count: Word; 
                   VAR index: Word): Boolean;
FUNCTION CompareBytes (VAR source1, source2: Bytes; count: Word; 
                   VAR index: Word): Boolean;
PROCEDURE SetBytes (value: Char; VAR dest: Bytes; count: Word);
PROCEDURE InsertBytes (VAR source, dest: Bytes; len, pos, byteCount: Word);
PROCEDURE DeleteBytes (VAR source, dest: Bytes; sourceLen, pos, 
                       byteCount: Word);


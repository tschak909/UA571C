? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide
{ This is ConPas.Inc~Text~ }
{ Updated for 3.1 release 2/24/84 }

PUBLIC Con;

  FUNCTION ConKeyPressed: BOOLEAN;

  FUNCTION ConCharIn: CHAR;

  PROCEDURE ConDefCsr (on: BOOLEAN);

  PROCEDURE ConResetDisplay;

  PROCEDURE ConMoveCsr (x, y: BYTE);

  PROCEDURE ConCharOut (ch: CHAR);

  PROCEDURE ConLineOut (VAR buffer: BYTES; length: WORD);

  FUNCTION ConPeekChar: CHAR;

  PROCEDURE ConHexOut (num: WORD);

  FUNCTION ConLineIn (VAR buffer: BYTES; maxLength: WORD): WORD;


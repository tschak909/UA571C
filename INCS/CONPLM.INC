? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide
/* This is ConPlm.Inc~Text~ */
/* Updated for 3.1 release 2/24/84 */


  ConKeyPressed: PROCEDURE BOOLEAN EXTERNAL;
    END;

  ConCharIn: PROCEDURE BYTE EXTERNAL;
    END;

  ConDefCsr: PROCEDURE (on) EXTERNAL;
    DCL on BOOLEAN;
    END;

  ConResetDisplay: PROCEDURE EXTERNAL;
    END;

  ConMoveCsr: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) BYTE;
    END;
            
  ConCharOut: PROCEDURE (ch) EXTERNAL;
    DCL ch BYTE;
    END;

  ConLineOut: PROCEDURE (pBuffer, length) EXTERNAL;
    DCL pBuffer PTR;
    DCL length WORD;
    END;

  ConPeekChar: PROCEDURE BYTE EXTERNAL;
    END;

  ConHexOut: PROCEDURE (num) EXTERNAL;
    DCL num   WORD;
    END;

  ConLineIn: PROCEDURE (pBuffer, maxLength) WORD EXTERNAL;
    DCL maxLength  WORD;
    DCL pBuffer    PTR;
    END;

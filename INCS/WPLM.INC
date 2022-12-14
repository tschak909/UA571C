? a?R ? w Q? m
Z<     ? h?	 oP    ? nSystem-wide
/* This file is WindowsPlm.Inc~Text~ */
/* Updated for 3.1 release 2/24/84 */

DCL Point LIT 'STRUCTURE 
 (x WORD, 
  y WORD)';

DCL Rectangle LIT 'STRUCTURE
 (topLeftX WORD, 
  topLeftY WORD,
  extentX WORD, 
  extentY WORD)';

DCL FontInfoType LIT 'STRUCTURE
 (charWidth   BYTE, 
  charHeight  BYTE,
  lineHeight  BYTE, 
  baseLine    BYTE)';

DCL up LIT '0';
DCL down LIT '1';
DCL left LIT '2';
DCL right LIT '3';

DCL screenFormat LIT '0';
DCL GRiDFormat   LIT '1';

DCL WindowRegionType LIT 'STRUCTURE
 (format       BYTE,
  width        WORD,
  height       WORD,
  bufLength    WORD,
  pBuf         PTR,
  bitsPerPel   BYTE,
  bytesPerLine WORD)';


/* Procedures */

CharHeight: PROCEDURE WORD EXTERNAL;
  END;

CharWidth: PROCEDURE WORD EXTERNAL;
  END;

LineHeight: PROCEDURE WORD EXTERNAL;
  END;

BaseLine: PROCEDURE WORD EXTERNAL;
  END;

WinLoadFont: PROCEDURE (conn, pError) PTR EXTERNAL;
  DCL conn     WORD;
  DCL pError   PTR;
  END;

WinSetFont: PROCEDURE (pFontTable, pStatusBuf, count) PTR EXTERNAL;
  DCL count         WORD;
  DCL pFontTable    PTR;
  DCL pStatusBuf    PTR;
  END;

WinGetWindowExtent: PROCEDURE (pExtent) EXTERNAL;
  DCL pExtent   PTR;
  END;

WinDrawLine: PROCEDURE (x1,y1, x2,y2) EXTERNAL;
    DCL (x1, y1, x2, y2) WORD;
    END;

WinEraseLine: PROCEDURE (x1,y1, x2,y2) EXTERNAL;
    DCL (x1, y1, x2, y2) WORD;
    END;

WinInvertLine: PROCEDURE (x1,y1, x2,y2) EXTERNAL;
    DCL (x1, y1, x2, y2) WORD;
    END;

WinInvertRectangle: PROCEDURE (r1) EXTERNAL;
    DCL r1 PTR;
    END;

WinEraseRectangle: PROCEDURE (r1) EXTERNAL;
    DCL r1 PTR;
    END;

WinCopyRectangle: PROCEDURE (r1, newTopLeftY, newTopLeftX) EXTERNAL;
    DCL r1 PTR;
    DCL newTopLeftY WORD;
    DCL newTopLeftX WORD;
    END;

WinScrollRectangle: PROCEDURE (r1, direction, distance) EXTERNAL;
    DCL r1 PTR;
    DCL direction BYTE;
    DCL distance WORD;
    END;

WinSetWindow: PROCEDURE (w) EXTERNAL;
    DCL w PTR;
    END;

WinSetClip: PROCEDURE (r) EXTERNAL;
    DCL r PTR;
    END;

WinResetClip: PROCEDURE EXTERNAL;
    END;

WinClipLine: PROCEDURE (x1,y1, x2,y2) BOOLEAN EXTERNAL;
    DCL (x1, y1, x2, y2) PTR;
    END;

WinClipRectangle: PROCEDURE (r1) EXTERNAL;
    DCL r1 PTR;
    END;

WinFrameWindow: PROCEDURE EXTERNAL;
    END;

WinEraseWindow: PROCEDURE EXTERNAL;
    END;

WinInitDefaultWindow: PROCEDURE EXTERNAL;
    END;

WinScrollWindow: PROCEDURE (r1, direction, distance) EXTERNAL;
    DCL r1 PTR;
    DCL direction BYTE;
    DCL distance WORD;
    END;

WinDrawChar: PROCEDURE (ch, x, y) EXTERNAL;
    DCL ch BYTE;
    DCL (x, y) WORD;
    END;

WinDrawChars: PROCEDURE (ch, count, x, y) EXTERNAL;
    DCL ch PTR;
    DCL (count, x, y) WORD;
    END;

WinEraseChar: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) WORD;
    END;

WinInvertChar: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) WORD;
    END;

WinDrawPixel: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) WORD;
    END;

WinInvertPixel: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) WORD;
    END;

WinErasePixel: PROCEDURE (x, y) EXTERNAL;
    DCL (x, y) WORD;
    END;

WinTestPixel: PROCEDURE (x, y) BOOLEAN EXTERNAL;
  DCL x      WORD;
  DCL y      WORD;
  END;

WinHandlePhone: PROCEDURE (newValue, pOldValue, pError) EXTERNAL;
  DCL newValue     BYTE;
  DCL pOldValue    PTR;
  DCL pError       PTR;
  END;

WinAllocateWindowMemory: PROCEDURE (width, height, format, pError) PTR EXTERNAL;
  DCL format      BYTE;
  DCL width       WORD;
  DCL height      WORD;
  DCL pError      PTR;
  END;

WinCopyRemoteRectangle: PROCEDURE (pSource, pDest, pRect, 
                                   newTopy, newTopx, mode) EXTERNAL;
  DCL mode       BYTE;
  DCL newTopY    WORD;
  DCL newTopX    WORD;
  DCL pSource    PTR;
  DCL pDest      PTR;
  DCL pRect      PTR;
  END;

WinSetAlternateWindow: PROCEDURE (pWindow) EXTERNAL;
  DCL pWindow    PTR;
  END;


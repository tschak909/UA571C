? a?R ? d ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide
{FILE: WindowProcs.inc~text~ }
{ Updated for 3.1 release 2/24/84 }

PUBLIC Windows;

FUNCTION CharHeight:  Integer;

FUNCTION CharWidth:   Integer;

FUNCTION LineHeight:  Integer;

FUNCTION BaseLine:    Integer;

FUNCTION WinLoadFont (conn : Word; VAR error : WORD): FontPointer;

FUNCTION WinSetFont(font : FontPointer; VAR info : FontInfoRecord;
                    count : Word): FontPointer;

PROCEDURE WinGetWindowExtent(VAR extent: Point);

PROCEDURE WinDrawLine(x1,y1, x2,y2: Integer);

PROCEDURE WinEraseLine(x1,y1, x2,y2: Integer);

PROCEDURE WinInvertLine(x1,y1, x2,y2: Integer);

PROCEDURE WinInvertRectangle(VAR r1: Rectangle);

PROCEDURE WinEraseRectangle(VAR r1: Rectangle);

PROCEDURE WinCopyRectangle(VAR r: Rectangle;
                           newTopLeft: Point);

PROCEDURE WinScrollRectangle(VAR r: Rectangle;
                             dir: Direction;
                             distance: Integer);

PROCEDURE WinSetWindow(VAR w: Rectangle);

PROCEDURE WinSetClip(VAR r: Rectangle);

PROCEDURE WinResetClip;

FUNCTION WinClipLine(VAR x1, y1, x2, y2: Integer): Boolean;

PROCEDURE WinClipRectangle(VAR r: Rectangle);

PROCEDURE WinFrameWindow;

PROCEDURE WinEraseWindow;

PROCEDURE WinInitDefaultWindow;

PROCEDURE WinScrollWindow(VAR r: Rectangle;
                          dir: Direction;
                          distance: Integer);

PROCEDURE WinDrawChar(ch: Char; x,y: Integer);

PROCEDURE WinDrawChars (VAR ch: BYTES; count,x,y: Integer); 

PROCEDURE WinEraseChar(x,y: Integer);

PROCEDURE WinInvertChar(x,y: Integer);

PROCEDURE WinDrawPixel(x,y: Integer);

PROCEDURE WinInvertPixel(x,y: Integer);

PROCEDURE WinErasePixel(x,y: Integer);

FUNCTION WinTestPixel(x, y : Integer ) : Boolean;

PROCEDURE WinHandlePhone (newValue: BYTE; VAR oldValue: BYTE; 
                          VAR error: WORD);

FUNCTION WinAllocateWindowMemory (width: Integer;
                                  height: Integer;
                                  format: WindowFormat;
                              VAR error: WORD): WindowRegionPtr;

PROCEDURE WinSetAlternateWindow (alt: WindowRegionPtr);

PROCEDURE WinCopyRemoteRectangle (source,
                                  dest: WindowRegionPtr;
                              VAR r: Rectangle;
                                  newTopLeft: Point;
                                  mode: WORD);


? a?R? w O? mP9     ? h?	 o     ? nSystem-wide$COMPACT NOLIST

MODULE Header;

$INCLUDE (`C:`Incs`Common~inc~)
$INCLUDE (`C:`Incs`Conpas~inc~)

$INCLUDE (`C:`Incs`FldTypes~Inc~)
$INCLUDE (`C:`Incs`FldProcs~Inc~)

$INCLUDE (`C:`Incs`Msgtypes~inc~)
$INCLUDE (`C:`Incs`Msgprocs~inc~)

$INCLUDE (`C:`Incs`Strtypes~inc~)
$INCLUDE (`C:`Incs`Strprocs~inc~)

$INCLUDE (`C:`Incs`Wtypes~inc~)
$INCLUDE (`C:`Incs`Wprocs~inc~)

$INCLUDE (`C:`Incs`Ospastyp~inc~)

$INCLUDE (`C:`UA571C`Fonts~Inc~)
$INCLUDE (`C:`UA571C`Header~Inc~)

PRIVATE Header;

{-----------------------------------------------------}

PROCEDURE Circle(xcent,ycent,rad:INTEGER);

VAR
   X, Y, D: INTEGER;
   dE, dSE: INTEGER;

BEGIN
  X   := 0;
  Y   := rad;
  D   := 1 - rad;
  dE  := 3;
  dSE := -(rad * 2) + 5;
  WinDrawPixel(xcent-x, ycent-y);
  WinDrawPixel(xcent-x, ycent+y);
  WinDrawPixel(xcent+y, ycent-x);
  WinDrawPixel(xcent-y, ycent+x);
  WHILE y>x DO
    BEGIN
       IF d<0 then
          BEGIN
             D   := d + dE;
             dE  := dE + 2;
             dSE := dSE + 2;
             x := x + 1;
          END
       ELSE
          BEGIN
             d   := d + dSE;
             dE  := dE + 2;
             dSE := dSE + 4;
             x := x + 1;
             y := y - 1;
          END;
       WinDrawPixel(xcent+x, ycent-y);
       WinDrawPixel(xcent-x, ycent+y);
       WinDrawPixel(xcent-x, ycent-y);
       WinDrawPixel(xcent+x, ycent+y);
       WinDrawPixel(xcent+y, ycent-x);
       WinDrawPixel(xcent-y, ycent+x);
       WinDrawPixel(xcent-y, ycent-x);
       WinDrawPixel(xcent+y, ycent+x);
    END;
END;

{-----------------------------------------------------}

PROCEDURE DrawA(X, Y: INTEGER);

BEGIN
   SetAFont;
   WinDrawChar('A',X,Y);
   Circle(X+9,17,16);
END;

{-----------------------------------------------------}

PROCEDURE DisplayHeader;

VAR
   wExtent: Point;
   x: INTEGER;

BEGIN
   WinInitDefaultWindow;
   WinGetWindowExtent(wExtent);

   SetHeaderFont;
   
   WinDrawChars('UA 571-C',8,272,1);

   WinDrawChars('REMOTE SENTRY WEAPON SYSTEM',27,158,18);

   DrawA(10,2);
   DrawA(608,2);

   WinDrawLine(0,35,640,35);
END;

{-----------------------------------------------------}

.
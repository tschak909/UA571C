? a?R? w O? mP9     ? h?	 o     ? nSystem-wide$COMPACT NOLIST

MODULE Fire;

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
$INCLUDE (`C:`UA571C`Fire~Inc~)
$INCLUDE (`C:`UA571C`MainDisp~Inc~)
$INCLUDE (`C:`UA571C`Menu~Inc~)

PRIVATE Fire;

VAR
   r:                                   RECTANGLE;
   rounds: INTEGER;
   rm: INTEGER;
   temperature: INTEGER;
   rmCounter: INTEGER;
   temperatureCounter: INTEGER;
   timeInt: INTEGER;
   timeFrac: INTEGER;
   critical: BOOLEAN;
   criticalCounter: INTEGER;

{-----------------------------------------------------}

PROCEDURE WinDrawRect(X, Y, W, H: INTEGER);
BEGIN
   WinDrawLine(X  ,Y  ,X+W,Y  ); (* TOP *)
   WinDrawLine(X  ,Y+H,X+W,Y+H); (* BOT *)
   WinDrawLine(X  ,Y  ,X  ,Y+H); (* LEF *)
   WinDrawLine(X+W,Y  ,X+W,Y+H); (* RIG *)
END;

{-----------------------------------------------------}

PROCEDURE DrawDisplay;

VAR
   wExtent: Point;
   y: INTEGER;
   refresh: BOOLEAN;

BEGIN
   WinInitDefaultWindow;
   
   DisplayHeader;

   SetSectionFont;
   
   WinDrawChars(' Rounds',7,20,70);
   WinDrawChars('Remaining',9,20,84);
   WinDrawChar(CHR(81H),164,84);

   WinDrawRect(170,70,56,36);
                                       
   WinDrawChars('TIME AT 100%',12,6,150);
   WinDrawChars('   (secs)',9,6,168);

   WinDrawRect(160,144,75,36);
    
   WinDrawChars('Temp   R(M)',12,500,50);

   WinDrawLine(520,68,528,68);  (* DRAW GAUGES *)
   WinDrawLine(588,68,596,68);
   WinDrawLine(528,68,528,180);
   WinDrawLine(596,68,596,180);
   WinDrawLine(508,180,528,180);
   WinDrawLine(576,180,596,180);
   
   y := 180;

   REPEAT                      (* DRAW GRADIENTS *)
      y := y - 16;
      WinDrawLine(520,y,528,y);
      WinDrawLine(588,y,596,y);
   UNTIL y = 68;

   y := 172;

   REPEAT
      WinDrawLine(524,y,528,y);
      WinDrawLine(592,y,596,y);
      y := y - 16;
   UNTIL y < 76;

END;

{-----------------------------------------------------}

PROCEDURE ShowCritical;

BEGIN
   SetSectionFont;

   WinDrawChars('CRITICAL',8,25,118);

   r.TopLeft.x := 6;
   r.TopLeft.y := 101;
   r.extent.x  := 106;
   r.extent.y  := 44;

   WinInvertRectangle(r);

   r.TopLeft.x := r.TopLeft.x + 6;
   r.TopLeft.y := r.TopLeft.y + 6;
   r.extent.x := r.extent.x - 12;
   r.extent.y := r.extent.y - 12;

   WinInvertRectangle(r);

   r.TopLeft.x := r.topLeft.x + 6;
   r.TopLeft.y := r.topLeft.y + 6;
   r.extent.x := r.extent.x - 12;
   r.extent.y := r.extent.y - 12;

   WinInvertRectangle(r);

   r.TopLeft.x := 6;
   r.TopLeft.y := 101;
   r.extent.x := 106;
   r.extent.y := 44;

   WinInvertRectangle(r);

END;

{-----------------------------------------------------}

PROCEDURE ToggleCritical;

BEGIN
   r.TopLeft.x := 6;
   r.TopLeft.y := 101;
   r.extent.x := 106;
   r.extent.y := 44;

   WinInvertRectangle(r);
END;

{-----------------------------------------------------}

PROCEDURE SetRounds(i: INTEGER);

VAR
   p, q, s: StringPtr;

BEGIN
   SetHeaderFont;

   q := IntegerToString(i);

   IF (i < 10) THEN
      BEGIN
         p := NewStringLit('  ');
         s := ConcatStrings(p,q);         
      END
   ELSE IF (i < 100) THEN
      BEGIN
         p := NewStringLit(' ');
         s := ConcatStrings(p,q);
      END
   ELSE
      BEGIN
         s := CopyOfString(q);
         FreeString(q);
      END;
     
   WinDrawChars(s^.chars[1],s^.len,180,82);
   FreeString(s);
END;

{-----------------------------------------------------}

PROCEDURE SetTime(i: INTEGER; j: INTEGER);

VAR
   p   : StringPtr;     (* Decimal point literal *)
   a, b: StringPtr;     (* INTEGERS turned to strings *)
   c, d: StringPtr;     (* a and b possibly with padding added *)
   e, f: StringPtr;     (* Final constructed fixed point display *)
   s, z: StringPtr;     (* Space and Zero strings *)

BEGIN
   SetHeaderFont;
   p := NewStringLit('.');
   s := NewStringLit(' ');
   z := NewStringLit('0');

   a := IntegerToString(i);
   b := IntegerToString(j);

   IF (i < 10) THEN
      BEGIN
         c := ConcatStrings(s,a); (* A is freed *)   
      END
   ELSE
      BEGIN
         c := CopyOfString(a);
         FreeString(a);
         FreeString(s);
      END;

   IF (j < 10) THEN
      BEGIN
         d := ConcatStrings(z,b); (* B is freed *)
      END
   ELSE
      BEGIN
         d := CopyOfString(b);
         FreeString(b);
         FreeString(z);
      END;

   e := ConcatStrings(c,p);  (* C and P Freed *)
   f := ConCatStrings(e,d);  (* E and D Freed *)
   WinDrawChars(f^.chars[1],f^.len,168,155);
   FreeString(f);
END;

{-----------------------------------------------------}

PROCEDURE SetTemperature(i: INTEGER);

BEGIN
   r.TopLeft.x := 508;
   r.TopLeft.y := 135;
   r.Extent.x := 11;
   r.Extent.y := 45; 
   WinInvertRectangle(r);
END;

{-----------------------------------------------------}

PROCEDURE SetRM(i: INTEGER);

BEGIN
END;

PROCEDURE Redraw;

BEGIN
    DrawDisplay;
    SetRounds(rounds);
    rounds := rounds - 1;
    SetTime(timeInt,timeFrac);
    SetTemperature(100);
    SetRM(100);
END;

{-----------------------------------------------------}

PROCEDURE DoFire;

BEGIN
   IF rounds > 0 THEN
      rounds := rounds - 1;
   
   SetRounds(rounds);

   IF TimeInt > 0 THEN
   BEGIN
       IF TimeFrac <= 0 THEN
          BEGIN
             TimeFrac := 99;
             TimeInt := TimeInt - 1;
          END
       ELSE                      
         TimeFrac := TimeFrac - 7;
   END;

   IF timeFrac <= 0 THEN
      timeFrac := 0;

   IF timeInt < 3 THEN
   BEGIN
      timeInt := 0;
      timeFrac := 0;
   END;

   IF rounds < 100 THEN
   BEGIN
      IF critical = FALSE THEN
         BEGIN
            critical := true;
            ShowCritical;
         END;
   END;

   IF critical = TRUE THEN
   BEGIN
      IF criticalCounter = 2 THEN
         BEGIN
            criticalCounter := 0;
            ToggleCritical;
         END
      ELSE
         criticalCounter := criticalCounter + 1;
   END;

   IF rmCounter = 2 THEN
      BEGIN
         rmCounter := 0;
         IF rm > 74 THEN
            BEGIN
               rm := rm - 1;
               WinDrawLine(576,rm,587,rm);
            END;
      END
   ELSE
      BEGIN
         rmCounter := rmCounter + 1;
      END;

   IF temperatureCounter = 2 THEN
      BEGIN
         temperatureCounter := 0;
         IF temperature > 69 THEN
            BEGIN
               temperature := temperature - 1;
               WinDrawLine(508,temperature,519,temperature);
            END;
      END
   ELSE
      BEGIN
         temperatureCounter := temperatureCounter + 1;
      END;

   SetTime(timeInt,timeFrac);
END;

{-----------------------------------------------------}

PROCEDURE DispUI;

VAR
   c: WORD;

BEGIN
   REPEAT
      c := ConCharIn;

      IF c = 0C3H THEN
         Redraw
      ELSE IF c = 100DH THEN
         DoFire
      ELSE IF c = 0DH THEN
         DoFire
      ELSE IF c = 40EFH THEN
         menuItem := 1
      ELSE IF c = 40F1H THEN
         menuItem := -1;

   UNTIL menuItem <> 2; 
END;

{-----------------------------------------------------}

PROCEDURE FireDefaults;

BEGIN
   temperature := 135;
   rm := 180;
   rounds := 500;
   timeInt := 33;
   timeFrac := 33;
   critical := false;
   criticalCounter := 0;
   rmCounter := 0;
   temperatureCounter := 0;
END;

{-----------------------------------------------------}

PROCEDURE FireDisplay;

BEGIN
   Redraw;
   DispUI;
END;
.
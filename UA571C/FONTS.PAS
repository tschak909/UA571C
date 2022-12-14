? a?R? w O? mP9     ? h?	 o     ? nSystem-wide$COMPACT NOLIST

MODULE Fonts;

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
$INCLUDE (`C:`Incs`OSpasprc~inc~)

$INCLUDE (`C:`Incs`Fntprocs~Inc~)

$INCLUDE (`C:`UA571C`Fonts~Inc~)

PRIVATE Fonts;    

VAR
   err:        Word;
   exitFont:   INTEGER;
   font:       StringPtr;

{-------------------------------------------------------}

PROCEDURE FontsInit;

BEGIN
  exitFont := FontGetN;
END;

{-------------------------------------------------------}

PROCEDURE SetHeaderFont;
   
BEGIN
    font := NewStringLit('Tb12X16');
    FontSetName(font,err);
    FreeString(font);
END;

{-------------------------------------------------------}

PROCEDURE SetAFont;
   
BEGIN
    font := NewStringLit('Tb24X32');
    FontSetName(font,err);
    FreeString(font);
END;

{-------------------------------------------------------}

PROCEDURE SetSectionFont;
   
BEGIN
    font := NewStringLit('Tb9X12');
    FontSetName(font,err);
    FreeString(font);
END;

{-------------------------------------------------------}

PROCEDURE FontsDone;

BEGIN
   FontSetNth(exitFont,err);
END;

.
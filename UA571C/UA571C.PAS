? a?R? w O? mP9     ? h?	 o     ? nSystem-wide$COMPACT NOLIST
MODULE Main;

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
$INCLUDE (`C:`UA571C`MainDisp~Inc~)
$INCLUDE (`C:`UA571C`Fire~Inc~)
$INCLUDE (`C:`UA571C`Menu~Inc~)

PROGRAM Main;

{-----------------------------------------------------}

BEGIN
   FontsInit;

   FireDefaults;
   MainDefaults;
   
   menuItem := 1;

   Repeat
      
      CASE menuItem OF
         1: MainDisplay;
         2: FireDisplay;
      END;

   Until menuItem=-1;
   
   FontsDone;

END.
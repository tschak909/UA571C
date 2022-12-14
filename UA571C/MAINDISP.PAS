? a?R? w !^? mP9     ? h?	 o     ? nTg5X8$COMPACT NOLIST

MODULE MainDisp;

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
$INCLUDE (`C:`UA571C`MainDisp~Inc~)
$INCLUDE (`C:`UA571C`Menu~Inc~)
$INCLUDE (`C:`UA571C`Fire~Inc~)

PRIVATE MainDisp;

VAR
   r, smr, wsr, isr, strr, tpr, spr, tsr:                                   RECTANGLE;
   menuState, oldMenuState:             INTEGER;
   systemMode, oldSystemMode:           INTEGER;
   weaponStatus, oldWeaponStatus:       INTEGER;
   iffStatus, oldIffStatus:             INTEGER;
   testRoutine, oldTestRoutine:         INTEGER;
   targetProfile, oldTargetProfile:     INTEGER;
   spectralProfile, oldSpectralProfile: INTEGER;
   targetSelect, oldTargetSelect:       INTEGER;

{-----------------------------------------------------}

PROCEDURE DrawDisplay;

VAR
   wExtent: Point;
   x: INTEGER;

BEGIN
   SetSectionFont;
   
   WinDrawChars('SYSTEM',6,36,39); 
   WinDrawChars('MODE',4,45,52);

   WinDrawChars('WEAPON',6,210,39);
   WinDrawChars('STATUS',6,210,52);

   WinDrawChars('IFF',3,382,39);
   WinDrawChars('STATUS',6,364,52);

   WinDrawChars('TEST',4,536,39);
   WinDrawChars('ROUTINE',7,518,52);
                     
   WinDrawLine(0,66,640,66);
   
   WinDrawLine(160,35,160,66);
   WinDrawLine(320,35,320,66);
   WinDrawLine(480,35,480,66);

   WinDrawLine(160,66,160,124);
   WinDrawLine(320,66,320,124);
   WinDrawLine(480,66,480,124);

   WinDrawChars('AUTO-REMOTE',11,14,69);
   WinDrawChars('MAN-OVERRIDE',12,14,83);
   WinDrawChars(' SEMI-AUTO',10,14,97);

   WinDrawChars('SAFE',4,216,69);
   WinDrawChars('ARMED',5,216,83);

   WinDrawChars('  SEARCH',8,348,69);
   WinDrawChars('   TEST',7,348,83);
   WinDrawChars('  ENGAGED',9,348,97);
   WinDrawChars('INTERROGATE',11,348,111);

   WinDrawChars('  AUTO',6,504,69);
   WinDrawChars('SELECTIVE',9,504,83);

   WinDrawLine(0,124,640,124);

   WinDrawLine(213,124,213,142);
   WinDrawLine(427,124,427,142);

   WinDrawLine(0,142,640,142);

   WinDrawChars('TARGET PROFILE',14,40,128);
   WinDrawChars('SPECTRAL PROFILE',16,240,128);
   WinDrawChars('TARGET SELECT',13,466,128);
   
   WinDrawChars('  SOFT',6,72,145);
   WinDrawChars('SEMI',8,72,145+14);
   WinDrawChars('  HARD',6,72,145+28);                        

   WinDrawChars(' BIO',4,291,145);
   WinDrawChars('INERT',5,291,145+14);

   WinDrawChars('MULTI SPEC',10,427+56,145);
   WinDrawChars('INFRA RED',9,427+56,145+14);
   WinDrawChars('    UV',6,427+56,145+28);

   WinDrawLine(0,212,640,212);
   WinDrawLine(213,142,213,212);
   WinDrawLine(427,142,427,212);
END;

{-----------------------------------------------------}

PROCEDURE SetSystemModeRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            smr.topLeft.x := 0;
            smr.topLeft.y := 0;
            smr.extent.x := 0;
            smr.extent.y := 0;
         END;
      0:
         BEGIN
            smr.topLeft.x := 1;
            smr.topLeft.y := 68;
            smr.extent.x := 158;
            smr.extent.y := 13;
         END;
      1:
         BEGIN
            smr.topLeft.x := 1;
            smr.topLeft.y := 82;
            smr.extent.x := 158;
            smr.extent.y := 13;
         END;
      2:
         BEGIN
            smr.topLeft.x := 1;
            smr.topLeft.y := 96;
            smr.extent.x := 157;
            smr.extent.y := 13;
         END;

   END;
END;

{-----------------------------------------------------}

PROCEDURE SetTargetProfileRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            tpr.topLeft.x := 0;
            tpr.topLeft.y := 0;
            tpr.extent.x := 0;
            tpr.extent.y := 0;
         END;
      0:
         BEGIN
            tpr.topLeft.x := 1;
            tpr.topLeft.y := 144;
            tpr.extent.x := 211;
            tpr.extent.y := 13;
         END;
      1:
         BEGIN
            tpr.topLeft.x := 1;
            tpr.topLeft.y := 158;
            tpr.extent.x := 211;
            tpr.extent.y := 13;
         END;
      2:
         BEGIN
            tpr.topLeft.x := 1;
            tpr.topLeft.y := 172;
            tpr.extent.x := 211;
            tpr.extent.y := 13;
         END;
   END;
END;

{-----------------------------------------------------}

PROCEDURE SetSpectralProfileRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            spr.topLeft.x := 0;
            spr.topLeft.y := 0;
            spr.extent.x := 0;
            spr.extent.y := 0;
         END;
      0:
         BEGIN
            spr.topLeft.x := 215;
            spr.topLeft.y := 144;
            spr.extent.x := 211;
            spr.extent.y := 13;
         END;
      1:
         BEGIN
            spr.topLeft.x := 215;
            spr.topLeft.y := 158;
            spr.extent.x := 211;
            spr.extent.y := 13;
         END;
   END;
END;

{-----------------------------------------------------}

PROCEDURE SetTargetSelectRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            tsr.topLeft.x := 0;
            tsr.topLeft.y := 0;
            tsr.extent.x := 0;
            tsr.extent.y := 0;
         END;
      0:
         BEGIN
            tsr.topLeft.x := 429;
            tsr.topLeft.y := 144;
            tsr.extent.x := 208;
            tsr.extent.y := 13;
         END;
      1:
         BEGIN
            tsr.topLeft.x := 429;
            tsr.topLeft.y := 158;
            tsr.extent.x := 208;
            tsr.extent.y := 13;
         END;
      2:
         BEGIN
            tsr.topLeft.x := 429;
            tsr.topLeft.y := 172;
            tsr.extent.x := 208;
            tsr.extent.y := 13;
         END;
   END;
END;

{-----------------------------------------------------}

PROCEDURE SetWeaponStatusRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            wsr.topLeft.x := 0;
            wsr.topLeft.y := 0;
            wsr.extent.x := 0;
            wsr.extent.y := 0;
         END;
      0:
         BEGIN
            wsr.topLeft.x := 162;
            wsr.topLeft.y := 68;
            wsr.extent.x := 157;
            wsr.extent.y := 13;
         END;
      1:
         BEGIN
            wsr.topLeft.x := 162;
            wsr.topLeft.y := 82;
            wsr.extent.x := 157;
            wsr.extent.y := 13;
         END;
   END;
END;

{-----------------------------------------------------}

PROCEDURE SetIffStatusRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            isr.topLeft.x := 0;
            isr.topLeft.y := 0;
            isr.extent.x := 0;
            isr.extent.y := 0;
         END;
      0:
         BEGIN
            isr.topLeft.x := 322;
            isr.topLeft.y := 68;
            isr.extent.x := 157;
            isr.extent.y := 13;
         END;
      1:
         BEGIN
            isr.topLeft.x := 322;
            isr.topLeft.y := 82;
            isr.extent.x := 157;
            isr.extent.y := 13;
         END;
      2:
         BEGIN
            isr.topLeft.x := 322;
            isr.topLeft.y := 96;
            isr.extent.x := 157;
            isr.extent.y := 13;
         END;
      3:
         BEGIN
            isr.topLeft.x := 322;
            isr.topLeft.y := 110;
            isr.extent.x := 157;
            isr.extent.y := 13;
         END;
   END;   
END;

{-----------------------------------------------------}

PROCEDURE SetTestRoutineRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            strr.topLeft.x := 0;
            strr.topLeft.y := 0;
            strr.extent.x := 0;
            strr.extent.y := 0;
         END;
      0:
         BEGIN
            strr.topLeft.x := 482;
            strr.topLeft.y := 68;
            strr.extent.x := 155;
            strr.extent.y := 13;
         END;
      1:
         BEGIN
            strr.topLeft.x := 482;
            strr.topLeft.y := 82;
            strr.extent.x := 155;
            strr.extent.y := 13;
         END;
   END;
END;

{-----------------------------------------------------}

PROCEDURE SetMenuRectangle(i: INTEGER);

BEGIN
   CASE i of
      -1:
         BEGIN
            r.topLeft.x := 0;
            r.topLeft.y := 0;
            r.extent.x := 0;
            r.extent.y := 0;
         END;
      0:
         BEGIN
            r.topLeft.x := 1;
            r.topLeft.y := 37;
            r.extent.x := 158;
            r.extent.y := 28;
         END;
      1:
         BEGIN
            r.topLeft.x := 162;
            r.topLeft.y := 37;
            r.extent.x := 157;
            r.extent.y := 28;
         END;
      2:
         BEGIN
            r.topLeft.x := 322;
            r.topLeft.y := 37;
            r.extent.x := 157;
            r.extent.y := 28;
         END;
      3:
         BEGIN
            r.topLeft.x := 482;
            r.topLeft.y := 37;
            r.extent.x := 155;
            r.extent.y := 28;
         END;
      4:
         BEGIN
            r.topLeft.x := 1;
            r.topLeft.y := 126;
            r.extent.x := 211;
            r.extent.y := 15;
         END;
      5:
         BEGIN
            r.topLeft.x := 215;
            r.topLeft.y := 126;
            r.extent.x := 211;
            r.extent.y := 15;
         END;
      6:
         BEGIN            
            r.topLeft.x := 429;
            r.topLeft.y := 126;
            r.extent.x := 208;
            r.extent.y := 15;
         END;
   END;   
END;

{-----------------------------------------------------}

PROCEDURE selectMenu(i: INTEGER);

BEGIN

   IF oldMenuState <> menuState THEN
   BEGIN
      SetMenuRectangle(oldMenuState);
      WinInvertRectangle(r);
      SetMenuRectangle(i);
      WinInvertRectangle(r);
      
      oldMenuState := menuState;
      menuState    := i;
      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectSystemMode(i: INTEGER);

BEGIN
   IF oldSystemMode <> systemMode THEN
   BEGIN
      SetSystemModeRectangle(oldSystemMode);
      WinInvertRectangle(smr);
      SetSystemModeRectangle(i);
      WinInvertRectangle(smr);
      
      oldSystemMode := systemMode;
      systemMode    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectWeaponStatus(i: INTEGER);

BEGIN
   IF oldWeaponStatus <> weaponStatus THEN
   BEGIN
      SetWeaponStatusRectangle(oldWeaponStatus);
      WinInvertRectangle(wsr);
      SetWeaponStatusRectangle(i);
      WinInvertRectangle(wsr);
      
      oldWeaponStatus := weaponStatus;
      weaponStatus    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectIffStatus(i: INTEGER);

BEGIN
   IF oldIffStatus <> iffStatus THEN
   BEGIN
      SetIffStatusRectangle(oldIffStatus);
      WinInvertRectangle(isr);
      SetIffStatusRectangle(i);
      WinInvertRectangle(isr);
      
      oldIffStatus := iffStatus;
      iffStatus    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectTestRoutine(i: INTEGER);

BEGIN
   IF oldTestRoutine <> testRoutine THEN
   BEGIN
      SetTestRoutineRectangle(oldTestRoutine);
      WinInvertRectangle(strr);
      SetTestRoutineRectangle(i);
      WinInvertRectangle(strr);
      
      oldTestRoutine := testRoutine;
      testRoutine    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectTargetProfile(i: INTEGER);

BEGIN
   IF oldTargetProfile <> targetProfile THEN
   BEGIN
      SettargetProfileRectangle(oldtargetProfile);
      WinInvertRectangle(tpr);
      SettargetProfileRectangle(i);
      WinInvertRectangle(tpr);
      
      oldtargetProfile := targetProfile;
      targetProfile    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectSpectralProfile(i: INTEGER);

BEGIN
   IF oldspectralProfile <> spectralProfile THEN
   BEGIN
      SetspectralProfileRectangle(oldspectralProfile);
      WinInvertRectangle(spr);
      SetspectralProfileRectangle(i);
      WinInvertRectangle(spr);
      
      oldspectralProfile := spectralProfile;
      spectralProfile    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE selectTargetSelect(i: INTEGER);

BEGIN
   IF oldtargetSelect <> targetSelect THEN
   BEGIN
      SettargetSelectRectangle(oldtargetSelect);
      WinInvertRectangle(tsr);
      SettargetSelectRectangle(i);
      WinInvertRectangle(tsr);
      
      oldtargetSelect := targetSelect;
      targetSelect    := i;      
   END;    
END;

{-----------------------------------------------------}

PROCEDURE Redraw;

BEGIN
   oldMenuState := -1;
   oldSystemMode := -1;
   oldWeaponStatus := -1;
   oldIffStatus := -1;
   oldTestRoutine := -1;
   oldTargetProfile := -1;
   oldSpectralProfile := -1;
   oldTargetSelect := -1;

   DisplayHeader;
   DrawDisplay;

   selectMenu(menuState);
   selectSystemMode(systemMode);
   selectWeaponStatus(weaponStatus);
   selectIffStatus(iffStatus);
   selectTestRoutine(testRoutine);
   selectTargetProfile(targetProfile);
   selectSpectralProfile(spectralProfile);
   selectTargetSelect(targetSelect);
END;

{-----------------------------------------------------}

PROCEDURE menuLeft;

BEGIN              
   IF menuState > 0 THEN
       menuState := menuState - 1;

   SelectMenu(menuState);      
END;

{-----------------------------------------------------}

PROCEDURE menuRight;

BEGIN
   IF menuState < 6 THEN
       menuState := menuState + 1;
   
   SelectMenu(menuState);
END;

{-----------------------------------------------------}

PROCEDURE menuUp;

BEGIN
   IF menuState = 0 THEN
      BEGIN
         IF (systemMode > 0) THEN         
            systemMode := systemMode - 1;
         
         SelectSystemMode(systemMode);
      END
   ELSE IF menuState = 1 THEN
      BEGIN
         IF (weaponStatus > 0) THEN
            weaponStatus := weaponStatus - 1;
         
         SelectWeaponStatus(weaponStatus); 
      END
   ELSE IF menuState = 2 THEN
      BEGIN
         IF (iffStatus > 0) THEN
            iffStatus := iffStatus - 1;

         SelectIffStatus(iffStatus);
      END
   ELSE IF menuState = 3 THEN
      BEGIN
         IF (testRoutine > 0) THEN
            testRoutine := testRoutine - 1;

         SelectTestRoutine(testRoutine);
      END
   ELSE IF menuState = 4 THEN
      BEGIN
         IF (targetProfile > 0) THEN
            targetProfile := targetProfile - 1;

         SelectTargetProfile(targetProfile);
      END
   ELSE IF menuState = 5 THEN
      BEGIN
        IF (spectralProfile > 0)	THEN
           spectralProfile := spectralProfile - 1;

        SelectSpectralProfile(spectralProfile);
      END
   ELSE IF menuState = 6 THEN
      BEGIN
         IF (targetSelect > 0) THEN
            targetSelect := targetSelect - 1;

         SelectTargetSelect(targetSelect);
      END;
END;

{-----------------------------------------------------}

PROCEDURE menuDown;

BEGIN
   IF menuState = 0 THEN
      BEGIN
         IF (systemMode < 3) THEN
            systemMode := systemMode + 1;
         
         SelectSystemMode(systemMode);
      END
   ELSE IF menuState = 1 THEN
      BEGIN
         IF (weaponStatus < 2) THEN
            weaponStatus := weaponStatus + 1;
         
         SelectWeaponStatus(weaponStatus); 
      END
   ELSE IF menuState = 2 THEN
      BEGIN
         IF (iffStatus < 4) THEN
            iffStatus := iffStatus + 1;

         SelectIffStatus(iffStatus);
      END
   ELSE IF menuState = 3 THEN
      BEGIN
         IF (testRoutine < 2) THEN
            testRoutine := testRoutine + 1;

         SelectTestRoutine(testRoutine);
      END
   ELSE IF menuState = 4 THEN
      BEGIN
         IF (targetProfile < 3) THEN
            targetProfile := targetProfile + 1;

         SelectTargetProfile(targetProfile);
      END
   ELSE IF menuState = 5 THEN
      BEGIN
        IF (spectralProfile < 2) THEN
           spectralProfile := spectralProfile + 1;

        SelectSpectralProfile(spectralProfile);
      END
   ELSE IF menuState = 6 THEN
      BEGIN
         IF (targetSelect < 3) THEN
            targetSelect := targetSelect + 1;

         SelectTargetSelect(targetSelect);
      END
END;

{-----------------------------------------------------}

PROCEDURE DispUI;

VAR
   c: WORD;

BEGIN
   REPEAT
      
      c := ConCharIn;

      IF C = 0C3H THEN
         Redraw
      ELSE IF C = 0C4H THEN
         menuDown
      ELSE IF C = 0C5H THEN
         menuUp
      ELSE IF C = 0C6H THEN
         menuLeft
      ELSE IF C = 0C7H THEN
         menuRight
      ELSE IF C = 40E6H THEN
         menuItem := 2
      ELSE IF C = 40F1H THEN
         menuItem := -1
      ELSE IF C = 408DH THEN
         menuItem := 2;

   UNTIL menuItem <> 1 
END;

{-----------------------------------------------------}

PROCEDURE MainDefaults;
BEGIN
   menuState := 0;
   systemMode := 0;
   weaponStatus := 0;
   iffStatus := 0;
   testRoutine := 0;
   targetProfile := 0;
   spectralProfile := 0;
   targetSelect := 0;
END;

{-----------------------------------------------------}

PROCEDURE MainDisplay;

BEGIN
   FireDefaults;
   Redraw;
   DispUI;
END;
.
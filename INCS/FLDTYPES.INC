? a?R ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide{ FieldTypes.inc~text~ }
{ Updated for 3.0 release 6/30/83 }

PUBLIC CommonTypes;

CONST bottomMargin = 1;
      
      
TYPE Alignment = (leftAlign, centerAlign, rightAlign);

     FieldKind =
       PACKED RECORD
       editable, choice, editableChoice, numeric: Boolean;
       align: Alignment;
       END;

     FieldDescriptor =
       RECORD
       box: Rectangle;
       text: StringPtr;
       kind: FieldKind;
       END;

     FieldPtr = ^FieldDescriptor;

     FieldEditResult = 
       (ignored, processed, outOfField, bufferFull,
        fieldFull, escaped, ok);

     SetType = (LegalKeys, TextKeys,
                 ArrowKeys, ChangeRowKeys);

     CursorDescriptor =
       RECORD
       field: FieldPtr;
       pos: Word;
        { Following fields never set directly by client: }
       place: Point;
       on: Boolean;
       keyProcess: Word;
       END;
     

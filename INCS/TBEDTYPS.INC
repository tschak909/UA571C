? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide{ TableEditTypes.inc~text~}
{ Updated for 3.0 release 7/1/83 }
   

PUBLIC CommonTypes;


CONST nowhere = 65535;
      
      
TYPE ColArray = ARRAY [1..2048] OF FieldPtr;
     ColPtr = ^ColArray;
     ScreenArray = ARRAY [1..2048] OF ColPtr;
     ScreenPtr = ^ScreenArray;
     CellId = RECORD col,row: Integer END;
     SelectionRangeKind = (cellRange, textRange, rowRange, colRange);
     TableSelection = RECORD
                      cell: CellId;
                      pos: Word;
                      rangeKind: SelectionRangeKind;
                      END;
     CellTable =
       RECORD
       colPerScreen,rowPerScreen: Integer;
       screen: ScreenPtr;
       movingCell, currentCell, scrollCell : CellId;
       visibleRect: Rectangle;
       constraint,visible:
         RECORD
         top,left,bottom,right: Integer;
         END;
       textCursor: CursorDescriptor;
       editMode: (normal, command);
       commandChar: Char;
       rangeKind: SelectionRangeKind;
       whichParameter: 0..10;
       hilightKind: (noHilight, dim, bright, splitHilight);
       gap: Point;
       anchor: TableSelection;
       sourceAnchor, sourceCurrent: TableSelection;
       commands: Keys;
       hilightOn,verticalGrid, horizontalGrid,
         frame, bottomFrame, rightFrame: Boolean;
       headingRows: Integer;
       headingCols: Integer;
       END;
     
  CellTablePtr = ^CellTable;

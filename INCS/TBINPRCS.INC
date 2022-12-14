? a?R ? w Q? mP9     ? h?	 oP    ? nSystem-wide{ TableInitProcs.inc~text~ }
{ Updated for 3.0 release 7/1/83 }




PUBLIC TableInit;

FUNCTION TblNewScreen(colCount: Integer): ScreenPtr;
PROCEDURE TblDisposeScreen(screen: ScreenPtr;
                           colCount: Integer);

FUNCTION TblNewCol(rowCount: Integer): ColPtr;
PROCEDURE TblDisposeCol(col: ColPtr; rowCount: Integer);

PROCEDURE TblInitTable(colPerScreen,rowPerScreen,
                   chPerLine,linesPerField: Integer;
                   topLeftMargin,
                   fieldGap: Point;
                   VAR table: CellTable;
                   shouldAlloc: Boolean;
                   editable: Boolean;
                   commands: Keys);

PROCEDURE TblSetVisible(VAR table: CellTable);

PROCEDURE TblSetVisibleRect(VAR table: CellTable; VAR r: Rectangle);

PROCEDURE TblDisposeTable (VAR Table: CellTable;
 shouldDispose: Boolean);

PROCEDURE TblAddCol(chPerLine,linesPerField: Integer;
                    VAR table: CellTable;
                    shouldAlloc: Boolean;
                    editable: Boolean);

PROCEDURE TblAddRows(rows, linesPerField: Integer;
                     VAR table: CellTable;
                     shouldAlloc: Boolean;
                     editable: Boolean);


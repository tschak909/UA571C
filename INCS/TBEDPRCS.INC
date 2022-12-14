? a?R ? w Q? mP9     ? h?	 oP     ? nSystem-wide{ TableEditProcs.inc~text~ }
{ Updated for 3.0 release 7/1/83 }


PUBLIC TableEdit;

FUNCTION TblEditTable(VAR table: CellTable; ch: Word): FieldEditResult;

FUNCTION TblChangeFields(VAR table: CellTable; ch: Char): Boolean;

PROCEDURE TblStartSelection(VAR table: CellTable; ch: Char);

PROCEDURE TblConfirmSelection(VAR table: CellTable);

PROCEDURE TblEscapeMode(VAR table: CellTable);

FUNCTION TblEqualCells(cell1, cell2: CellId):Boolean;

PROCEDURE TblSetCurrentCell(VAR table: CellTable; col, row: Integer);

PROCEDURE TblDrawGrid(VAR table: CellTable);

PROCEDURE TblDrawTable(VAR table: CellTable);

PROCEDURE TblScroll(VAR table: CellTable; ch: Char);

PROCEDURE TblHilightTable(VAR table: CellTable);

PROCEDURE TblUnhilightTable(VAR table: CellTable);

PROCEDURE TblHilightCell(VAR table:CellTable; cell: CellId);

PROCEDURE TblDimHilightCell(VAR table: CellTable; cell: CellId);

PROCEDURE TblGetSelectedCellIds(VAR table:CellTable; VAR first,last: CellId);

PROCEDURE TblScrollAdjustCellId(VAR table:CellTable;
                                VAR unscrolled, scrolled: CellId);

FUNCTION TblFieldOfCellId(VAR table: CellTable; cell: CellId): FieldPtr;

FUNCTION TblFieldOfColRow(VAR table: CellTable; col,row: Integer): FieldPtr;

PROCEDURE TblInvertRange(VAR table: CellTable);

PROCEDURE TblInvertSpan(VAR table: CellTable; col1, col2, row1, row2: Integer);

FUNCTION TblCellOnScreen(VAR table: CellTable; cell: CellId): Boolean;

PROCEDURE TblUpdateRect(VAR table: CellTable; VAR rect: Rectangle);

PROCEDURE TblFindBounds(VAR table: CellTable; VAR rect: Rectangle;
                        VAR left, right, top, bottom: Integer);


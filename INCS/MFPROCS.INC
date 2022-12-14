? a?R ? w Q? mP9     ? h?	 oP     ? nSystem-wide{MenuFormProcs.inc}
{ Updated for 3.0 release 7/1/83 }

PUBLIC MenuForm;

FUNCTION MenuInit(usableRect: Rectangle;
                itemCount: Integer;
                FUNCTION ItemStr(index: Integer
                                 ): StringPtr
                ): MenuFormPtr;

FUNCTION FormInit(usableRect: Rectangle;
                  itemCount,maxChPerLabel,
                              choiceLines: Integer;
                  FUNCTION ItemStr(col,row: Integer;
                                 field: FieldPtr
                                 ): StringPtr
                  ): MenuFormPtr;

FUNCTION MenuFormConfirmed
             (menuForm: MenuFormPtr;
              keyProcess: Word;
              FUNCTION ItemStr(col,row: Integer;
                               field: FieldPtr
                               ): StringPtr;
              FUNCTION ChoiceStr(col,row:Integer;
                                 choice: Integer
                                 ): StringPtr;
              FUNCTION ChoiceInfo(col,row,choice:
                                            Integer;
                              request: ChoiceRequest
                              ): Integer;
              FUNCTION ScrollKey(ch: Char; col, row: Integer): UpdateKind;
              VAR selection: Integer;
              VAR ch: Char
              ): Boolean;

FUNCTION MenuFormDispose(menuForm:MenuFormPtr):
{always returns nil}                    MenuFormPtr;


{used if no choice fields in form:}
FUNCTION NilChoiceProc(col,row: Integer;
                    choice: Integer): StringPtr;

FUNCTION NilChoiceInfo(col,row,choice: Integer;
                    request:ChoiceRequest): Integer;

FUNCTION NilItemStr(col,row: Integer;
                    field: FieldPtr): StringPtr;


FUNCTION NilScrollKey(ch: Char; col, row: Integer): UpdateKind;


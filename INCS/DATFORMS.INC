? a?R ? w ?? m
Z<     ? h?	 oP    ? nDefault
{ This is DataForms.Inc~Text~ }

PUBLIC DataForms;

TYPE
    SomeArrayOfBytes = ARRAY [1..1] OF CHAR;

    PointerToSomeBytes = ^SomeArrayOfBytes;

    DataKindType = (stringKind, numberKind, choiceOnlyKind, 
                    fontKind, realNumberKind);

    DataFormModeType = (normalDataForm, initOnlyDataForm, runOnlyDataForm);

    DataKindAliasType = RECORD
                        CASE INTEGER OF
                            1 : (string : StringPtr);
                            2 : (number : INTEGER);
                            3 : (realNumber : REAL);
                        END;

    DataRowType = RECORD
                      changed : BOOLEAN;
                      rowKind : DataKindType;
                      currentChoice : INTEGER;
                      tempChoice : INTEGER;
                      theData : DataKindAliasType;
                      tempData : DataKindAliasType;
                  END;

    DataFormType = RECORD
                       form : PointerToSomeBytes;
                       numItems : INTEGER;
                       labelsAndChoices : PointerToSomeBytes;
                       choiceLines : INTEGER;
                       rows : ARRAY [1..1] OF DataRowType;
                     END;

    DataMenuType = PointerToSomeBytes;

FUNCTION DataMenuConfirmed (dataMenu : DataMenuType;
                            msgStatus : MessagePtr; msg : StringPtr;
                            VAR rect : Rectangle; keyProcess : WORD;
                            VAR selection : INTEGER; VAR ch : CHAR) : BOOLEAN;

FUNCTION DataFormConfirmed (VAR dataForm : DataFormType;
                            dataFormMode : DataFormModeType;
                            msgStatus : MessagePtr; msg : StringPtr; 
                            VAR rect : Rectangle; keyProcess : WORD;
                            VAR ch : CHAR) : BOOLEAN;

PROCEDURE FreeStringsInDataForm (VAR dataForm : DataFormType);

PROCEDURE UnDoDataForm (VAR dataForm : DataFormType; eraseDataForm : BOOLEAN);

FUNCTION StringOfFormItem (VAR dataForm : DataFormType;
                           row : INTEGER) : StringPtr;

FUNCTION ExactCopyOfString (oldStr : StringPtr) : StringPtr;


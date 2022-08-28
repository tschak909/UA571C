PUBLIC FileFormProcs;

FUNCTION FileFormConfirmed
                (FFMode:  FFModeType;     {a get or a put?}
                 userPID: WORD;           {your keyboard process}
                 VAR ch: CHAR;            {last keystroke typed}
                 VAR formRect: Rectangle; {return the rect to refresh}
                 msg: StringPtr;          {message to be displayed}
                 VAR pathName: StringPtr; {Pathname used for defaulting}
                 filter: StringPtr;       {Wildcard filter }

                 VAR defaultRec: DefaultTypeRec; {part(s) used as defaults}

                 attachMode: BOOLEAN;     {should File Form attach file?}

                 mode,                    {mode and access for the attach}
                 access: BYTE;

                 VAR connection: WORD; {connection of the attached file}
                 ExchangeMode: FFExchangeMode; {display exchange and/or save?}
                 VAR ExchangeResult: FFExchangeResult; {the exchange result}
                 VAR SaveResult: FFSaveResult          {the save result}
                 ): BOOLEAN;

  FUNCTION FFExecuteCommand (filename: StringPtr) : WORD;

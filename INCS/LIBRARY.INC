? a?R ? w Q? m^9     ? h?	 oP    ? nSystem-wide{----------------------------------------------------------}
{                       Library.Inc                        }
{----------------------------------------------------------}
PUBLIC Library;

TYPE
    SymbolType = (statement, integerFunction, stringFunction,
                  longRealFunction, booleanFunction);

PROCEDURE RegisterFunction (functionName       : StringPtr;
                            VAR functionAddress: BYTES;
                            functionType       : SymbolType;
                            parameterDescriptor: StringPtr);

{ RegisterFunction frees the two string parameters }

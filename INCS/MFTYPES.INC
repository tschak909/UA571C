? a?R ? w Q? m
Z<     ? h?	 oP     ? nSystem-wide{MenuFormTypes.inc}
{ Updated for 3.0 release 7/1/83 }

PUBLIC CommonTypes;
TYPE
  MenuFormDescriptor =
    RECORD
    table, choiceTable: CellTablePtr;
    obscuredRect,choiceRect: Rectangle;
    choiceLines: Integer;
    END;
  MenuFormPtr = ^MenuFormDescriptor;

  ChoiceRequest = (choiceCountRequest, choiceCurrentRequest,
                   choiceSetCurrent, choiceLeavingItem,
                   choiceEnteringItem, ChoiceUpdateItem);

  UpdateKind = (dontUpdate, updateTop, updateBottom,
                updateForward, updateBackward);



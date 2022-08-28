PUBLIC CommonTypes;

CONST 
  DevicePart   = 1;
  SubjectPart  = 2;
  TitlePart    = 3;
  KindPart     = 4;
  PasswordPart = 5;
  ExchangePart = 6;
  SavePart     = 7;
  
TYPE 
  FFModeType  = (FFGet, FFPut);

  FFExchangeMode = (NoExchangeOrSave, Exchange, ExchangeAndSave);

  FFExchangeResult = (DontExchange, ExchangeFiles, ExchangeApplications);

  FFSaveResult = (SaveFile, DontSaveFile);

  DefaultType = (DefaultThis, DontDefaultThis); 
  
  DefaultTypeRec = ARRAY[DevicePart..KindPart] OF DefaultType;

? a?R ?
 w "? m
Z<     ? h?	 oZ     ? nSystem-wide{ CommonPropsTypes.Inc -- definitions for files containing common properties. }
{ Updated for 3.0 release 6/30/83 }

PUBLIC CommonTypes;


CONST	 { interchange file record header bytes }
	userPropsByte = 0FFh;
	commonPropsByte = 0FEh;
	binaryUserPropsByte = 0FDh;

	 { common properties identifier bytes }
	authorID = 061h;		{ a }
	columnFieldPropsID = 063h;	{ c }
	defaultFieldPropsID = 064h;	{ d }
	cellFieldPropsID = 066h;	{ f }
	textHeaderID = 068h;	{ h }
	rowHeightID = 06Ch;	{ l }
	printOptionsID = 06Dh;	{ m }
	fontPropsID = 06Eh;	{ n }
	rowFieldPropsID = 072h;	{ r }
	tableSizeID = 074h;	{ t }
	columnWidthID = 077h;	{ w }

	 { alignment and format special values }
	useDefaultOfBoth = 255;
	useDefaultAlignment = 7;
	useStandardAlignment = 6;
	useDefaultFormat = 31;


TYPE	AuthorType = (newAuthor, oldAuthor, noAuthor);
	HeadingType = (noHeadings, firstPageOnly, notFirstPage, allPages);
	FormFeedType = (noFormFeeds, formFeedBefore, formFeedAfter,
		     formFeedBeforeAndAfter);
	ColumnType = (noColumnSpacing, oneColumnSpace, gridBetweenColumns);
	TypeSize = (normalType, compressedType, enlargedType, emphasizedType,
		 bannerType);
	
	PrintOptionsRecord = RECORD
	  leftMostChar, rightMostChar:	Byte;
	  firstPageLine, lastPageLine:	Byte;
	  formFeedPlacement:	FormFeedType;
	  columnHeadings:		HeadingType;
	  textHeadings:		HeadingType;
	  columnSpacing:		ColumnType;
	  rowHeadings:		Boolean;
	  letterSize:		TypeSize;
	  END;

	CommonPropertiesRecord = RECORD
	  length:		Word;
	  identifier:	Byte;
	  CASE Integer OF

	    authorID:		(authorCode:	Word;
				 fileVersion:	Byte);
	    printOptionsID:	(printOps:		PrintOptionsRecord);
	    textHeaderID:		(textString:	ARRAY [1..1] OF Char );
	    tableSizeID:		(numTableCols:	Integer;
				 numTableRows:	Integer);
	    columnWidthID:		(firstWidthCol:	Integer;
				 colsWidths:	ARRAY [1..1] OF Byte);
	    rowHeightID:		(firstHeightRow:	Integer;
				 rowsHeights:	ARRAY [1..1] OF Byte);
	    defaultFieldPropsID:	(bytesPerProp:	Byte;
				 defaultColWidth:	Byte;
				 defaultProps:	Byte);
	    columnFieldPropsID:	(firstPropsCol:	Integer;
				 columnProps:	ARRAY [1..1] OF Byte);
	    rowFieldPropsID:	(firstPropsRow:	Integer;
				 rowProps:		ARRAY [1..1] OF Byte);
	    cellFieldPropsID:	(firstCellCol:	Integer;
				 cellRow:		Integer;
				 cellProps:	ARRAY [1..1] OF Byte);
	 END;

	GeneralRecord = RECORD
	  headerByte:	Byte;
	  CASE Integer OF
	    0FFh: ( textString:   ARRAY [1..2] OF Char ); { ends with CRLF }  
	    0FEh: ( commonProps:  CommonPropertiesRecord );
	    0FDh: ( userLength:  Word; userProps:  ARRAY [1..1] OF Byte );
	    000h: ( length: Word; binaryProps: Byte)
	  END;

	GeneralRecordPointer = ^GeneralRecord;


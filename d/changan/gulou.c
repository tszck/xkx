// /d/changan/gulou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "鼓樓");
	set  ("long",  @LONG
鼓樓建於明洪武一十三年。青條石爲基，青磚爲樓，穩重厚實。門
樓內安放大鼓一張，相傳當年天子在此擊鼓點將，連洛陽都能聽到。樓
前檐下懸掛藍底金字木匾(bian)，和城中心的鐘樓遙相呼應。
LONG);
	set("item_desc",  ([
		"bian"  : " 
        ********************************************
        *            文武盛地    聲聞於天          *
        ********************************************
\n"
	]));
	set("exits",  ([  //sizeof()  ==  4
		"south"  :  __DIR__"westroad2",
	]));
	set("outdoors",  "changan");
	setup();
	replace_program(ROOM);
}


// /d/changan/dongyuemiao.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "東嶽廟");
	set  ("long",  @LONG
東嶽就是泰山，歷代天子認爲山高有靈，因此建廟祭祀。此廟建於
北宋政和六年。大殿宏偉壯觀，東西殿牆上畫着不少樓閣仕女，遠非普
通宗教題材之壁畫可比，頗有元明氣韻。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northwest" :  __DIR__"zaoxiang",
	]));
	set("no_clean_up",  0);
	setup();
	replace_program(ROOM);
}


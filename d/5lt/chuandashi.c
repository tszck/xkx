// Room: /d/5lt/chuandashi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "傳達室");
	set  ("long",  @LONG
這裏是村支部的傳達室。你埋頭加快腳步剛從門口走過，卻瞥見傳
達室的大爺正望着你，目光炯炯，十分警惕。
LONG);
	set("exits",  ([  //sizeof()  ==  3
		"north"  :  __DIR__"yuelanshi",
		"west"   :  __DIR__"czoffice",
		"east"   :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

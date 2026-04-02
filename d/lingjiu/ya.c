//room: ya.c
inherit ROOM;

void create()
{
	set("short","斷魂崖");
	set("long",@LONG
這是通向靈鷲宮的必經之路，一條小道蜿蜒曲折地通向縹緲峯頂。
路的右側是一條陡峭的山崖，一陣山風吹過，你似乎聽見從下面傳來幾
聲慘號，你心中一凜，不禁加快腳步趕緊離開這裏。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"westup"   : __DIR__"yan",
		"eastdown" : __DIR__"shanjiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
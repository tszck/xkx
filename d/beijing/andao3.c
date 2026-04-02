// /d/beijing/andao3.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地會暗道");
	set("long", @LONG
一走進黑漆漆的地道，陣陣陰風從南邊吹來，你感到有些冷。兩邊
都是土牆，隱約可以聽到上面腳底落地的聲音。
LONG );
	set("exits", ([
		"north" : __DIR__"andao1",
		"south" : __DIR__"andao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}

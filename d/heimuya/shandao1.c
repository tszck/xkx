// Room: /d/heimuya/shandao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "山道");
	set("long", @LONG
西面是一座高山，地勢極之險峻，一條窄小陡峭的山道蜿蜒盤往山
上，東邊山腳是一片長灘。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"changtan",
	    "westup"   : __DIR__"shandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", 4200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
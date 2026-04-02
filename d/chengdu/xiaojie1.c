// Room: /d/chengdu/xiaojie1.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小街");
	set("long", @LONG
這是一條青石板鋪成的小街，路面非常乾淨。朝北邊看，天氣好的
話，還可以隱約看到風雨亭的一角。東邊有個糉子店。
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"east"      : __DIR__"zongzidian",
		"southeast" : __DIR__"xiaojie2",
		"northwest" : __DIR__"xiaojie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


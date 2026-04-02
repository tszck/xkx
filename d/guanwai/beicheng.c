// /guanwai/beicheng.c

inherit ROOM;

void create()
{
	set("short", "北城");
	set("long", @LONG
這裏是用黃土鋪就的街道，街上的行人不多，看起來很冷清。偶爾
有幾個身着異域服飾的行人走過，看起來是滿族，鮮祖的居民。西面有
一條幽深的小巷，不知通向何處。
LONG );
	set("exits", ([
		"south" : __DIR__"jishi",
		"west"  : __DIR__"xiaoxiang",
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6040);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
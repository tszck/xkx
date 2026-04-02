// Room: /d/baituo/datiepu.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "打鐵鋪");
	set("long", @LONG
這裏是一家打鐵鋪，鐵匠忙着打製鐵製兵器，賣給江湖俠客。
LONG	);
	set("exits", ([
		"north" : __DIR__"dongjie",
	]));
	set("objects",([
		__DIR__"npc/smith" : 1,
	]));
	set("coor/x", -49980);
	set("coor/y", 19970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

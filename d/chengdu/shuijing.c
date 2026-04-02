// Room: /d/chengdu/shuijing.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "水井");
	set("long", @LONG
有一眼清澈見底的水井，井旁搭着小土房。有幾個婦人在這裏邊洗
衣，一邊說說笑笑，還有個老人，挑着溜滿的兩桶清水，顫顫悠悠地朝
外走去。你可以在這喝口水。
LONG	);
	set("resource/water", 1);
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"dongjie3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


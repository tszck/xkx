// Room: /yangzhou/sixiepu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","李家絲鞋鋪");
	set("long",@LONG
李家做的絲鞋，以「舒適合腳，輕便耐穿」而著稱。鋪內陳列着一
雙特大個的白絲鞋，看來只有巨靈神才穿的下。櫃檯上放着幾雙絲鞋，
邊上的鞋架上放着皮靴、皁靴等各式鞋樣，可供客人試穿，以便挑選到
自己喜歡的合適的鞋。
LONG );
	set("exits", ([
		"south" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/libailv" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
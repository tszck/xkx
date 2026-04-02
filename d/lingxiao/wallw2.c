// Room: /d/lingxiao/wallw2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城頭");
	set("long", @LONG 
高處不勝寒。不只是雪，連霜也紛紛而下。頭天晚上還是石城木垛，
一下子就霜雪漫天，萬物俱白。古詩云“天涯霜雪霽寒霄”。大概也就
是這個意思吧。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"wallw3",
		"east" : __DIR__"wallw1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31020);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup(); 
	replace_program(ROOM);
}


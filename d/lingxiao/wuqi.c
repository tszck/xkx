// Room: /d/lingxiao/wuqi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "刀劍鋪");
	set("long", @LONG
這就是凌霄城的刀劍鋪。走進這裏，寒氣侵體，好象比外面還要冷。
仔細一看，牆上掛滿了大大小小、形形色色的刀劍，一柄柄寒光閃閃，
全是上品。店主軒轅蒼翼看到有人進來，立刻殷勤地迎上前來。
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad2",
	]));
	set("objects", ([
		__DIR__"npc/xuanyuan": 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	set("coor/x", -31010);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


// wg_wuchang4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南練武場");
	set("long", @LONG
這是露天練武場，好多人在這裏辛苦的練着，你走在場中，沒有人
回頭看你一眼，都在聚精匯神的練着自己的功夫，地上放着幾個練功用
具。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_lang4",
		"west" : __DIR__"wg_wuchang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_daotong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 21);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
}


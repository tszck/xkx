// Room: /d/nanshaolin/lwc.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。十來個僧人正在練習武技。
南北西三面各有一練武場。
LONG );
	set("exits", ([
		"east"  : __DIR__"lhtang",
		"west"  : __DIR__"lwc5",
		"north" : __DIR__"lwc2",
		"south" : __DIR__"lwc9",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


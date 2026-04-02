// Room: /d/nanshaolin/lwc8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。十來個僧人正在練習武技。
東西北三面各有一練武場。
LONG );
	set("exits", ([
		"north" : __DIR__"lwc5",
		"east" : __DIR__"lwc9",
		"west" : __DIR__"lwc7",
	]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1780);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


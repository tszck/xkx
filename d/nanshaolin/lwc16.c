// Room: /d/nanshaolin/lwc16.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。十來個僧人正在練習武技。
南北東三面各有一個練武場。西面是研習武功用的羅漢九部。
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc15",
                "west"  : __DIR__"brtang",
		"north" : __DIR__"lwc14",
		"south" : __DIR__"lwc17",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


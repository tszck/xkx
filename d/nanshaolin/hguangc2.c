// Room: /d/nanshaolin/hguangc2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "後殿廣場");
	set("long", @LONG
這裏是後殿廣場，由大青石板拼成的地面上有幾處凹凸的踏痕，似
是以前有高手施展內功所遺留的印記。南面通往大悲殿。
LONG );
	set("outdoors", "nanshaolin");
	set("no_fight", 1);
	set("exits", ([
		"east"  : __DIR__ "hguangc3",
		"west"  : __DIR__ "hguangc1",
		"south" : __DIR__ "dabeidian",
        ]));
        set("objects",([
//		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

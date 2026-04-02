// Room: /d/nanshaolin/hguangc5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "後殿廣場");
	set("long", @LONG
這裏是後殿廣場，由整塊大青石板拼成的地面上有幾處凹凸的踏痕，
似是以前有高手施展內功所遺留的印記。西面是後殿。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west" : __DIR__ "houdian",
		"south" : __DIR__ "hguangc3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


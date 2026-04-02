// Room: /d/tiezhang/road2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "黃土路");
	set("long", @LONG
你走在一條塵土飛揚的黃土路上，兩旁是陰森森的樹林。這裏是川
湘交界，據説經常有土匪出沒，不可久留。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"      : __DIR__"road3",
		"northeast" : __DIR__"road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2020);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
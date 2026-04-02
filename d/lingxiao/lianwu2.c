// Room: /d/lingxiao/lianwu2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "練武廳");
	set("long", @LONG
這裏是凌霄城的練武場。只見刀光劍影，目不暇接，一羣凌霄弟子
練得大汗淋漓，彼此打得難解難分。凌霄城裏派系不和，彼此間明爭暗
鬥，門下弟子也只得努力練功，以防不測。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"fudian2",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 4,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


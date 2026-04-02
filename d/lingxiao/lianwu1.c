// Room: /d/lingxiao/lianwu1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "練武廳");
	set("long", @LONG
這裏是凌霄城的練武場。場上放着幾個木人，是供凌霄弟子練功之
用。幾個凌霄弟子手持長劍，你來我往，正在場上練的起勁。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"fudian1",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -31020);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


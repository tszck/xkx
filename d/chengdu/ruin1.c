// Room: /d/chengdu/ruyin1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "破舊大宅");
	set("long", @LONG
這裏是一間破舊大宅的前院，大廳已經崩塌了一半，焦黑的樑柱擋
住了你的去路，庭院裏雜草叢生，看來已經很久沒有人住了，據說這裏
晚上有鬼魂出現，但是倒也從沒聽說過有人被害，因此附近的居民仍然
照常生活。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"cai",
		"west"  : __DIR__"ruin2",
		"north" : "/d/npc/m_weapon/lianbangshi",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 3,
	]));
	set("coor/x", -8070);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


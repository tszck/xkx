// Room: /d/nanshaolin/gchang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "廣場西側");
	set("long", @LONG
這裏是天王殿前的一個廣場。廣場正中放着個二人高的青銅大香爐，
前面擺着個香臺，幾位香客正在虔誠謨拜。自此向左有一間偏殿，供比
丘們打坐誦經之用。北面有一個長廊，通向天王殿後。
LONG );

	set("exits", ([
		"east"  : __DIR__"gchang-1",
		"west"  : __DIR__"cdian-2",
		"north" : __DIR__"celang-1",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


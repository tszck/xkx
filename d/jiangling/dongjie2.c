//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "東街");
	set("long", @LONG
這是荊州城東的一條小街。雖然這裏沒有西街繁華，近日卻也頗有
些江湖人物來去匆匆。西邊是一堵高高的圍牆，東邊是一個茶館。
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dongmen",
		"north" : __DIR__"dongjie1",
	]));
	set("objects", ([
		__DIR__"npc/langzhong": 1,
	]));

	set("coor/x", -1470);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
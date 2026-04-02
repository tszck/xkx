inherit ROOM;

void create()
{
	set("short", "馬棚");
	set("long", @LONG
這裏是康親王府的馬棚，其中好馬無數。剛一進門，馬兒就衝你“
恢恢”直叫。
LONG );
	set("exits", ([
		"west" : __DIR__"kang3",
	]));
	set("objects", ([
		__DIR__"npc/yucongma" : 1,
	]));
	set("coor/x", -179);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

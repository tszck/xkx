inherit ROOM;

void create()
{
	set("short", "橋底東側");
	set("long", @LONG
這裏是小橋西側，一股寒風吹過，冷得你瑟瑟發抖，只想離開。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"bridge",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

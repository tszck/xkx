// Room: /beijing/xichang2.c

inherit ROOM;

void create()
{
	set("short", "西長安街");
	set("long", @LONG
你走在街上，感到這裏的街面要比別處的乾淨、整潔。再往西就是
西城門，直通往郊外。東邊是空蕩蕩的街道。南邊是一條行人稀少的小
巷，北邊通往西單。
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xichang1",
		"west"  : __DIR__"ximen",
		"south" : __DIR__"alley1",
		"north" : __DIR__"xidan",
	]));
	set("coor/x", -220);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

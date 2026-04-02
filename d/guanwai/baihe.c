// /guanwai/baihe.c

inherit ROOM;

void create()
{
	set("short", "白河");
	set("long", @LONG
這裏是長白山下的一個小村，只有四，五間粗陋的小木屋。這裏並
沒有固定的居民，木屋都是進山採參的參客所蓋，爲的是在進山前能在
這裏好好的休息一下。東面就是巍峨聳立的長白大山。
LONG );
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6140);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

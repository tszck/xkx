// /kaifeng/dadao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "三叉路口");
	set ("long", @LONG
道路至此分爲三路，一條路向北就是開封城，東南面是座樹林。林
中隱有條小道穿過。西南面的路通向野豬林。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"dadao0",
		"southwest" : __DIR__"dadao2",
		"southeast" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}

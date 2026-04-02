inherit ROOM;

void create()
{
	set("short", "打鐵鋪");
	set("long", @LONG
這是一家簡陋的打鐵鋪，中心擺着一個火爐，爐火把四周照得一片
通紅，你一走進去就感到渾身火熱。牆角堆滿了已完工和未完工的菜刀、
鐵錘、鐵棍、匕首、盔甲等物。一位鐵匠滿頭大汗揮舞着鐵錘，專心致
志地在打鐵。
LONG );
	set("exits", ([
		"north" : __DIR__"dongcha2",
	]));
        set("objects", ([
                 __DIR__"npc/smith": 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

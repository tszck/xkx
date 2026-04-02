// Room: /d/5lt/datiepu.c

inherit ROOM;

void create()
{
	set("short", "打鐵鋪");
	set("long", @LONG
這是一家簡陋的打鐵鋪，中心擺着一個火爐，爐火把四周照得一片
通紅，你一走進去，就感到渾身火熱。牆角堆滿了已完工和未完工的菜
刀、鐵錘、鐵棍、匕首、盔甲等物。一位鐵匠滿頭大汗揮舞着鐵錘，專
心致志地在打鐵。
LONG );
	set("exits", ([
		"east" : __DIR__"sroad3",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
	set("coor/x", -160);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
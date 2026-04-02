// ROOM lianzhangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "杖場");
	set("long", @LONG
這裏是玄兵古洞的造杖的地方。四周道也不是十分荒涼，相反還可
説有幾分景緻。露天放着一個巨大的爐子，冒着蓬蓬的藍炎，似乎什麼
都能被它融化似的。
LONG );
	set("exits", ([
		"eastup" : "/d/baituo/xiaolu4",
	]));
	set("objects", ([
		__DIR__"npc/shizhang" :1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

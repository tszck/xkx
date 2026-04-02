inherit ROOM;

void create()
{
	set("short", "屠宰場");
	set("long", @LONG
這裏是屠宰場，空氣中瀰漫着豬的氣味。偶爾一陣熱風吹過，頓時
一股臭氣襲來，直燻得人作嘔。一箇中年人手握屠刀，指揮着夥計們殺
豬去毛。這就是京城最大的屠宰場，據說宮裏所有的豬肉都是從這裏送
去的。
LONG );
	set("exits", ([
		"east" : __DIR__"nandaj2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/lilishi": 1,
		__DIR__"npc/huoji1": 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

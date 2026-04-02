inherit ROOM;

void create()
{
	set("short", "東長安街");
	set("long", @LONG
這裏是東長安街，寬闊的街道上車水馬龍，人來人往。向西走就是
天安門了。北邊是京城最有名的“怡紅院”，達官顯貴、宮廷侍衛都愛
去。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"dongcha2",
		"west" : __DIR__"tian_anm",
		"north" : __DIR__"yihongyu",
		"south" : __DIR__"fuweibiaoju",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/qin" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

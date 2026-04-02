//room: /d/baituo/liangong.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","練功場");
	set("long", @LONG
這裏是白駝山弟子的練功場。東邊是一個練功房。北邊是個門廊，
西邊連着一條長廊，雕樑畫柱，非常氣派。南面可見巍巍大廳。
LONG	);
	set("exits",([
		"east" : __DIR__"fang",
		"north" : __DIR__"menlang",
		"west" : __DIR__"changlang",
		"south" : __DIR__"dating",
	]));
	set("objects",([
		CLASS_D("baituo")+"/li" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -50010);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}


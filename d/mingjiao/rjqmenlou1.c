//RJQMENLOU1.C

inherit ROOM;

void create()
{
	set("short", "門樓一層");
	set("long", @LONG
這裏是一間大石室，石室四周整齊的碼置着兵器架，十八般兵器樣
樣俱全。幾個教衆在室中巡邏，好象是守護兵器的。右面有一條石梯直
通樓上。
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou2",
		"east" : __DIR__"rjqyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
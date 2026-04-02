// Room: /d/baituo/guangchang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裏是一塊不小的廣場，上面堆着農家曬的穀物。北上是『白駝山
莊』。東面有間小農舍，西邊有塊菜地，東南方是一座小橋。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"east"      : __DIR__"nongshe",
		"northup"   : __DIR__"shijie",
		"northwest" : __DIR__"shanlu",
		"southeast" : __DIR__"bridge",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

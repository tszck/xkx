//ROOM: caifeng.c

inherit ROOM;

void create()
{
	set("short", "瀟湘館");
	set("long",@LONG
這是『靈鷲宮』的裁縫室。幾個女子圍坐在一塊，飛針走線，苦練
女紅，難道她們是爲了以後找一個好婆家嗎？ 
LONG );
	set("exits", ([
		"south" : __DIR__"changl10",
	]));
	set("objects",([
		__DIR__"npc/fumy" : 1,
	]));
	set("coor/x", -50980);
	set("coor/y", 30170);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
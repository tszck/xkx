// Room: /d/baituo/shanlu1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
這裏是山上的泥路。四周是一眼望不盡的叢林。這裏地處西域，天
候乾燥，山風颳來，一片片的樹林左右搖擺。
LONG);
	set("exits",([
		"north" : __DIR__"shulin",
		"southeast" : __DIR__"shanlu",
	]));
	set("outdoors", "baituo");
	set("objects" ,([
		__DIR__"npc/qiaofu" : 1 ,
	]) );
	set("coor/x", -50030);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/baituo/shoushe.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","獸舍");
	set("long", @LONG
這裏是白駝山莊的獸舍。白駝山馭獸術天下知名，這裏也豢養了各
種猛獸，以供下山的白駝弟子使用。獸舍裏猛獸長聲嘶嚎，老遠都聽得
見。尤其是夜晚聽來，更有是撕心裂肺的慘烈。
LONG );
	set("exits",([
		"east"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/fox" :1,
		__DIR__"npc/wolf" :1,
		__DIR__"npc/tiger" :1,
		__DIR__"npc/lion" :1,
	]));
	set("coor/x", -50010);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

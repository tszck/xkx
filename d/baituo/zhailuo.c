// Room: /d/baituo/zhailuo.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","小宅落");
	set("long", @LONG
這裏是一個樹影婆娑的靜謐的小宅落，當中放着一口烏黑髮亮的大
水缸。白駝山上常年積雪，這裏的主人架起一條長長的竹渠，把清涼的
雪水引到家中的水缸裏來。
LONG	);
	set("exits",([
		"east" : __DIR__"tangwu",
	]));
	set("objects",([
		__DIR__"npc/jiren": 1,
		__DIR__"npc/jiren1": 1,
	]));
	set("outdoors", "baituo");
	set("resource/water", 1); 
	set("coor/x", -50020);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




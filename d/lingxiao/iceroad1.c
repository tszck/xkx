// Room: /d/lingxiao/iceroad1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰道");
	set("long",@LONG
這裏是一片冰雕玉砌的世界。走在路上，低頭一看，路面是用萬載
不化的寒冰所制，晶瑩剔透，足可映物，照理說走在這樣的冰上，應該
滑溜不堪，但仔細一看，每處冰道上，都雕有細細的花紋，而且做工精
細，顯然耗費了大量人力。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"gate",
		"north" : __DIR__"iceroad2",
		"west"  : __DIR__"hotel",
		"east"  : __DIR__"sell",
	]));
	set("objects",([
		__DIR__"npc/li" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


//Roon: lianpath1.c 蓮花峯小路
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","蓮花峯小路");
	set("long",@LONG
小路通往蓮花峯，周圍靜靜悄悄，微聞蟬鳴。四望密林幽谷，讓人膽
寒。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"westup"   : __DIR__"lianpath2",
		"northeast": __DIR__"zhenyue",
	]));
	set("objects",([ 
		__DIR__"npc/ying-bailuo" : 1,
	]));
	set("coor/x", -880);
	set("coor/y", 180);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}

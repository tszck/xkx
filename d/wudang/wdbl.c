//Room: wdbl.c 武當柏林
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","武當柏林");
	set("long",@LONG
你穿行在一片茂密的柏林中，陰森鬱翠，怪石嶙峋，草深沒人。林
子裏時而傳出丁丁冬冬的伐木聲響，不時地驚起兔子從你的身邊飛跑而
過。
LONG);
	set("objects", ([
		__DIR__"npc/yetu" : 2,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"yuzhengong",
		"southup"  : __DIR__"haohanpo",
		"west"     : __DIR__"wdbl1",
		"east"     : __DIR__"wdbl2",
	]));
	set("coor/x", -2050);
	set("coor/y", -830);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

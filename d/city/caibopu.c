// Room: /yangzhou/caibopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","顧家彩帛鋪");
	set("long",@LONG
進入彩帛鋪中，只見店內擁擠不堪，數個小二在招呼客人，依舊應
接不暇。店內兩邊各有幾個貨架，上面陳列着布匹綢緞。幾個客商正在
挑選，邊上的店員在給他們介紹。幾個姑娘手裏拿着一匹花布，在身上
比劃着，嘰嘰喳喳的相互說着，不大理會邊上嬉皮笑臉的店員。
LONG );
	set("exits", ([
		"south" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/gubancheng" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
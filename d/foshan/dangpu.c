//Room: /d/foshan/dangpu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄典當");
	set("long",@LONG
當鋪裏一張高高的櫃檯，櫃檯後面坐着當鋪的朝奉。這家當鋪
是鳳老爺所開，十多年來從沒人來鬧過事，朝奉也就很放心。櫃檯
上掛着一個木牌子(paizi)。
LONG);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "公平交易\n
	sell        賣 
	buy         買
	value       估價
",
	]));
	set("objects", ([
	   __DIR__"npc/chaofeng": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street5",
	]));
	set("coor/x", -1290);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

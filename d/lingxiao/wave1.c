// Room: /d/lingxiao/wave1.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","冰洞");
	set("long",@LONG 
這是一個巨大的天然冰洞。做夢也沒想到，這溫泉水潭下，竟然有
這樣一個天造地設的洞天福地。站在這裏，彷彿置身於水晶寶庫一般，
四周全是晶瑩剔透的冰塊，四面八方都是自己的倒影，清可鑑發。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"up"   : __DIR__"water", 
		"west" : __DIR__"wave2", 
	]));
	if(random(6)>3)
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

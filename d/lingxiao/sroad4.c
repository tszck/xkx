// Room: /d/lingxiao/sroad4.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","天風川");
	set("long",@LONG
你正站在一塊晶瑩剔透的萬年冰川之上，只覺腳部不斷傳來一陣透
骨的冰涼。雪山上北風怒號，萬裏愁雲淡霧籠罩雪域，四周一片蒼茫，
已經看不見半點生命跡象了。片片雪花從空中鵝毛般飛撒而下。足底溜
滑，道路更是難於辨認。可謂“雪道難，難於上青天”。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"shiya",
		"northup"   : __DIR__"sroad5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8970);
	set("coor/z", 100);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" || dir == "southdown")
	{
		me->recieve_damage("jing", 30);
		me->recieve_damage("qi", 30);
	}
	return 1;
}

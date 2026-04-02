// Room: /d/lingxiao/sroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
山行崎嶇，這裏已是雪山之上，朔風飛揚，黃雲蓋天。愈上愈高，
山勢也愈來愈險，俯覽羣山，片片浮白，在雲氣瀰漫之下，恍如雲海中
星羅棋佈的島嶼。這時已是正午時分，但寒氣卻愈來愈濃。四周白茫茫
的一片，惟有無邊飛雪，紛紛揚揚從空中撒將下來。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"sroad2",
		"eastup"    : __DIR__"shiya",
	]));
	set("objects", ([
		__DIR__"npc/huyan" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8980);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}


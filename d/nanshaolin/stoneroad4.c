// Room: /d/nanshaolin/stoneroad4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long",@LONG
一條平整寬闊的石路，路邊是兩長溜僧棚，可供大家休息之用。香
客們手執線香，緩步通過。一些忙碌的僧侶，急匆匆的奔馳而去，似乎
有什麼要事在身。一隊護寺僧兵手執戒刀，正自來往巡視。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"west"  : __DIR__"lhtang",
		"east"  : __DIR__"stoneroad2", 	  
		"north" : __DIR__"celang1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


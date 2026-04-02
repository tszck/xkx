// Room: /d/heimuya/linjxd6.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","林間小道");
	set("long", @LONG
你走在一條陰暗的林間小道上，兩旁是陰森森的樹林。一陣陣風吹
過樹梢，發出沙沙的響聲，令你不寒而慄。
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"south" : __DIR__"linjxd1",
		"north" : __DIR__"linjxd4",     
		"east"  : __DIR__"linjxd3",
		"west"  : __DIR__"dating2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/heimuya/linjxd1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","林間小道");
	set("long", @LONG
你走在一條陰暗的林間小道上，兩旁是陰森森的樹林。一陣陣風吹
過樹梢，發出沙沙的響聲，令你不寒而慄。不過西邊好象是一個山谷。 
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"south" : __DIR__"linjxd2",
		"north" : __DIR__"linjxd5",     
		"east"  : __DIR__"road1",
		"west"  : __DIR__"guang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
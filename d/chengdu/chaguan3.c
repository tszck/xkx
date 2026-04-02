// Room: /d/chengdu/chaguan3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "望風茶館");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神爲之一爽。幾張八仙
桌一字排開，坐滿了客人，或高聲談笑，或交頭接耳，只聽見全是些操
着川話的市俗之徒。你要若想打聽江湖掌故和謠言，這裏是個好所在。
需要些茶水和點心可在些小坐。
LONG	);
	set("no_fight",1);
	set("exits", ([
		"north" : __DIR__"dongjie3",
	]));
	set("objects", ([
		__DIR__"npc/boss1" : 1,
	]));
	set("coor/x", -8020);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


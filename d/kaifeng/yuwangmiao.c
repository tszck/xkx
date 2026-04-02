// /kaifeng/yuwangmiao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "禹王廟");
	set("long", @LONG
禹王廟爲追念大禹治水功德，在吹臺上建造，廟內的大禹神像端身
平坐，一手握着把鐵鍬，目注遠方，來人多是祈求莫發大水的，西下過
去就是片樹林。
LONG);
	set("objects", ([
		__DIR__"npc/obj/dayu" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"yuwang",
	]));

	setup();
	replace_program(ROOM);
}

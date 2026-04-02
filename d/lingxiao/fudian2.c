// Room: /d/lingxiao/fudian2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","副殿");
	set("long",@LONG
這裏是凌霄城的副殿之一。幾個凌霄弟子正在一起，賊頭賊腦地不
知在幹什麼，鬼鬼祟祟的，準沒什麼好事。最近凌霄城裏不太平，麻煩
事情也挺多的，還是少理爲妙。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"lianwu2",
		"west" : __DIR__"dadian",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


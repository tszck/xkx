// Room: /d/chengdu/xuetao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "薛濤井");
	set("long", @LONG
這裏是一代女詩人薛濤埋香之所，四周竹林環繞，靜悄悄的連自己
的腳步聲都聽得到，你的面前有口古井，上面長滿了青苔，看起來已經
很久沒人來過了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wanliqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}




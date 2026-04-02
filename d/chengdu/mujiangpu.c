// Room: /d/chengdu/mujiangpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
void create()
{
	set("short", "木匠鋪");
	set("long", @LONG
這是一家簡陋的木匠鋪，一箇中年木匠正蹲在地上釘東西。值此亂
世，木匠們也只好製作些刀槍棍棒什麼的以養家餬口。地上和牆角凌亂
地堆放着一些木劍，木刀，木棍什麼的，還有幾件象鋸子，刨子一類的
木匠工具。
LONG	);
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie2",
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


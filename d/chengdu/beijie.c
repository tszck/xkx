// Room: /d/chengdu/beijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
這條街上雙人合抱的梧桐十步一株，整整齊齊，青石鋪就的路面打
掃得乾乾淨淨。東邊是個珠寶鋪，西邊則是聞名天下的武威鏢局。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"zhubaopu",
		"west"  : __DIR__"biaoju",
		"south" : __DIR__"beijie1",
		"north" : __DIR__"northgate",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


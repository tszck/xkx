//ROOM: /d/yanziwu/shuwu.c

inherit ROOM;

void create()
{
	set("short", "翰墨書屋");
	set("long",@LONG
屋中一架架紫竹搭成的書架倚牆而立，書架上擺滿了經史典籍。屋
子正中央是一張書桌，桌上琴棋俱備，筆墨紙硯一應俱全，牆上掛着一
幅條幅(tiaofu)。大名鼎鼎的慕容公子常在這裏讀書寫字。
LONG );
	set("exits", ([
		"east" : __DIR__"lanyue",
		"north": __DIR__"canheju",
		"south": __DIR__"shangyu",
	]));

	set("item_desc",([
		"tiaofu" : "
	       光灑菱湖天欲晚，
	       復國無計隱寒潭。
	       大夢未覺身已老，
	       燕語聲中空笑談。\n\n\n ",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1550);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
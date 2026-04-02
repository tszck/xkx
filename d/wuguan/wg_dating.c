// wg_dating.c

inherit ROOM;

void create()
{
	set("short", "武館大廳");
	set("long", @LONG
這裏是武館大廳，正中靠北擺着一張八仙桌，桌上供着關公的神位，
旁邊放着兩個青瓷花瓶，插着幾支孔雀翎，牆上寫着大大的一個“武”
字武館主人早些年在江湖上闖蕩，現今洗手隱退，在揚州開起了這間武
館，往東走是個長廊，一直通向館主的臥室。
LONG);
	set("exits", ([
		"enter"     : __DIR__"wg_lang5",
		"westdown"  : __DIR__"wg_dayuan2",
		"northdown" : __DIR__"wg_shilu-2",
		"southdown" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_chen" : 1,
	]));
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
	"/clone/board/wuguan_b"->foo();
}



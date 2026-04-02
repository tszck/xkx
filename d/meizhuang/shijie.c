// /d/meizhuang/shijie.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "孤山石階");
	set("long", @LONG
你向孤山邊的石階上行去，一路欣賞着湖邊長曳的楊柳。不知不覺
地轉了幾個彎，卻見遍地都是梅樹，老幹橫斜，枝葉茂密，想像初春梅
花盛開之日，香雪如海，定然觀賞不盡。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : "/d/hangzhou/gushan",
		"north"	   : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

// Room: /d/chengdu/wanliqiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "萬裏橋");
	set("long", @LONG
這裏便是萬裏橋了，此橋的得名來至一句“千里之行始於足下”，
據說當時的詩人便是在此吟出此句的。橋很寬，兩邊是漢白玉的欄杆，
扶手上雕着獅子頭，數一數有三十六頭之多。橋下便是南河，水流清澈
見底，一羣小孩在水中嬉戲打鬧。
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wangjianglou1",
		"east" : __DIR__"xuetao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}




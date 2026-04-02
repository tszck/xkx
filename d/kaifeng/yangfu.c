// /kaifeng/yangfu.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "天波楊府");
	set("long", @LONG
天波楊府是抗遼名將楊業的府邸，自從楊業去世之後，府中只剩下
一些女子居住。門前的綠柳槐樹旁，兩塊大石光滑異常，乃是當朝所賜。
文官過者下橋，武官過者下馬。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"road3",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}

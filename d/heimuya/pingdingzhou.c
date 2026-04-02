// Room: /d/heimuya/pingdingzhou.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "平定州");
	set("long", @LONG
平定州在河北境內，州府不大，但地處要衝，十分重要。往來京城
的客商穿梭頻繁。但在大街上，日月教徒橫衝直撞，出手抓人，雖近在
京畿，卻絲毫沒將官府放在眼裏。
LONG );
	set("exits", ([
		"east" : __DIR__"road3",
		"west" : __DIR__"road2",
	]));
	set("outdoors", "huabei");
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
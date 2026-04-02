// Room: /d/suzhou/hehuating.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "荷花廳");
	set("long", @LONG
荷花廳的主建築面闊三間，寬敝高爽，廳名取宋時朱熹：“一水方
涵碧，千林以變紅”之詩意。廳前寬廣的平臺依臨荷池，爲夏日賞荷納
涼勝處，故稱“荷花廳”。廳後有花臺庭院，疊石種樹，自成一景。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"liuyuan",
		"west"  : __DIR__"gumujiaohe",
	]));
	set("coor/x", 830);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// husun.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "猢猻愁");
	set("long", @LONG
前面又是一處十分陡峭的山嶺，上面有四隻鐵猿，盤踞臺畔，據說
以前從華山水簾洞出來的猿猴，每到這裏就要返回去，連它們也感到難
於超越，此嶺因而得名。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"laojun",
		"southup"   : __DIR__"shangtianti",
	]));
	set("objects", ([ /* sizeof() == 2 */
		"/d/wudang/npc/monkey": 1,
		"/d/wudang/npc/little_monkey": 2,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -870);
	set("coor/y", 220);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
 

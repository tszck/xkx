// Room: /d/heimuya/shidao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "石道");
	set("long", @LONG
一路往北行，中間僅有一道寬約五尺的石道，兩邊石壁如牆，一路
上都有日月教徒模樣的人物在走動，對往來的路人都嚴密監視。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "east" : __DIR__"guang",
	    "north" : __DIR__"shidao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
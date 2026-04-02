// /guanwai/ermenkan.c

inherit ROOM;

void create()
{
	set("short", "二門坎子");
	set("long", @LONG
漫長的參路蜿蜒的消失在原處的天邊，路上依稀還留有一些淺淺的
足印，看來是前面的參客留下的。白茫茫的雪地反射出耀眼的銀光，看
得人頭昏眼花。偶爾有幾隻雪兔飛馳而過，轉眼就無影無蹤了。
LONG );
	set("exits", ([
		"east"       : __DIR__"mantianxing",
		"northwest"  : __DIR__"damenkan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6110);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
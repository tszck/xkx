// Room: /d/chengdu/gongqiao1.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "石拱橋");
	set("long",@LONG
這裏充分地顯示着天府之國那種獨特僅有的風格，園拱形的小橋橫
跨縱貫成都的府南河。橋下的流水被浮萍染成愛人的翠綠。偶爾一兩隻
輕舟劃過，帶動着河邊的蓮藕隨波而動。往北就是風雨亭。 
LONG
	);

	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xiaojie2",
		"north" : __DIR__"fengyuting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}



// Room: /d/heimuya/xiaohuayuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "小花園");
	set("long", @LONG
從昏暗的地道中出來，你發現自己竟是置身於一個極精緻的小花園
中，紅梅綠竹，青松翠柏，佈置得頗具匠心，往東去，是一間很精雅的
小舍。
LONG  );
	set("outdoors", "heimuya");
	set("exits", ([
		"south" : __DIR__"didao6",
		"enter" :__DIR__"xiaoshe",   
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
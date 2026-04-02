// Room: /city/luqiao.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "露橋");
	set("long", @LONG
橋的北頭，翼以二亭，名翠陰，名雪薌，半突於水面之上。橋的南
面，湖石山子巍然聳立，氣勢不同凡響。山頂構一亭，曰詩興，半掩於
聳峯之後，格外增加了山的層次感。當山峯倒影於水的時候，尤其使人
感覺到水之深和山之偉了。天上的雲，如同溶合在水裏；水裏的魚，好
似悠遊於天半。
LONG );
	set("exits", ([
		"northwest" : __DIR__"qinshi",
		"south"     : __DIR__"hushishandong",
		"southup"   : __DIR__"shixingting",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 3);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
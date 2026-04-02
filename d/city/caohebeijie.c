// Room: /yangzhou/caohebeijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河北街");
	set("long",@LONG
這是草河小街的盡頭了，北邊就是瘦西湖了。西邊是揚州府的府學
「資政書院」，西北邊是魁星閣。這裏遊人稀少，只有幾個書生匆匆而
過，府學的門口有幾個頑劣學童在嬉笑打鬧，給這寂靜的街道添了幾分
生氣。北邊是一個典當行，大概只有一些窮書生常光臨那裏。南邊是一
個小廣場。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"zizheng",
		"east"      : __DIR__"hongqiao",
		"south"     : __DIR__"xiaosquare",
		"north"     : __DIR__"diandanghang",
		"northwest" : __DIR__"kuixingge",
		"southwest" : __DIR__"petroom",
	]));
	set("objects", ([
		__DIR__"npc/qiuxingxing" : 1,
		__DIR__"npc/yangleishi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

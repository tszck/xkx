// Room: /d/chengdu/chaguan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "陸羽茶館");
	set("long", @LONG
這裏是成都最有名的茶樓，成都的達官顯貴非常喜歡來的一個地方。
因爲這裏環境舒適，而且往來的都是有身份有名氣的人，在這裏你可以
一邊品茗，一邊同高雅之士高談闊論。一樓是一般有錢人喝茶的地方，
二樓纔是那些真正有身份有文化的雅士飲茶的地方。
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"chunxilu1",
		"up" : __DIR__"chaguan2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



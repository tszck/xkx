// Room: /yangzhou/caiyijiekou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","綵衣街口");
	set("long",@LONG
一過小秦淮河，你便感到一種不同的氣氛。河的東岸是新城，多爲
商賈。你只見街口到處是店鋪，臨街而設，各自挑着高高的旗幟。小販
沿街叫賣，喧囂吵鬧。往北是天寧巷，通向天寧寺。往東就是綵衣街，
揚州的綢緞衣帽店大多在此。南面北柳巷是淮揚煙花之地。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"kaimingqiao",
		"east"  : __DIR__"caiyixijie",
		"north" : __DIR__"tianningxiang",
		"south" : __DIR__"beiliuxiang",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
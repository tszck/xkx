// Room: /yangzhou/kaimingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","開明橋");
    set("long",@LONG
拾級而上，步上開明橋頭。橋兩側圍以石欄，每塊石欄板雕刻着四
時花木，雕刻精緻，神形俱美。正處河心的石欄鑲着一匾額「開明橋」。
開明橋據說是揚州城裏最古老的橋，能在五代戰火之中倖存下來，揚州
的老人對開明橋多有感慨。下了東邊的石階，就是綵衣街口；西邊是瓊
花街，通向府學「崇雅書院」。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qionghuajie",
		"east"  : __DIR__"caiyijiekou",
	]));
	set("objects", ([
		"/d/village/npc/kid": random(4),
		"/d/village/npc/girl": random(3),
		"/d/village/npc/boy": random(3),
	]));
	set("coor/x", 30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
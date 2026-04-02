// Room: /d/chengdu/guangchang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "天府廣場");
	set("long", @LONG
這裏是成都的中心，佔地約三畝，綠色的草坪就象一塊大的地毯，
東西各有一棵老榕樹，已有上百歲了，看看它們，就知道成都的歷史是
相當悠久的。這裏來往的人很多，熙熙攘攘，摩肩接踵，有遊客、賣藝
人、閒人、小販、商人，吵鬧和吆喝聲不絕於耳，好一派熱鬧繁華的景
象。
LONG	);
	set("exits", ([
		"west"  : __DIR__"xijie2",
		"east"  : __DIR__"dongjie1",		
		"north" : __DIR__"beijie2",
		"south" : __DIR__"nanjie1",
	]));
	set("outdoors","chengdu");
	set("objects", ([
		__DIR__"npc/xiaolanyan" : 3,
		__DIR__"npc/laolanyan" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 

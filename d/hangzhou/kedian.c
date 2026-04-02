// kedian.c
// Date: Nov.1997 by Venus

inherit ROOM;

void create()
{
	set("short", "天外天");
	set("long", @LONG
這是杭州最有名的客店，裏面雕樑畫壁，裝飾有如宮殿，你可以在這裏
打聽到各地的風土人情。店小二裏裏外外忙得團團轉，接待着南腔北調的客
人。牆上掛着一個牌子(paizi)。
LONG);
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五兩白銀。\n",
	]));

	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"road13",
		"east" : __DIR__"majiu",
		"up"   : __DIR__"kedian2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 4160);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian7_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
     return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就住
旁人還以為小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
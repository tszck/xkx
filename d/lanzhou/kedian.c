// /d/lanzhou/kedian.c

inherit ROOM;

void create()
{
	set("short", "順風客棧");
	set("long", @LONG
這是一家價錢低廉的客棧，生意非常興隆。幾張桌字都坐滿了客人。
店小二裏裏外外忙得團團轉，接待着南腔北調的客人。牆上掛着一個牌
子(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五十兩白銀。\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"market",
		"up"    : __DIR__"kedian2",
	]));

	set("coor/x", -9280);
	set("coor/y", 2680);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian11_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
	return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就走了呢！
旁人還以為小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
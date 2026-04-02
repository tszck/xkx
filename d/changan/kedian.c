// /d/changan/kedian.c

inherit ROOM;

void create()
{
	set("short", "雲來客棧");
	set("long", @LONG
這是一家興隆的客棧，門口掛着塊匾，上書“客似雲來”。據説是
米芾的墨寶。店小二里裏一邊招呼客人，一邊大聲介紹米芾和客棧的淵
源，神色甚為得意。牆上掛着一個牌子(paizi),想來不是什麼墨寶，寫
的歪歪扭扭。
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
		"north" : __DIR__"majiu",
		"south" : __DIR__"westroad1",
		"up"    : __DIR__"kedian2",
	]));

	set("coor/x", -5060);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian10_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就走了呢！
旁人還以為小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

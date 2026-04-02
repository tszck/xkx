// Room: /chengdu/kedian.c
// Date: Feb.14.1998 by Java

inherit ROOM;

void create()
{
	set("short", "錦城驛");
	set("long", @LONG
錦城驛是全西南最大的客店，生意非常興隆。外地遊客多選擇這裏
落腳，你可以在這裏打聽到各地的風土人情。店小二裏裏外外忙得團團
轉，沉重的川味官話你是實在聽不順耳。這是成都督府官辦的客棧，接
待着各地入川的官差浪人。牆上掛着一個牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五十兩白銀。\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"up"    : __DIR__"kedian2",
		"south" : __DIR__"dongjie1",
		"north" : __DIR__"majiu",
	]));
	set("coor/x", -8040);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian3_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就走了呢！旁人還以為小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

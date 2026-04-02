// Room: /d/yueyang/jiudian.c 
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "牡丹樓");
	set("long", @LONG
呂洞賓三醉洞庭的故事無人不知，而白牡丹戲洞賓的傳說在這裏也
是人人皆曉。這裏就是當年白牡丹戲洞賓的所在。樓上是行商休息的地
方，樓下靠邊上，有一個櫃檯，櫃檯後有一個帳房先生正在撥着算盤珠
子，一邊還拿枝筆記着什麼。一個店小二看到你的到來，笑吟吟的迎上
前來。邊上的樓梯前掛着個告示(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五十兩白銀。\n"
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"kedian2",
		"west" : __DIR__"nanjie",
	]));

	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian18_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就走了呢！\n旁人還以爲小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

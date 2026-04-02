// Room: /d/tiezhang/kedian.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
這是一家價錢低廉的客棧，生意非常興隆。外地遊客多選擇這裏落
腳，你可以在這裏打聽到各地的風土人情。店小二裏裏外外忙得團團轉，
接待着南腔北調的客人。
LONG );
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五兩白銀。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"lx",
		"up"   : __DIR__"kedian2",
	]));
	set("coor/x", -2010);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian13_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("客官已經付了銀子，怎麼不住店就走了呢！
旁人還以爲小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

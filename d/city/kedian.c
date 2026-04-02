// Room: /yangzhou/kedian.c
// Last Modified by Winder on Jul. 15 2000
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"秦淮客寓"NOR);
	set("long", @LONG
這裏是秦淮客寓，過往揚州的客商大多在此歇腳。客寓內擺設很簡
單，邊上一個櫃檯，櫃檯後有一個帳房先生正在撥着算盤珠子，一邊還
拿枝筆記着什麼。一個店小二看到你的到來，笑吟吟的迎上前來。邊上
的樓梯前掛着個告示(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "樓上雅房，每夜五十兩白銀。\n"+
"本店出售，投標：bid；預付金：deposit；定價：setprice;狀態：status \n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/popo" : 1,
	]));
	set("exits", ([
		"up"    : __DIR__"kedian2",
		"east"  : __DIR__"majiu",
		"west"  : __DIR__"shilijie5",
		"north" : __DIR__"ganquanjie",
	]));

	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian_b"->foo();
	"clone/npc/xiang"->move(this_object());
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下擋在樓梯前，白眼一翻：怎麼着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && ( dir == "west" || dir == "north"))
	return notify_fail("店小二跑到門邊攔住：客官已經付了銀子，怎麼不住店就走了呢！
旁人還以爲小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
void init()
{
	object me=this_player();
	if (me->query("name")=="青雲" && me->query("id")!="qingyun")
	  me->set("name","我是豬頭");
}
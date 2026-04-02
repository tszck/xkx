// Room: /yangzhou/dixiashi.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set( "short", "地下室" );
	set( "long" , "這裏黑乎乎的，什麼也看不見。\n" );
	set( "exits", ([
		"up" : __DIR__"shufengguan",
	]));
	set("coor/x", -11);
	set("coor/y", -47);
	set("coor/z", -10);
	set("no_quest",1);
	setup();
}

void init()
{
	add_action( "do_use", "use" );
}

int do_use( string arg )
{
	object ob, me = this_player();

	if ( !me->can_act() ) return 0;
	if ( arg != "fire" ) return 0;
	if ( objectp ( ob = present( arg, me) ) )
	{
		write( "你取出懷裏的火摺子一晃，" );
		message_vision( "頓時你的眼前一亮。", me );
		set( "long", @LONG
這裏頗爲狹窄，卻很乾燥，中間放着一張桌子，上面放着一個小匣子。整個屋子裏就這
麼一點東西。
LONG
		);
/*
		本應該火摺子到一定時間就滅的，
		不過好象比較麻煩，考慮的情況太多，以後再說。
		remove_call_out( "no_fire" );
		call_out( "no_fire", 10, ob )
*/
		ob = new( __DIR__"obj/xiaoxiazi" );
		ob->move();
		return 1;
	}
	return 0;
}
// Room: /d/kunlun/bainiuling.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_wo(string arg);
int do_breathe();
void delete_done(object me);

void create()
{
	set("short", "白牛嶺");
	set("long",@long
這座山嶺因終年覆蓋白雪，且形狀遠望猶如一頭正在喫草的牛而得
名。這裏寒風呼嘯，凜冽刺骨，你不禁打了個寒顫。山頂有一處平地，
放有一塊青色的巨石(stone)。
long);
	set("exits",([
		"southwest" : __DIR__"fufengshan",
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"stone" :"這塊巨石很大，可以躺下一個人。表面十分平整光滑，似乎常有人摩挲。\n",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119970);
	set("coor/y", 40180);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_wo", "wo");
	add_action("do_breathe", "breathe");
}

int do_wo(string arg)
{
	if ( !arg || (arg != "stone") )
	return notify_fail("你要臥在什麼上面？\n");

	if (this_player()->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (this_player()->query_temp("marks/wo"))
		return notify_fail("你已經躺在青石上了。\n");

	this_player()->set_temp("marks/wo", 1);
	return notify_fail("你側身躺於青石上，意守丹田，口眼輕閉，雙腿自然微曲，全身放鬆。\n");
}

int do_breathe()
{
	object me=this_player();

	if( !me->query_temp("marks/wo") )
		return notify_fail("你深深吸了幾口氣，只覺得寒氣衝進五臟六腑，體內的真氣幾乎提不起來。\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if( me->query_temp("marks/done") )
		return notify_fail("寒風凜冽，你剛運過功，身子正十分虛弱，先好好休息一下吧。\n");

	if( me->query_skill("force", 1) < 51 )
		return notify_fail("你內功基底太弱，不可以隨意控制內息。\n");
		
	if( me->query_skill("force", 1) > 200 ) 	
                return notify_fail("你內功深厚，已經可以隨意控制內息。\n");
                
	message_vision("$N集聚體內真氣，深深吸進幾口氣，緩緩呼出，只覺得全身透徹清涼，心定似水，彷彿已物我渾然一體。\n", me);

	me->receive_damage("jing", random(30));
	me->receive_damage("qi",   random(30));
	me->improve_skill("force", (int)(me->query("int"))/2 + (int)(me->query_skill("force", 1))/5);

	me->set_temp("marks/done", 1);
	call_out("delete_done", 5, me);

	return 1;
}

void delete_done(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/done");
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/wo");
	return ::valid_leave(me, dir);
}

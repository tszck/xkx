// Room: /d/taohua/hetang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_ride();

void create()
{
	set("short", "荷塘");
	set("long", @LONG
曲曲折折的轉出竹林，眼前出現一大片荷塘。塘中白蓮盛放，清香
陣陣，蓮葉田田，一條小石堤穿過荷塘中央，北面穿過方廳通向後面一
座精舍，南面是一片竹林。塘邊有一對白雕(diao)正自嬉戲，形體特是
雄壯。
LONG
	);
	set("exits",([
		"north" : __DIR__"dating",
		"south" : __DIR__"jicui",
	]) );
	set("item_desc", ([
		"diao" : "一對白雕正展翅欲飛。如果是桃花島的弟子，\n"
		"騎上(ride)就可以飛到中原。\n",
	]));
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("coor/x", 9010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_ride", "ride");
}
int do_ride()
{
	mapping myfam;
	object ob = this_player();
	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "桃花島")
	{
		message_vision("$N一躍身跨上了白雕。只見白雕仰天長唳，突然猛然一顛......\n"HIR"結果$N摔了個鼻青臉腫！\n"NOR"看來白雕對$N並不感興趣，它只認識桃花島的弟子。\n",ob);
		ob->receive_damage("qi",50);
		ob->receive_wound("qi",50);
		return 1;
	}
	if( (int)query("sb_ride") ) 
		return notify_fail("現在白雕正忙着，請過一會再乘坐。\n" ) ;
	add("sb_ride",1) ;
	message_vision("$N一躍身跨上了白雕。只見白雕仰天長唳，突然展翅高飛。\n\n但看一雕一人身形漸漸縮小，終至不見。\n" , ob );
	ob->move("/d/taohua/lantian") ;
	tell_object(ob,CYN"\n你不斷地飛呀飛，萬水千山身下飄過 ......\n\n" NOR);
	call_out("taohua", 3 , ob );
	add("sb_ride",-1) ;
	return 1 ;
}
void taohua( object ob )
{
	tell_object(ob, "你終於飛到了中原，白雕落了下來。\n\n"  ) ;
	ob -> move ("/d/guiyun/dayuan");
}

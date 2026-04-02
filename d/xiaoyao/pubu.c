// pubu.c 
// Modified by Winder June.25 2000

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short", "玉壁瀑布");
	set("long", @LONG
循小路直往後山深處，猛聽得水聲響亮，轟轟隆隆，便如潮水大至
一般，抬頭一看，只見西北角上猶如銀河倒懸，一條大瀑布從高崖上直
瀉下來。玉壁之前就是劍湖，湖西又是萬丈深谷，雲霧瀰漫，望不到盡
頭。。。。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : "/d/wuliang/road6",
	]));
	set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("coor/x", -71020);
	set("coor/y", -79870);
	set("coor/z", 110);
	setup();
}
 
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object ob;
	int new_jing;
	ob = this_player();
	if (ob->query_temp("marks/wuliang") != 1)
		return notify_fail("有人追殺你啊？這麼急想要跳崖自殺？\n");
	new_jing = random( ob->query("max_jing")*3 );
	if ( new_jing > ob->query("jing") ) new_jing = ob->query("jing") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
		return notify_fail("你想要跳崖自殺？這麼想不開啊？\n");
	tell_object(ob, HIR"你不加思索，縱身一躍，跳下了懸崖。。。。\n"NOR);
	message("vision", NOR"只見" + ob->query("name") + "萬念俱灰，縱身跳入了懸崖之中。。。。\n"NOR, environment(ob), ob);
	if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<30) )
	{
		ob->die();
		return 1;
	}
	ob->add("jing", 0 - new_jing);
	ob->move(__DIR__"yanfeng");
	return 1;
}
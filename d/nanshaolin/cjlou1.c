// Room: /d/nanshaolin/cjlou1.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "藏經閣二樓");
	set("long", @LONG
千餘年來少林寺執中原武林之牛耳，自達摩老祖以下，歷代人材輩
出。其中有不少高僧遺著留存，彙集至今，終成名震天下的少林七十二
絕藝。福建下院轉抄本院典籍，是故，少林精華，盡集於此。二樓四面
開窗，確保通風。中間排列着五排大書架。四周則陳列矮几，以供閱讀。
幾位老僧手執經卷，正在閉目凝思。
LONG );
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangge" : 1,
		BOOK_DIR+"nwuji1" : 1,
		BOOK_DIR+"nwuji2" : 1,
		BOOK_DIR+"nwuji3" : 1,
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

	if ( present("fang ge", environment(me)) && dir == "down")
	{
		ob = deep_inventory(me);
		i = sizeof(ob);
		while (i--)
			if (ob[i]->id("shaolin wuji"))
				return notify_fail("方戈說道: 武功祕籍只許在藏經閣內研習，不得攜帶外出！\n");
	}
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_tui", ({ "tui", "push" }));
} 
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "chuang" ) return 0;
	if ( !arg ) return 0;
	if (!me->query_temp("marks/推")) return notify_fail("你要做什麼？\n");

	if( (int)me->query_skill("dodge",1) < 120 )
	{
		message_vision( HIR"$N推開窗戶，縱身躍起直奔窗外，無奈輕功不夠，沒有跳過窗臺，就摔了下來！\n"NOR, me);
		me->unconcious();
		return 1;     
	}  
	message_vision("$N推開窗戶,縱身躍出窗戶，一眨眼就不見了 。\n", me);
	me->move(__DIR__"xiaoxi");
	tell_room(environment(me), me->name() + "從藏經閣飛身躍了過來。\n", ({ me }));
	me->delete_temp("marks/推");
     	return 1;
}
int do_tui(string arg)
{
	if( !arg || arg == "" || arg !=  "chuang") return 0;
	write("你輕輕的將藏經閣的窗戶推開。\n");
	this_player()->set_temp("marks/推", 1);
	return 1;
}

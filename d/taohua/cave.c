// Room: /d/taohua/cave.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_pull(string arg);

void create()
{
	set("short", "巖洞");
	set("long", @LONG
這裏是一個山壁上的小巖洞，雖然不甚寬敞，但也有足夠的活動空
間。陽光透過桃樹間的縫隙射了進來，映得洞中半明半暗。只能隱隱約
約看出地上有一堆乾草。乾草上好象放着一個石匣 (xia)。靠裏的洞壁
上依稀寫有一行小字(zi)。
LONG
	);
	set("exits",([
		"out" : __DIR__"dongkou",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"xia" : "你仔細看了一下石匣，發現裏面似乎放着一本書。\n",
		"zi": "只見洞壁上用尖利之物刻着字道：“奉上臭尿數罐，請啊請啊....”，後面的字被一片樹葉(ye)蓋了起來。\n",
		"ye": "一片普通的樹葉，把下面的字全都遮住了。\n",
	]) );
	set("objects",([
		__DIR__"npc/zhou" : 1,
	]) ); 
	set("coor/x", 9210);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_pull","che");
	add_action("do_pull","move");
	add_action("do_pull","yi");
	add_action("do_pick","pick");
}

int do_pull(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "ye")
	{
		message_vision("$N伸手揭起樹葉，猛聽得頭頂忽喇喇聲響，立時醒悟，忙向一旁躍開，哪知乒乒乓乓一陣響亮，從洞頂上掉下幾隻瓦罐，淋了$N一頭臭尿。\n",me);
		return 1;
	}
	return 0;
}

void reset()
{
	::reset();
	set("get_available" , 1);
}

int do_pick(string arg)
{
	object me,obj;

	me = this_player();
	if( !arg || arg!="book" ) return notify_fail("你要拿什麼？\n");
	if ( present("zhou botong",environment(me)))
	
	{
		message_vision(YEL "周伯通兩眼一瞪，哼了一聲道：別在我這裏偷偷摸摸！我周伯通還沒死哪！\n" NOR,me) ;
		return 1 ;
	}
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"jiuyin1");
		add("get_available", -1);
		if (obj->violate_unique())
		{
			destruct(obj);
			return notify_fail("你要拿起那本書，卻發現你看花了眼，其實那裏什麼都沒有。\n");
		}
		obj->move(me);
		message_vision("$N從石匣中取出一本書。\n",me );
message("channel:rumor", MAG"【謠言】某人："+this_player()->query("name")+"拿到九陰真經上卷啦。\n"NOR, users());
	}
	else
		return notify_fail("你要拿起那本書，卻發現你看花了眼，其實那裏什麼都沒有。\n");
	return 1;
}


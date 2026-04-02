// Room: /yanziwu/matou.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
#define MAX_EXP 20000
#define MIN_EXP 5000
inherit ROOM;
string look_sign();
int do_go(string);
mapping *sign=({
	([	"name" : "北京",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "蘇州",
		"id"   : "sz",
		"file" : "/d/suzhou/szyunhe",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "杭州",
		"id"   : "hz",
		"file" : "/d/hangzhou/matou",
		"value": 200,
		"time" : 20
	])
});
void create()
{
	set("short","寧海橋碼頭");
	set("long",@LONG
這裏是揚州城裏最大的碼頭，南方的糧食，兩淮的鹽鐵在此卸下由
漕運署的官員抽查，或轉運或暫時儲存。這裏人員繁雜，有小販在叫賣，
有工人在搬運糧袋，有官員手持長鞭在監工，有幾個潑皮在轉來轉去，
不知打些什麼主意。南邊就是漕運署。東邊是達士街，新開了幾家店鋪。
    岸邊停靠着一條客船。客船醒目處，掛着一個牌子(sign)。
LONG );
	set("outdoors", "yangzhoue");
	set("worktimes", 20);
	set("exits", ([
		"north" : __DIR__"beiliuxiang",
		"south" : __DIR__"zhuqidian",
		"east"  : __DIR__"dashixijie",
		"west"  : __DIR__"ninghaiqiao",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
	set("objects", ([
		__DIR__+"npc/jiangong" :1,
	]));
	set("coor/x", 40);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_work", ({"work", "ganhuo"}) );
	add_action("do_go", "qu");
}

int do_work()
{
	object me = this_player();
//	if ( query("worktimes") < 0)
//		return notify_fail("碼頭上現在不需要人幹活，下次吧！\n");
	if ( me->query_temp("working") )
		return notify_fail("你已經在幹活了！！\n");
	if ( !objectp( present ("jian gong", environment(me) ) ) )
		return notify_fail("碼頭上現在不需要人幹活，下次吧！\n");
	if (me->query("combat_exp")<MIN_EXP)
	{
		tell_object(me,"這裏都是重活，你現在還幹不了。\n");
		return 1;
	}
	
	if (me->query("combat_exp")>=MAX_EXP)
	{
		tell_object(me,"這種小事不敢勞您大駕。\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if ( (int)me->query("jing") < 10 || (int)me->query("qi") < 10 )
	{
		message_vision(
"監工衝着$N就是一鞭子，$N身上頓時起了一道血痕，$N踉踉蹌蹌躲到一\n"
"邊去了。“媽的，你小子這副萎靡不振的樣子還想幹活？！！”監工罵\n"
"到：“滾！！”\n", me);
		me->receive_damage("qi", 11);
		me->receive_wound("qi", 11);
		return 1;
	}
	write("監工拿鞭子指了指，說道：“去那裏搬麻袋吧。”\n");
	write("你搬起一個麻袋，開始幹活。\n");
	add("worktimes", -1);
	me->start_busy(3);
	me->set_temp("working",1);
//	remove_call_out("work_end");
	call_out("work_end", 5, me);
	return 1;
}

int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	write("終於做完苦工了，搬了一天的麻袋，累個半死。\n"
"監工過來拍了拍你的肩膀，說道：“小子，好樣的，這是你的工錢。”\n");
	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
		add_exp=60+random(20);
		add_pot=30+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "點實戰經驗，"
			+ chinese_number(add_pot) + "點潛能，"
			+ chinese_number(add_score) + "點江湖閱歷。\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}

string look_sign()
{
	string str="由此去(qu)到下列碼頭：\n";
	int i=sizeof(sign);

	while (i--)
	{
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
//	ob->enable_player();
	ob->delete_temp("noliving");
	ob->delete_temp("block_msg/all");
	tell_object(ob, "終點站到了。\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), ob->name() + "從船上走了下來。\n", ({ob}));
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	while(i--)
	{
		if (arg == sign[i]["id"])
		{
			switch (MONEY_D->player_pay(ob, sign[i]["value"]))
			{
				case 0:
					return notify_fail("窮光蛋，一邊待著去！\n");
				case 2:
					return notify_fail("有零錢嗎？\n");
			}
			message_vision("$N登上了去" + sign[i]["name"] + "的船。\n", ob);
//			ob->disable_player("<旅途中>");
			ob->set_temp("noliving/journey", 1);
			ob->set_temp("block_msg/all", 1);
			ob->move("/d/suzhou/onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪裏？\n");
}


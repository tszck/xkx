// laoban.c 
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老闆娘", ({"laoban niang", "laoban"}));
	set("age", 32);
	set("gender", "女性");
	set("per", 20);
	set("attitude", "friendly");

	set("combat_exp", 400);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);

	set("vendor_goods", ({
		__DIR__"obj/meigui",
		__DIR__"obj/mudan",
		__DIR__"obj/chahua",
		__DIR__"obj/lanhua",
		__DIR__"obj/meihua",
		__DIR__"obj/redrose",
		__DIR__"obj/yaohuang",
		__DIR__"obj/weizi",
	}));
	set("chat_chance", 20);
	set("chat_msg", ({
		"老闆娘嘆道：人如同花一般，一天不如一天了。\n",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 2);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_send", "send");
}
int do_send(string arg)
{
	object obj, flower, me = this_player();
	string target, item;

	if(!arg) return notify_fail("老闆娘説：你要給誰什麼東西？\n");

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	if( sscanf(arg, "%s to %s", item, target) !=2)
		return notify_fail("老闆娘説：你要給誰什麼東西？\n");

	obj = find_player(target);
		if(!obj || !me->visible(obj))
			return notify_fail("老闆娘説：此人現在不在。沒法幫你送花。\n");

	if( !living(obj))
		return notify_fail("老闆娘説：抱歉，現在沒法幫你送花。\n");

	if( !objectp(flower = present(item, me)) )	
		return notify_fail("老闆娘説：你身上沒有這種花。\n");

	if( !flower->query("flower"))
		return notify_fail("老闆娘説：你只能讓我幫你送花。\n");

	if( flower->query("no_drop") )
		return notify_fail("這樣東西不能隨便給人。\n");

	flower->move(obj);
	me->save();
	obj->save();
	tell_object(me, HIC"花店老闆娘笑了笑道：“這位"+RANK_D->query_respect(me)+"稍候，這就給你送到"+obj->query("name")+"手上。”轉身出門去了。\n" NOR );
	tell_object(obj, HIC"花店老闆娘走過來遞給你一"+flower->query("unit")+flower->query("name")+HIC"，輕輕説道：“這是"+me->query("name")+"送給你的。”轉身笑了笑就走了。\n" NOR );
	tell_object(me, HIC"花店老闆娘片刻後回來笑道：“放心吧，送到了。”\n" NOR );
	return 1;
}

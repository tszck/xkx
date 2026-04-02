// ake.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

#define MAX_PAWN 10
void create()
{
	set_name("阿珂", ({ "a ke", "ke" }) );
	set("gender", "女性" );
	set("long", "阿珂為李自成與陳圓圓之女。
她容色麗都，冠絕當代，五根手指細長嬌嫩，真如用白玉雕
成，手背上手指盡處，有五個小小的圓渦。
當年韋小寶一見這少女，不過十六七歲，胸口宛如被一個無
形的鐵錘重重擊了一記，霎時之間脣燥舌乾，目瞪口呆，心
道：“我死了，我死了！哪裏來的這樣的美女？這美女倘若
給了我做老婆，小皇帝跟我換位也不幹。韋小寶死皮賴活，
上天下地，槍林箭雨，刀山油鍋，不管怎樣，非娶了這姑娘
做老婆不可。”\n");
	set("age", 16);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_get", 1);
	set("no_get_from", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();

	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/green_cloth")->wear();
}

void init()
{
	add_action("do_value", "value");
//	add_action("do_pawn", "pawn");
//	add_action("do_redeem", "redeem");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文錢";
	else
		return chinese_number(value/100) + "兩" + (value%100? "又" + chinese_number(value%100) + "文錢": "");
}

void pay_player(object who, int amount)
{
	object ob;
	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("阿珂問道：“你要拿什麼物品給我估價？”\n");

	if( ob->query("money_id") )
		return notify_fail("阿珂問道：“這是「錢」，你沒見過嗎？”\n");

	value = ob->query("value");
	if( !value ) printf("阿珂道：“%s一文不值。”\n", ob->query("name"));
	else 
		printf("阿珂道：“%s價值%s。\n如果你要典當(pawn)，可以拿到%s。\n如果你到廣陵當鋪賣斷(sell)，可以拿到%s。”\n", ob->query("name"), value_string(value), value_string(value * 25 / 100), value_string(value * 75 / 100));
	return 1;
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value, pawn_count, i;
 
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
		write("你目前典當的物品有：\n");
		if( !mapp(pawn) || !sizeof(pawn) )
			write("\t沒有任何典當的物品。\n");
		else
		{
			terms = keys(pawn);
			for(i=0; i<sizeof(terms); i++)
			printf("%-3s：  %-15s  贖銀：%s\n", terms[i], pawn[terms[i]], value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
		}
		return 1;
	}
	if( ob->query("money_id") )
		return notify_fail("阿珂問道：“你要當「錢」？”\n");
	if (ob->is_container() )
		return notify_fail("阿珂道：“"+ob->name()+"可以裝東西，是不能收當的！請尊駕原諒。”\n");
	if( ob->query("ownmake") )
		return notify_fail("阿珂道：“典當的行規，對武林中人的喫飯傢伙是不能收當的！請尊駕原諒。”\n");
	if( ob->query("shaolin") )
		return notify_fail("阿珂道：“少林廟產小店可不敢收！”\n");
	if( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail("阿珂道：“這樣東西可當不了！”\n");
	if( ob->is_character() )
		return notify_fail("阿珂客客氣氣地道：“典當的行規，活東西是不能當的，請尊駕原諒。”\n");
	value = ob->query("value");
	if( !(value/4) )
		return notify_fail("阿珂道：“這樣東西並不值很多錢。”\n");

	if( mapp(pawn) && sizeof(pawn))
	{
		terms = keys(pawn);
		if(sizeof(terms) > MAX_PAWN)
			return notify_fail("阿珂道：“你已典當太多物品了。”\n");
		for(i=0; i<sizeof(terms); i++)	
		{
			pawn_count = i;
			if(!((int) me->query("vpawn/" + sprintf("%d", i))))
				break;
			else pawn_count = i+1;
		}
	}
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N把身上的" + ob->query("name") + "拿出來典當了"
		+ value_string(value * 25 / 100) + "。\n", this_player());
	message_vision("阿珂提筆寫道：“今押到"+ ob->query("name")+"一，殘缺破爛，當" + value_string(value * 25 / 100)+"整。年息二分，憑票取贖。蟲蟻鼠咬，兵火損失，各安天命，不得爭論。三年為期，不贖斷當。”遞給了$N。\n", this_player());
	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要賣斷什麼物品？\n");

	if( ob->query("money_id") ) return notify_fail("你要賣「錢」？\n");
	value = ob->query("value");
	if( !value ) return notify_fail("這樣東西不值錢。\n");

	message_vision("$N把身上的" + ob->query("name") + "賣掉。\n", this_player());

	pay_player(this_player(), value  * 80 / 100);
	destruct(ob);

	return 1;
}
void pay_him(object who, int amount)
{
	object ob;
	object cash, tencash, gold, silver, coin;
	tencash = present("tenthousand-cash_money", who);
	cash = present("thousand-cash_money", who);
	gold = present("gold_money",who);
	silver = present("silver_money",who);
	coin = present("coin_money",who);
	if(tencash) destruct(tencash);
	if(cash) destruct(cash);
	if(gold) destruct(gold);
	if(silver) destruct(silver);
	if(coin) destruct(coin);


	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
	int total;
	object cash, tencash, gold, silver, coin;

	tencash = present("tenthousand-cash_money", me);
	cash = present("thousand-cash_money", me);
	gold = present("gold_money",me);
	silver = present("silver_money",me);
	coin = present("coin_money",me);

	total = 0;
	if( tencash) total += tencash->value();
	if( cash) total += cash->value();
	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	if( total < amount ) return 0;

	return total;
}
int do_redeem(string arg)
{
	int num;
	int amount;
	string ob_file;
	object ob;
	object me;
	int afford;
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：redeem <物品標號>\n");
	me = this_player();
	amount = (int) me->query("vpawn/" + sprintf("%d", num));
	if( !amount )
		return notify_fail("阿珂問道：有這個物品標號嗎？\n");
	amount = amount * 3 /4;
	if( afford = affordable(me, amount) )
	{
		pay_him(me, afford-amount);
		ob_file = me->query("fpawn/"+sprintf("%d",num));
		ob = new(ob_file);
		if(ob_file == "/clone/medicine/nostrum/guiyuandan.c" ||
			ob_file == "/clone/medicine/nostrum/huochan.c" ||
			ob_file == "/clone/medicine/nostrum/labazhou.c" ||
			ob_file == "/clone/medicine/nostrum/mangguzhuha.c" ||
			ob_file == "/clone/medicine/nostrum/renshenguo.c" ||
			ob_file == "/clone/medicine/nostrum/sanshi.c" ||
			ob_file == "/clone/medicine/nostrum/xuming8wan.c" ||
			ob_file == "/clone/medicine/nostrum/xiongdan.c" ||
			ob_file == "/clone/medicine/nostrum/zhujingchan.c" ||
			ob_file == "/clone/medicine/vegetable/fuxincao.c" ||
			ob_file == "/d/jianzhong/obj/shedan.c")
		{
			message_vision("$N典當的$n由於時間太久，變質化灰了。\n", me, ob);
			destruct(ob);
		}
		else
		{
			message_vision("$N從典當行贖回了$n。\n", me, ob);
			ob->move(me);
		}
		me->delete("pawn/"+sprintf("%d",num));
		me->delete("vpawn/"+sprintf("%d",num));
		me->delete("fpawn/"+sprintf("%d",num));
		me->save();
		return 1;
	} else return notify_fail("阿珂道：你的錢不夠。\n");

}

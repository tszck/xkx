// zeng.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

int working(object me);
int halt_working(object me);
string ask_job();
void create()
{
	set_name("曾柔", ({ "zeng rou", "zeng", "rou" }));
	set("shen_type", 1);

	set("gender", "女性");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("long",
"她是韋爵爺不知道第幾房的小妾，在這裏開個成衣鋪，賣些不知道
哪來的衣服。有人說那都是韋爵爺從宮中弄出來的禁品。話這麼說，
生意照樣紅火。\n");
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		CLOTH_DIR+"cloth/belt",
		CLOTH_DIR+"cloth/boots",
		CLOTH_DIR+"cloth/bu-shoes",
		CLOTH_DIR+"cloth/cloth",
		CLOTH_DIR+"cloth/color-dress",
		CLOTH_DIR+"cloth/feature",
		CLOTH_DIR+"cloth/fu-cloth",
		CLOTH_DIR+"cloth/gui-dress",
		CLOTH_DIR+"cloth/hat",
		CLOTH_DIR+"cloth/jade-belt",
		CLOTH_DIR+"cloth/liu-dress",
		CLOTH_DIR+"cloth/marry-dress",
		CLOTH_DIR+"cloth/mini-dress",
		CLOTH_DIR+"cloth/moon-dress",
		CLOTH_DIR+"cloth/pink-dress",
		CLOTH_DIR+"cloth/qi-dress",
		CLOTH_DIR+"cloth/red-dress",
		CLOTH_DIR+"cloth/scarf",
		CLOTH_DIR+"cloth/sha-dress",
		CLOTH_DIR+"cloth/shoes",
		CLOTH_DIR+"cloth/xian-cloth",
		CLOTH_DIR+"cloth/xiu-cloth",
		CLOTH_DIR+"cloth/xiu-scarf",
		CLOTH_DIR+"cloth/yan-dress",
		CLOTH_DIR+"cloth/zi-dress",
	}));
	set("inquiry", ([
//		"工作" : (: ask_job :),
//		"job"  : (: ask_job :),
	]));

	setup();
	carry_object(CLOTH_DIR+"cloth/feature")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sew", "sew");
}

string ask_job()
{
	object me = this_player();
	object *obs;

	if (me->query_temp("job/sew")) return "讓你做的衣服你弄好了麼？";
	if (me->query("gender") != "女性") return "這女孩子家的活你也來幹？";
	if (me->query("combat_exp") < 50)
		return "讓你在我這兒幹活我還真有點不放心。";
//	if (me->query("combat_exp") > 15000)
//		return "大俠您好，您還是看見什麼好的自己選件吧，讓您幹活也太委屈了！";
	if (me->query("qi") < 30) return "你臉色這麼差，還是先歇會兒吧。";
	if (me->query("jing") < 30)
		return "你精神頭不行啊，別把我得料子糟踏了！";
	if (me->query_int() < 20)
		return "嘻嘻...你這麼笨手笨腳的，也會做衣服？";
	if (! interactive(me)) return "...";
	obs = filter_array(all_inventory(environment()),
		(: interactive($1) &&
		$1 != $(me) &&
		$1->query_temp("job/sew") &&
		query_ip_number($1) == query_ip_number($(me)) :));
	if (sizeof(obs) > 0)
		return "現在已經有" + obs[0]->name() + "在幫我啦，不勞你了。";

	me->set_temp("job/sew", 1);
	return "好，你就幫我做點裁縫(sew)的小活吧！喏，東西都在這兒。";
}

int do_sew(string arg)
{
	object me = this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢，彆着急。\n");
	if (! me->query_temp("job/sew"))
	{
		message_vision("$N偷偷的拿起一個頂針，$n一聲嬌吒道：你給我放下，有什麼好玩的？\n", me, this_object());
		return 1;
	}

	me->set_temp("job/step", 1);
	me->start_busy(bind((: call_other, __FILE__, "working" :), me), bind((: call_other, __FILE__, "halt_working" :), me));
//	me->start_call_out((:call_other,__FILE__,"working", me, 1:), 5);
	tell_object(me, "你開始縫紉。\n");
	return 1;
}

int working(object me)
{
	string msg;
	int finish;
	int b;

	if (! me->query_temp("job/step")) me->set_temp("job/step", 1);
	if (! living(me))
	{
		me->delete_temp("job/sew");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 1);
	me->receive_damage("qi", 2);
	switch (me->query_temp("job/step"))
	{
		case 1:
			msg = "$N戴上一個頂針，摸出針線。";
			break;
		case 2:
			msg = "$N展開布料，對着樣子比劃了半天。";
			break;
		case 3:
			msg = "$N輕輕的折了折料子，留下幾條痕印。";
			break;
		case 4:
		case 6:
			msg = "$N專心致志的一針一線的縫紉。";
			break;
		case 5:
			msg = "$N凝眉看了看樣子，若有所思。";
		case 7:
			msg ="$N輕動纖纖細指，縫針上下穿梭，衣服的模樣漸漸的出來了。";
			break;
		default:
			msg = "$N把衣服縫好，燙熨完畢，疊好遞給$n。";
			finish = 1;
			break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n看了$N縫出來的衣服，點頭道：不錯，有點意思。\n";
		me->delete_temp("job/sew");
		me->delete_temp("job/step");

		b = 5 + random(5);
		me->add("combat_exp", b);
		me->improve_potential((b + 2) / 3);

		ob = new("/clone/money/coin");
		ob->set_amount(60);
		ob->move(me, 1);
	}

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (b > 0)
		{
			tell_object(me, HIC "\n你獲得了" + chinese_number(b) + "點經驗和" + chinese_number((b + 2) / 3) + "點潛能。\n\n" NOR);
		}
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_working(object me)
{
	message_vision("$N把手中的針線一扔，嘀咕道：“沒勁，本姑娘不幹了！”\n", me);
	me->delete_temp("job/sew");
	me->delete_temp("job/step");
	return 1;
}


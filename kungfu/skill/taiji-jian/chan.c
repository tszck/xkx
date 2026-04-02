// chan.c 太極劍法「纏」字訣

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「纏」字訣"
int checking(object me, object target, object weapon);

string *number_msg = ({"一","二","三","四","五","六","七","八","九","十","十數","千百","無數"});
string *sword_msg = ({"反撩","斜刺","上挑","下劃","正劈","直刺","後拉","前推"});
string *chan_msg = ({
CYN"$N以意馭劍，$S畫出$R個"RED"圓圈"CYN"，其千變萬化，無窮無盡，要去包裹纏住$n！\n" NOR,
CYN"$N以意馭劍，$S畫出$R個"RED"圓圈"CYN"，前後排列，要將$n包裹起來！\n" NOR,
CYN"$N心中不存半點渣滓，以意馭劍，$W"CYN"每發一招，便似放出一條"RED"細絲"CYN"，要去纏住$n！\n"NOR,
CYN"$N以意馭劍，$S畫出$R個"RED"圓圈"CYN"，正反相交，要將$n纏在正中！\n" NOR,
CYN"$N手中$W"CYN"揮動，驅太極劍意散發出根根"RED"細絲"CYN"，要將$n裹起來！\n"NOR,
CYN"$N以意馭劍，$S畫出$R個"RED"圓圈"CYN"，上下包容，要將$n包裹起來！\n" NOR,
CYN"$N的一柄$W"CYN"畫着一個個"RED"圓圈"CYN"，每一招均是以弧形刺出，以弧形收回，纏住$n！\n"NOR,
CYN"$N以意馭劍，$S畫出$R個"RED"圓圈"CYN"，左右兼顧，要將$n纏在正中！\n" NOR,
});

string *dodged = ({
HIY"可是$n已然看穿了$P的招數，孤注一擲直入圈心，破了$N的太極劍意！\n\n" NOR,
HIY"$n微覺$N招數澀滯，急忙變招，竭盡全身之力中宮疾進，從劍光圈中衝了出去！\n\n"NOR,
HIY"$n微覺$N招數澀滯，急忙變招，竭盡全身之力飛躍後退，遠離了劍圈！\n\n"NOR,
HIY"$n看得真切，回招擋格了$N中宮一劍，接着縱身一躍，已逃出圈外。\n\n"NOR,
});

string *chaned = ({
HIW"結果$n的招數漸見澀滯，偶爾發出一招，真氣運得不足，便被$W"HIW"帶着連轉幾個圈子。\n"NOR,
HIW"結果太極劍意散發出的細絲越積越多，似是積成了一團團絲棉，將$n緊緊裹了起來！\n"NOR,
HIW"結果，劍氣似是積成了一團團絲棉，將$n緊緊裹了起來！\n"NOR,
HIW"$n越鬥越是害怕，一個疏忽，被太極劍意緊緊裹了起來！\n"NOR,
});

int perform(object me, object target)
{
	int cost;
	object weapon = me->query_temp("weapon");
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if(!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中無劍，如何使得「纏」字訣？\n");

	if(me->query_temp("tjj/chan"))
		return notify_fail("你正在使用「纏」字訣。\n");

	if( target->is_busy() )
		return notify_fail(target->name() +"目前正自顧不暇，放膽攻擊吧！\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修為不夠，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill )
		return notify_fail("你所用的內功與太極劍意氣路相悖！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的內力不夠！\n");

	if( me->query("max_neili") <= 700 )
		return notify_fail("你的內力修為不夠！\n");

	cost = me->query_skill(bskill, 1)/2;
	me->add("neili", -cost);

	message_combatd(CYN"\n$N使出太極劍法"RED"「纏」"CYN"字訣，一柄"+weapon->name()+CYN"在畫着一個個圓圈，每一招均是以弧形刺出，弧形收回。
神在劍先，綿綿不絕，便如撒出了一張大網，逐步向$n收緊！\n\n"NOR, me, target);
	me->start_busy(1);
	me->set_temp("tjj/chan", 1);
	call_out("check_fight", 0, me, target, weapon);
	me->start_perform(1, "纏");
	return 1;
}

int check_fight(object me, object target, object weapon)
{
	string msg;
	object wep;

	if (!me) return 1;
	if(!me->query_temp("tjj/chan")) return 1;

	if( !living(me) || me->query_temp("noliving") || !target)
	{
		me->delete_temp("tjj/chan");
		return 1;
	}
	
	if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword")
	{
		if(!wep)msg = HIY"$N手中武器既失，圓轉的太極劍幕也隨之消散，$n不禁鬆了口氣。\n"NOR;
		else msg = HIY "$N亮出"+wep->name()+HIY"而撤回太極劍意，$n身邊密佈的劍幕也隨之消散，壓力驟然減輕！\n"NOR;
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	} 
	if(environment(me) != environment(target))
	{
		msg = HIY"$N將手中"+wep->name()+HIY"向後一擺，抱圓守一，撤回了散開的太極劍意。\n"NOR;
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	}
	if(!me->is_fighting(target) && !me->is_killing(target->query("id")))
	{
		if(!living(target) || target->query_temp("noliving") )
			msg = HIY"$N不屑地望了$n一眼，將手中"+wep->name()+HIY"一向後襬，撤回了散開的劍幕。\n"NOR;
		else
			msg = HIY"$N將手中"+wep->name()+HIY"向後一擺，抱圓守一，撤回了散開的太極劍意。\n"NOR;
		if(target->is_busy()) target->start_busy(1);
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	}

	if(wep != weapon)
	{
		message_combatd(HIY"$N撤後換劍，劍勢頓時無法圓轉如意，$n身邊的太極劍幕威力驟減，使$n有了喘息之機會！\n"NOR,me, target);
		me->start_busy(1);
		if(target->is_busy() &&
			random(me->query_skill("sword", 1)) <
			(int)target->query_skill("dodge", 1)/2)
		{
		//	target->start_busy(1);
			me->delete_temp("tjj/chan");
			return 1;
		}
		else
		{
			call_out("checking", 1, me, target, wep);
			me->start_perform(1, "纏");
		}
	}
	if (userp(me) &&
		(me->query_skill_mapped("sword") != "taiji-jian" ||
		me->query_skill_mapped("parry") != "taiji-jian"))
	{
		message_combatd(HIY"$N突然變招，劃破劍幕，使出和太極劍法完全不同的招數來！\n"NOR,me);
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		return 1;
	}
	if( me->query("neili") <= me->query_skill("sword", 1)/2 )
	{
		message_combatd(HIY"$N劍招漸見澀滯，偶爾一劍刺出竟然軟弱無力，原來是真氣不足了！\n"NOR,me);
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		return 1;
	}

	if(!target->is_busy() && !me->is_busy() && random(4)==1 &&
		living(target) && !target->query_temp("noliving") )
	{
		msg = chan_msg[random(sizeof(chan_msg))];
		msg = replace_string(msg, "$S", sword_msg[random(sizeof(sword_msg))]);
		msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
		msg = replace_string(msg, "$W", wep->name());
		message_combatd(msg, me, target);
		checking(me, target, wep);
	}
	else
	{
		call_out("check_fight", 1, me, target, wep);
		me->start_perform(1, "纏");
	}
	return 1;
}

int checking(object me, object target, object weapon)
{
	string msg;
	int busy_time, ap, dp, cost;
	cost = 20 * target->query_temp("tjj/"+me->query("id")) + me->query_skill("sword", 1)/2;
	busy_time = (int)me->query_skill("sword", 1)/20;
	ap = me->query("combat_exp")/1000 * me->query_skill("sword",1) * me->query_int();
	dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;

	me->add("neili", -cost);
	if(random(ap) > dp/2)
	{
		target->start_busy(2+random(busy_time));
		msg = chaned[random(sizeof(chaned))];
		msg = replace_string(msg, "$W", weapon->name());
		message_combatd(msg, me, target);
		call_out("check_fight", 1, me, target, weapon);
		me->start_perform(1, "纏");
	}
	else
	{
		me->start_busy(3);
		me->delete_temp("tjj/chan");
		msg = dodged[random(sizeof(dodged))];
		msg = replace_string(msg, "$W", weapon->name());
		message_combatd(msg, me, target);
	}
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		遲滯對方出手

	出手要求：
		太極神功100級
		太極劍法100級
		內力500
		內力修為700
HELP
	);
	return 1;
}


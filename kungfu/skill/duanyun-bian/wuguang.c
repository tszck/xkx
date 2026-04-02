// wuguang.c 斷雲鞭法「日月無光」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「日月無光」"
int perform(object me, object target)
{
	int damage, power;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail(HIR"裝備鞭才能使用「日月無光」？\n"NOR);

	fskill = "xiantian-qigong";
	bskill = "whip";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你內力修爲不足，無法運足內力。\n"NOR);
	if ((int)me->query("neili") < 600)
		return notify_fail(HIC"你現在內力不夠，沒能將"PNAME"使完！\n"NOR);
	msg = HIC "$N"HIC"一聲大喝，右手一振，手中"+weapon->query("name")+HIC"脫手飛出。只見滿天鞭影，盤旋繚繞，遮閉天日，劈頭蓋腦向$n"HIC"砸了下去！\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		if ((int)me->query("shen") > 1000000) 
			power = 1000000;	
		else if ((int)me->query("shen")>0) 
			power = (int)me->query("shen");
		else power = 3000;
		if ((int)target->query("shen") <0) 
			power=power*2;
		damage = random((int)(power/1000))+(int)(power/3000);
		me->add("neili", -600);
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);		
		target->receive_wound("qi", damage/2,me);
		target->receive_damage("jing", damage/4,me);
msg += HIR"$n疾忙返身後躍，但鞭勢疾如電閃，但見黑影如壓城之勢而來，全身如遭
雷擊，一時不知捱了多少鞭，不禁慘聲連連！\n"NOR;
	} else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20,me);
		msg += HIY"可是$n"HIY"一縱數丈，一下就躍出了$N的鞭影。\n"NOR;
		me->add("neili", -200);
	}
	msg += HIC+weapon->query("name")+HIC+"落下，倒插在地上，猶振然弄威作響。\n"NOR;
	weapon->move(environment(me));
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方精氣
		遲滯對方出手

	出手要求：
		先天氣功150級
		斷雲鞭法120級
		內力600
HELP
	);
	return 1;
}


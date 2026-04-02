// diezhang.c 崑崙掌法  perform 崑山疊掌

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "「崑山疊掌」"
int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0;
	int arg;
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
		
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展"PNAME"。\n");

	fskill = "xuantian-wuji";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("strike") != "kunlun-strike" || 
			me->query_skill_mapped("parry") != "kunlun-strike")
			return notify_fail("你現在無法使用「崑山疊掌」進行攻擊。\n");
	}
	if( (int)me->query_str() < 26 )
		return notify_fail("你的膂力不夠強，不能使用「崑山疊掌」。\n");
	arg = (int)(me->query_skill(bskill, 1) / 30);

	if( arg <= 1 )
		return notify_fail("至少要有兩招纔可組成"PNAME"。\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你內力修爲不夠，不能使用"PNAME"。\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("你現在內力太弱，不能使用"PNAME"。\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("你現在的內力施展不了那麼多招。\n");

	message_combatd(HIG"$N"HIG"深吸一口氣，大喝一聲，連續擊出"+ chinese_number(arg) +"掌，後招推着前招，掌力疊合在一起撲向$n"HIG"！\n\n"NOR, me, target);
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("kunlun-strike")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
			damage = damage+100+random(500);
		}
		damage = (1 + me->query("jiali")/300) * damage / 2;
	
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "內傷");
		msg += "( $n"+eff_status_msg(p)+" )\n";

		me->add("neili", -100 * arg/2);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(arg/2+1);
		me->add("neili", -200);
		target->add("neili", -100);
		msg =HIY"\n$n"HIY"身形急速後退，順着掌風就勢一跳，躲開了這攻擊。\n" NOR;
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		傷敵氣血，並使敵受內傷

	出手要求：
		崑崙掌法100級
		基本掌法100級
		玄天無極140級
		後天膂力26
		內力1500
		激發崑崙掌法爲招架技能
		激發崑崙掌法爲掌法技能
		指定掌法技能(prepare)
HELP
	);
	return 1;
}


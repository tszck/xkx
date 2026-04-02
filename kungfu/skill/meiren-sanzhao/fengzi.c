// fengzi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "絕世風姿"
int perform(object me, object target)
{
	int level;
	string msg;
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

	if( (me->query("gender") != "女性" || me->query_per() < 20) &&	!wizardp(me) )
		return notify_fail("象你這副尊容，恐怕再怎麼樣，也沒人多看你一眼的。\n");

	if( target->query("gender") != "男性" )
		return notify_fail("怎麼了？賣弄風騷也要找個正確對象吧？\n");

	fskill = "dulong-dafa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的內力不足，恐怕沒法擺什麼風姿了。\n");

	if( target->query_temp("shenlong/fengzi") )
		return notify_fail("他已經對你很傾倒了，你還浪費什麼表情？\n");

	level = target->query_cps()/2;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cps() < random(me->query_per() * 2) )
	{
		message_combatd(HIC"激鬥中，卻見$N"HIC"忙中不亂，衝着$n"HIC"輕輕展顏露齒一笑，端的是豔若桃李、燦若明霞，容色柔媚無限，$n心中不覺一蕩，油然升起一股親近的感覺，眼神也漸漸迷茫起來。\n" NOR, me, target);
		target->set_temp("shenlong/fengzi", 1);
		target->add_temp("apply/composure", -level);
		target->start_busy(random(3)+1);
		target->start_call_out( (: call_other, __FILE__, "remove_effect", target, level:), 30);
	}
	else
	{
		message_combatd(HIY"只見$N"HIY"衝着$n"HIY"輕輕露齒一笑，露出了牙縫中一絲沒嚥下去的"HIG"菜葉"HIY"。\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object target, int level)
{
	target->delete_temp("shenlong/fengzi");
	target->add_temp("apply/composure", level);
	message_combatd(HIG"$N迷茫的眼神忽然一亮，心頭猛地一震，忙收攏起心神來。\n" NOR, target);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗費自己的內力
		大幅降低對方的定力

	出手要求：
		毒龍大法50級
		美人三招60級
		自身爲女性
		對手爲男性
		內力300
HELP
	);
	return 1;
}


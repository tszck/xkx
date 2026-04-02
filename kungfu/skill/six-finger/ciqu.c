// ciqu.c 此去彼來

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "「此去彼來」"
int perform(object me, object target)
{
	string msg, *limbs;
	int a,b,p,count, damage = 0;
	int arg=(int)(me->query_skill("finger", 1) / 30);
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

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用「此去彼來」！\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 160 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠嫺熟，無法使用"+PNAME+"。\n");

		if( (int)me->query_skill("force", 1) < 160 )
			return notify_fail("你的內功等級不夠，不能使用「此去彼來」。\n");

	if( (int)me->query_str() < 26 )
		return notify_fail("你的膂力不夠強，不能使用「此去彼來」。\n");

	if( (int)me->query("neili", 1) < 200 * arg )
		return notify_fail("你現在的內力不夠使用「此去彼來」進行攻擊。\n");
	
	if ( !userp(me) && me->query("family/family_name")!="大理段家")
		return notify_fail("只有玩家和大理人氏可以使用。\n");

	a=me->query("max_neili",1);
	b=target->query("max_neili",1);

	message_combatd(MAG "$N"MAG"十指連動，忽伸忽縮，或點或按，空中氣流激盪，劍氣自$N"MAG"指中洶湧而出，此去彼來，連綿無盡。\n" NOR, me, target);

	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("six-finger")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
			damage = damage+200+random(100);
		}    
		damage = (1 + me->query("jiali")/300) * damage*a/b ;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "內傷");
		msg += "( $n"+eff_status_msg(p)+" )\n";  

		me->add("neili", -200 * arg);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(arg/2+1);
		me->add("neili", -100*arg);
		target->add("neili", -100);
		msg =RED"\n$n就地一滾，躲開了攻擊，嚇的臉色慘白。\n" NOR;
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
		激發六脈旋環，連續出手

	出手要求：
		六脈神劍120級
		枯榮禪功160級
		基本內功160級
		後天膂力26
		內力足夠
HELP
	);
	return 1;
}


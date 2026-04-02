// biyan.c 抽髓掌之碧焰
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "「碧焰」"

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用"PNAME"！\n");	

	fskill = "huagong-dafa";
	bskill = "strike";
	pskill = "poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "douzhuan-xingyi";
	}
	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你發現自己的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"進行攻擊。\n");
	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠嫺熟，無法使用"+PNAME+"。\n");
	if(me->query_temp("pfm_chousui"))
		return notify_fail("你正在驅動火堆進行攻擊！\n");
	if((int)me->query_skill(pskill,1) < 60)
		return notify_fail("你發現自己體內聚毒不夠，無法使用"PNAME"進行攻擊。\n");	 
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你發現自己所用的內功無法進行"PNAME"攻擊。\n");

	if( (int)me->query("max_neili") < 500)
		return notify_fail("你發現自己內力太弱，無法驅動"PNAME"進行攻擊。\n");
	if((int)me->query("neili") < 300)
		return notify_fail("你發現自己現在真氣太弱，使不出"PNAME"進行攻擊。\n");	   
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
			return notify_fail("沒有火堆怎麼驅動"PNAME"進行攻擊？\n");
	  message_combatd(HIR"\n$N咬破指尖，數滴鮮血落到地面，再用內力一鼓，轟地一聲燃起一堆熊熊火焰！\n"NOR,me);
	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(HIC"\n$N右手指向"HIR"火堆"HIC"，默不作聲的注視着火焰，左掌按胸，口中喃喃的不知說些什麼。。。\n"NOR,me);
	me->start_busy(1);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 2, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;

	if(!me) return 0;
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");

	me->delete_temp("pfm_chousui");
	if ( !living(me) || me->query_temp("noliving") ||
		me->is_ghost()) return 1;

	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) || environment(me)!=environment(target) ||
  	  !living(target) || target->query_temp("noliving") )
	{
		message_combatd(HIY"$N緩緩將右手收回，散開內息，雙手下垂而立。\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N眼看火堆熄滅，長嘆一聲散開內息，雙手下垂而立。\n"NOR,me);
		return 1;
	}
	if(target->query_condition("xx_poison") > 100)
	{
		tell_object(me,"對方已經身中無數劇毒，你不用再進行「碧焰」攻擊了。\n");	   
		return 1;
	}
	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry", 1) * target->query_dex();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -200);
	me->receive_damage("jing", 25);

	msg = HIC"\n然後$N突然雙掌向前平平推出，但見"RED"火焰"HIC"微微顫動了兩下，吐出一道"GRN"碧焰"HIC"，射向$n的$l！\n"NOR;	
	if(random(ap) > dp/3)//2
	{
		damage = random(i)*2+me->query("jiali")*2;
		if(neili > target->query("neili")*2) damage = damage*2;
		if(damage > 700) damage = 700;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		target->apply_condition("xx_poison",  (me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "刺傷");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		me->start_busy(1);
		target->start_busy(1);
	}
	else	
	{
		me->start_busy(2);
		msg += HIY"\n$p全力向後一縱一閃，兇險萬分地避開了那急速而來的$w"HIY"！\n" NOR;
	}       
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", GRN"碧焰"NOR);
	message_combatd(msg, me, target);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		傷害對方氣血
		使對手中星宿毒

	出手要求：
		化功大法80級
		抽髓掌80級
		基本毒技60
		內力修爲500
		內力300
		周圍有火堆
HELP
	);
	return 1;
}


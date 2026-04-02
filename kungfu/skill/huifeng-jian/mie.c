// mie.c  迴風拂柳劍法「滅劍」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「滅劍」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"開什麼玩笑，沒裝備劍就想使"PNAME"？\n"NOR);

	fskill = "linji-zhuang";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，"+PNAME+"不成招式。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"劍法不夠嫺熟，還使不出"+PNAME+"。\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail(RED"你的內力修爲不足，無法運足"PNAME"的內力。\n"NOR);

	if ((int)me->query("neili")<400)
		return notify_fail(HIC"你現在內力不夠，沒能將"PNAME"使完！\n"NOR);

	msg = HIC "$N手中"+weapon->query("name")+HIC+"劍芒躍動，劍光暴長，幻出死亡的色彩，劍尖漸\n"NOR;
	msg += HIC"漸逼近$n"HIC"，$n"HIC"看到漫天劍光，抽身後躍，只這一剎，漫天劍\n"NOR;
	msg += HIC"影化爲一劍直刺$n"HIC"前胸，快捷無倫，只有一劍！\n"NOR;
	if (random(me->query_skill("force"))>target->query_skill("force")/2 || 
		random(me->query("combat_exp"))>target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1);
		damage = damage + random((int)(damage*3/5));
//		if (me->query("sex/number")) damage/=10;
		target->receive_damage("qi", (int)(damage/2),me);
		target->receive_wound("qi", damage,me);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", (int)(damage/2),me);
		msg +=HIC"$n根本沒法躲避，一式「迴風拂柳劍」的絕招「滅劍」端端正\n正扎進在$n胸口！$n一低頭，便看到長劍自胸口挾"HIR"血"HIC"拔出！\n"NOR;
		me->add("neili", -400);
	} else
	{
		me->start_busy(4);
		msg +=HIY"可是$p輕輕一笑，側身右轉，伸出兩指，正彈在$P的劍上，長\n劍在$p身側劃過，毫髮無傷。\n"NOR;
		me->add("neili", -200);
	}
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
		損傷對方精氣和氣血

	出手要求：
		臨濟十二莊60級
		迴風拂柳劍60級
		內力400
HELP
	);
	return 1;
}


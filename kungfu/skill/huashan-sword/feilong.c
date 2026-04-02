// feilong.c  華山劍法「天外飛龍」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「天外飛龍」"
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

  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"裝備劍才能使用"PNAME"！\n"NOR);
        
	fskill = "zixia-shengong";
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
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");

  if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你內力修為不足，無法運足內力。\n"NOR);

  if ((int)me->query("neili") < 400)
		return notify_fail(HIC"你現在內力不夠，沒能將"PNAME"使完！\n"NOR);
 
    msg = HIC "$N"HIC"心念電閃，一提內力，勒手仗劍，運勁於臂，呼的一聲向$n"HIC"擲了出去，\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi");
        target->receive_damage("qi", damage-10,me);
        target->receive_wound("qi", damage*2/3,me);
        msg += HIC"$n"HIC"疾忙躍起，但劍如電閃，只覺一陣劇痛，劍刃攔腰而過，鮮血飛濺，皮肉捲起！\n"NOR;
        me->set("neili", 100);
    } else
    {
        me->start_busy(2);
        msg += HIY"可是$n"HIY"輕輕一笑，側身伸指，正彈在$N"HIY"的劍脊上，劍斜飛落地。\n"NOR;
        me->add("neili", -200);
    }
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
		脫手飛劍傷敵
		極度損傷對方氣血，但威力稍弱於狂風快劍

	出手要求：
		華山劍法150級
		紫霞神功100級
		內力600
HELP
	);
	return 1;
}


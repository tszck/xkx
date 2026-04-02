// jianzhang.c  天山奇峯
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「天山奇峯」"
string *desc = ({
HIW"\n                  ^長空雷隱！^          \n" NOR,
HIY  "                ^^^山風凜冽！^^^       \n" NOR,
RED  "             ^^^^^^回光幻電！^^^^^^  \n" NOR,
HIM  "          ^^^^^^^^^冰河開凍！^^^^^^^^^ \n" NOR,
HIC  "       ^^^^^^^^^^^^天山雪崩！^^^^^^^^^^^^ \n" NOR,
});
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,i;
        int staff_level;
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
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不對。\n");

	fskill = "huagong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"還不到家，無法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不夠！\n");

	msg = HIY "$N使出星宿派絕技「天山奇峯」，身法陡然加快。\n"NOR;
	message_combatd(msg,me,target);
  staff_level=me->query_skill(bskill);
  for (i=0;i<5;i++)
  {
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		msg = desc[i];
		message_combatd(msg,me,target);
		me->add_temp("apply/attack",staff_level/20);
		me->add_temp("apply/damage",staff_level/20);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->add_temp("apply/attack",-staff_level/20*i);
	me->add_temp("apply/damage",-staff_level/20*i);
	me->add("neili", -250);
	me->start_busy(3);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
                連續出手數杖

        出手要求：
                化功大法100級
                天山杖法100級
                內力修爲300
                內力500
HELP
        );
        return 1;
}
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「焚我」"
int perform(object me, object target)
{
	object weapon,piece;
	int i;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");

	if (weapon->is_unique())
		return notify_fail("你手中之刀已是鋒利之極，使用「焚我」絕技沒有什麼作用！\n");

	fskill = "yijinjing";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"還不夠嫺熟，使不出"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("force") != "yijinjing")
			return notify_fail("沒有易筋經作為根基，是無法使出「焚我」絕技的！\n"); 
	}
	if( (int)me->query_str() < 34)
		return notify_fail("你的膂力不夠強勁，使不出「焚我」絕技。\n");
	if( (int)me->query_int() < 34)
		return notify_fail("沒有大智慧大般若，是使不出焚我絕技的。\n");
	if(me->query_temp("ranmu")) 
		return notify_fail("你現在正在使用「焚心」絕技。\n"); 
	if (me->query_temp("fumo"))
		return notify_fail("你現在正在使用「金剛伏魔」神功。\n"); 
	if (me->query("max_neili") < 2000)
		return notify_fail("你的內力修為不夠。\n");
	if (me->query("neili") < 650)
		return notify_fail("你的內力不夠。\n");
	me->add("neili", -600);
	message_combatd( HIR"\n$N雙掌夾刀合十，手中的"+weapon->name()+HIR"頓時升起一團火焰將自己包圍，$N"HIR"猛宣一聲佛號，一刀直劈向$n"HIR"！\n"NOR,me,target);	

//fenwo's damage depends on how many times u pfmd	
	i = me->query("fenwo");
	if(i > me->query_skill("blade")) i = me->query_skill("blade");
	i -= me->query("age");
//and it will not be over ur enable blade skill

	me->add_temp("apply/damage", i);
	me->set_temp("fenwo_hit", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add("fenwo",1);
	weapon->add("fenwo", 1);
	if (weapon && weapon->query("fenwo") >= (3+weapon->query("rigidity")))
	{
		message_combatd(HIY "\n只聽“咔咔”幾聲，$N手中的$n"HIY"在熊熊火焰中裂成了碎片！\n"NOR,me,weapon);
		weapon->unequip();
   	seteuid(getuid());
   	piece = new("/clone/misc/piece");
   	piece->set("long", "燒成碎片的一堆物事。\n");
   	piece->set_name( "碎裂的" + weapon->query("name"), ({weapon->query("id"),"piece"}) );
   	piece->move(environment(me));
 		destruct(weapon);
		me->reset_action();
	}
	me->add_temp("apply/damage", -i);
	me->delete_temp("fenwo_hit");
	me->start_busy(2+random(2));
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
		焚燬自己兵刃，猛力出手

        出手要求：
                燃木刀法150級
                基本刀法150級
                易筋經120級
                後天膂力34
                後天悟性34
                內力修為2000
                內力650
HELP
        );
        return 1;
}


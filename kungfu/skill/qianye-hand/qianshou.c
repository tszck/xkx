// qianshou 千手如來

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「千手如來」"
void back(object target, int skill);
int perform(object me, object target)
{
	string msg;
	int skill;
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
		return notify_fail("使用「千手如來」時雙手必須空着！\n");

	fskill = "zhanzhuang-gong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( target->query_temp("qianshou"))
		return notify_fail("對方已中了「千手如來」！\n");

	if( (int)me->query_dex() < 27 )
		return notify_fail("你的身法不夠強，不能使用「千手如來」。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你現在內力太弱，不能使用「千手如來」。\n");

	skill = (int)me->query_skill(bskill, 1)/10;

	msg = HIY"$N"HIY"雙手合十互擊，陡然向外一分，雙掌頓時變得輕靈飄逸，靈動異常，霎時幻起漫天的掌影。\n" NOR;
	msg += HIR "$n"HIY"只覺得四周都是$N的身影，不由得慌亂起來。\n" NOR;
	message_combatd(msg, me, target);

	target->add_temp("apply/attack", -skill);
	target->add_temp("apply/dodge", -skill);
	target->add_temp("apply/parry", -skill); 
	target->set_temp("qianshou",1);   
	me->add("neili", -500);
	target->start_call_out( (: call_other, __FILE__, "back", target, skill :),skill/10);

	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void back(object target, int skill)
{
	target->add_temp("apply/attack", skill);
	target->add_temp("apply/dodge", skill);
	target->add_temp("apply/parry", skill);
	target->delete_temp("qianshou");
	tell_object(target, HIB"你漸漸適應了這種變化，狀態又恢復如常。\n"NOR);
}

int help(object me)
{
	write(HIC"\n千葉如來手之千手如來："NOR"\n");
	write(@HELP

	使用功效：
		使對手的攻擊力和防禦力在一定時間內下降。
		但十分消耗內力。

	出手要求：
		站樁功100級
		如來千葉手100
		後天身法27
		內力1000
HELP
	);
	return 1;
}


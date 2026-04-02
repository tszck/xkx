// raozhi.c 「繞指柔劍」
// Last Modifyed by Winder on Jan. 14 2002

/*
這路「繞指柔劍」全仗以渾厚內力逼彎劍刃，使劍招閃爍無常，敵人難以擋架。
殷天正從未見過這等劍法，急忙沉肩相避，不料錚的一聲輕響，那劍反彈過來，
直刺入他左手上臂。
*/

#include <ansi.h>
void remove_effect(object me, object weapon, int sword, int force);
inherit F_SSERVER;
#define PNAME "「繞指柔劍」"
int perform(object me,object target)
{
	int force, sword;
	object weapon = me->query_temp("weapon");
	string shape = weapon->query("id");
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
		
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中無劍，怎能使出「繞指柔劍」？！\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("你已經將內力貫注入劍中了！！\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(fskill)+"修為火候未足，無法以內力逼彎劍刃！\n");

	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(sskill)+"修為還不夠，難以施展"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill )
			return notify_fail("你所用的內功與「繞指柔劍」心法相悖！\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if(userp(me) && !me->query("wudang/raozhi") )
			return notify_fail("你未得高人指點，不知該如何施展「繞指柔劍」。\n");
	}

  if( me->query_temp("taiji"))
    return notify_fail("你已經運了太級心法，沒有太多精力施展「繞指柔劍」！\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("你的內力不夠渾厚，勁力不足以逼彎劍刃！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的內力不夠，勁力不足以逼彎劍刃！\n");

	if( me->query("qi") <= 400 )
		return notify_fail("你的體力有限，難以施展「繞指柔劍」！\n");

	if( shape == "iron sword" )
		return notify_fail("你所持之劍質地過於堅硬，難以用內力將其逼彎！\n");

	if( weapon->query("ownmake"))
	  return notify_fail("自鑄兵器不宜施展「繞指柔劍」！\n");

	if( shape == "tie di" || shape == "tie xiao" || shape == "zhu xiao" ||
		shape == "yu xiao")
		return notify_fail("簫笛形狀不適合施展「繞指柔劍」！\n");

	if( shape == "xiuhua zhen" || shape == "qijue zhen" ||
		shape == "emei ci" || shape == "duanjian" || shape == "bishou" )
		return notify_fail("你的佩劍太短，不適合施展「繞指柔劍」！\n");

	me->add("neili", -100);
	me->receive_damage("qi", 150);

	if( (string)weapon->query("material") != "steel" || weapon->query("rao"))
	{
		message_combatd(HIW"\n猛地裏$N一聲清嘯，劍法忽變。可是手中"+weapon->name()+HIW"卻已經不住內力衝擊，裂成碎片！！\n"NOR, me);
		destruct(weapon);
		me->reset_action();
		me->start_busy(1);

		return 1;
	}

	force = me->query_skill("force")/2;
	sword = me->query_skill(bskill)/3;

	weapon->add("rigidity", -force);
	weapon->set("rao",1);
	me->add_temp("apply/attack", sword);
	me->set_temp("wudang/raozhi", sword);

	message_combatd(HIG"\n猛地裏$N一聲清嘯，劍法忽變，那柄"+ weapon->name() +HIG"竟似成了一條軟帶，輕柔曲折，飄忽不定。\n正是武當派絕技"+ HIW +"「繞指柔劍」"+ HIG +"！\n"NOR, me);

	call_out("checking", 1, me, weapon, sword, force);
	return 1;
}

void checking(object me, object weapon, int sword, int force)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() || !objectp(weapon))
	{
		remove_effect(me, weapon, sword, force);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIG "\n$N伸指在劍脊上輕輕一彈，只聽得" + weapon->name() + HIG"振起嗡嗡之響，劍身不停抖動。\n"+CYN+"$N順勢挽起一個劍花，將劍勢收回。\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( environment(weapon) != me || weapon !=me->query_temp("weapon"))
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIR "\n$N放棄手中" + weapon->name() +HIR"，將劍勢收回！\n"NOR, me);
		return;
        }
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("qi") < (int)me->query("max_qi") / 4 )
	{
	        remove_effect(me, weapon, sword, force);
        	tell_object(me,HIR"\n你微覺內息不暢，不得不將內力收回！\n" NOR);
		message("vision", CYN+"\n"+ me->name() + weapon->name() + CYN"圈轉，收回劍勢。招數已不如之前閃爍無常，變幻不定！\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian" &&
		!me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(CYN "\n$N圈轉" + weapon->name()+ CYN"，突然變招，使出與"+ HIW +"「太極劍」"+ NOR + CYN"不同的劍法！\n"NOR, me);
		return; 
	}
	else if( me->query_temp("wudang/raozhi") <= 50 )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIC "\n$N" + weapon->name()+ HIC"圈轉，已堪堪將一路"+ HIW +"「繞指柔劍」"+ HIC +"盡數使出！\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, weapon, sword, force);
} 

void remove_effect(object me, object weapon, int sword, int force)
{
	me->delete_temp("wudang/raozhi");
	me->add_temp("apply/attack", -sword);
  if (objectp(weapon))
  {
  	weapon->add("rigidity", force);
  	weapon->delete("rao");
  }
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
                繞指柔劍全仗以渾厚內力逼彎劍刃，使劍招閃爍無常，敵人難以擋架。

	出手要求：
		太極神功180級
		太極劍法180級
		激發太極神功和太極劍法
		內力修為1500
		內力500
		氣血400
		需機緣學得
HELP
	);
	return 1;
}


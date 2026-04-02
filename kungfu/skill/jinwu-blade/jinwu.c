// Last Modified by winder on Jul. 9 2001
// jinwu.c 金烏墮地

/*
由於劈斷對方武器的功能是這個perform最大的威力，但為了保持獨孤九劍在
這一方面的第一地位，特地對發揮這一威力的條件，在程序中做了如下限制
希望以後的巫師不要更改這些設定，畢竟在weapon武功中，不能超越lonely-sword的地位。
*/

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「"+HIR"金烏墮地"NOR+"」"

int perform(object me,object target)
{
	string msg;
	object weapon, weapon2,*inv;
	int skill, ap, dp, neili_wound, qi_wound,equip,skill1,skill2,skill3,skill4;
	int temp;
	object piece;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");
		
	fskill = "bingxue-xinfa";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("你的內力修為不夠，無法運用「"+HIR"金烏墮地"NOR+"」！\n");

	if( me->query("neili") < 400 )
		return notify_fail("你的內力不夠，無法運用「"+HIR"金烏墮地"NOR+"」！\n");

	skill  = me->query_skill(sskill,1);
	skill1 = me->query_skill("xueshan-sword",1);
	skill2 = me->query_skill(fskill,1);
	skill3 = me->query_skill(bskill,1);
	skill4 = me->query_skill("strike",1);
	msg = HIY"$N縱身躍起,使出"+HIR"「金烏墮地」"HIY"，揮舞"NOR+weapon->name()+HIY"從半空中揮刀直劈下來，\n刀鋒離地尚有數尺，地下已是塵沙飛揚，敗草落葉被刀風激得團團而舞，\n將$n逃遁退避的空隙封的嚴嚴實實。\n"NOR;
	message_combatd(msg, me, target);
	msg = "";

	ap = random(me->query_skill(bskill) + skill);
	dp = target->query_skill("dodge")/3;
	if (target->query_skill_mapped("parry") == "xueshan-sword")
	{
                msg += HIR "$n" HIR "慌忙中忙以"HIW"雪山劍法"HIR"作出抵擋，哪知$N"
                       HIR "刀法竟似雪山劍法剋星般，\n" + weapon->name() +
                       HIR "刀芒霎時又暴漲數倍，完全封鎖$n" HIR "的所"
                       "有劍招！\n" NOR;
		ap = ap * 2;
		temp = 1;
	}	
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-250);
		msg += HIC"$n避無可避，只覺一股剛猛之極的勁風撲面而來，使人直欲窒息。\n$n極力後退隔擋，卻只見"NOR""+weapon->name()+""HIC"刀光一閃，毫不停息，一刀正中面門。\n"NOR;
		qi_wound = me->query_skill("blade",1)*2+me->query_str()*10;
		qi_wound *= 2;
		if (temp != 1) //對付非雪山門派
		{
			qi_wound = random(qi_wound);
			if(qi_wound > target->query("qi")) qi_wound = 100;
		}
		target->receive_damage("qi", qi_wound);
		target->receive_wound("qi", target->query("max_qi")/3);
		target->start_busy(2+random(1));
		me->start_busy(1+random(1)); 

		if(me->query("str")>=20	&& 		//先天臂力必須不小於20
			objectp(weapon2 = target->query_temp("weapon")) &&
			me->query_str() >= 45 &&	//後天臂力必須不小於45
			me->query("max_neili") > 2500 &&//最大內力必須大於2800
			!me->query("betrayer") &&	//必須沒叛過師
			(me->query("neili") - me->query("max_neili")) > 300  &&
//現有內力必須比最大內力多300，由於在上面會減掉250，實際必須大於550
			skill > 200 &&			//金烏刀法必須大於200級
			skill1 > 200 &&			//雪山劍法必須大於200級
			skill2 > 200 &&			//冰雪心法必須大於200級
			skill3 > 200 &&			//基本刀法必須大於200級
			skill4 > 200 &&			//基本掌法必須大於200級
			me->query("family/master_id") == "bai zizai")
	//師父必須是白自在 
		{
			inv = all_inventory(target);
			for(equip=0; equip<sizeof(inv); equip++)
			{
				if(inv[equip]->query("weapon_prop") &&
					((string)inv[equip]->query("equipped")=="wielded"))
				{
					msg += HIW "$N力道未盡，手中刀勢不絕，連帶$n手上"NOR+inv[equip]->query("name")+HIW"一起劈斷。\n只聽噹的一聲，$n手上的"NOR+inv[equip]->query("name")+HIW"已被劈成兩半，掉在了地上！\n"NOR;
					message_combatd(msg, me,target);
					inv[equip]->unequip();
					seteuid(getuid());
    			piece = new("/clone/misc/piece");
		    	piece->set_name("斷掉的" + inv[equip]->query("name"),({inv[equip]->query("id"),"piece"}));
			    piece->move(environment(target));
					piece->set("long","一把破爛武器，從中斷開，破口整齊，看來是被高手一刀劈開的。\n");
				  destruct(inv[equip]);
				}
			}
			return 1;
		}
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg += HIW"可是$n輕輕往旁邊一閃，避過了$N這必殺的一刀。\n"NOR;
		me->start_busy(2+random(2));
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
		擊落手持兵器的敵手之兵器

	出手要求：
		身為白自在嫡傳弟子
		金烏刀法100級
		冰雪心法100級
		內力修為1000
		內力400
HELP
        );
        return 1;
}


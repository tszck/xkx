// po.c 破劍式
// Last Modified by winder on Mar. 10 2000
/*
獨孤九劍，“總訣式”做在zongjue 中，有種種變化，用以體演
總訣，便於修習。
第二招“破劍式”，用以破解普天下各門各派的劍法。
第三招“破刀式”，用以破解單刀、雙刀、柳葉刀、鬼頭刀、大
砍刀、斬馬刀種種刀法。
第四招“破槍式”，包括破解長槍、大戟、蛇矛、齊眉棍、狼牙
棒、白蠟杆、禪杖、方便鏟種種長兵刃之法。
第五招“破鞭式”，用以破解鋼鞭、鐵鐧、點穴橛、枴子、蛾眉
刺、匕首、板斧、鐵牌、八角槌、鐵椎等等短兵刃。
第六招“破索式”，破解的是長索、軟鞭、三節棍、鏈子槍、鐵
鏈、漁網、飛錘流星等等軟兵刃。
第七招“破掌式”，破的是拳腳指掌上的功夫，將長拳短打、擒
拿點穴、魔爪虎爪、鐵沙神掌，諸般拳腳功夫盡數包括內在。
第八招“破箭式”，則總羅諸般暗器，練這一劍時，須得先學聽
風辨器之術，不但要能以一柄長劍擊開敵人發射來的種種暗器，
還須借力反打，以敵人射來的暗器反射傷敵。
三述八招歸於po中。
第九劍“破氣式”，是為對付身具上乘內功的敵人而用，神而明
之，存乎一心。用poqi來實現。
pozhong 一招，是“破箭式”的變招。
*/

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "破劍式"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage, sk ;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	if(me->query("family/master_id")!="feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("你不是風清揚的弟子，不能使用絕招！\n");
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
		return notify_fail("獨孤九劍攻招只能對戰鬥中的對手使用。\n");
		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("沒有劍在手怎麼能用獨孤九劍？\n");

	bskill = "sword";

	skill = me->query_skill(sskill,1);

	if( skill < 50)
		return notify_fail("你的獨孤九劍等級不夠，不能使用攻招！\n");
		
	if( me->query("max_neili") < 500 )
		return notify_fail("你的內力修為不夠，無法運用攻招！\n");

	if( me->query("neili") < 250 )
		return notify_fail("你的內力不夠，無法運用攻招！\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))) sk = 1;
	else
	{
		if((string)weapon2->query("skill_type")=="sword") sk=2; //掌
		if((string)weapon2->query("skill_type")=="blade") sk=3; //刀
		if((string)weapon2->query("skill_type")=="spear" ||     //槍
			(string)weapon2->query("skill_type")=="club" || //棍
			(string)weapon2->query("skill_type")=="fork" || //叉
			(string)weapon2->query("skill_type")=="rake" || //耙
			(string)weapon2->query("skill_type")=="stick" || //棒
			(string)weapon2->query("skill_type")=="staff") sk=4;//杖
		if((string)weapon2->query("skill_type")=="mace" || //鞭
			(string)weapon2->query("skill_type")=="axe" || //斧
			(string)weapon2->query("skill_type")=="dagger" || //匕
			(string)weapon2->query("skill_type")=="hammer" || //錘
			(string)weapon2->query("skill_type")=="hook") sk=5; //鈎
		if((string)weapon2->query("skill_type")=="whip") sk=6; //軟鞭
		if((string)weapon2->query("skill_type")=="throwing") sk=7;//暗器
	}
// 破掌
	switch (sk)
	{
		case 1:
			msg = HIC"$N"HIC"使出獨孤九劍之「破掌式」，勁力聚在劍尖，以意使劍，向$n"HIC"的掌心刺去。\n";
			break;
		case 2:
			msg = HIC"$N"HIC"舉"+weapon->name()+HIC"畫弧，默潛獨孤九劍之「破劍式」, 斜刺裏刺出一劍，劍勢飄忽，刺向$n"HIC"的手腕。\n";
			break;
		case 3:
			msg = HIC"$N"HIC"使出獨孤九劍「破刀式」，手腕微翻，"+weapon->name()+HIC"挑上，刷的一聲，刺向$n"HIC"肩頭“肩貞穴”。\n";
			break;
		case 4:
			msg = HIC "$N"HIC"一式獨孤九劍「破槍式」，劍勢靈巧地順着"+weapon2->name()+HIC"削落，划向$n"HIC"的五指。\n";
			break;
		case 5:
			msg = HIC"$N"HIC"使出獨孤九劍「破鞭式」逼近$n"HIC"，提劍幻出重重劍影，向$n"HIC"如柔絲般向$n裹去。\n";
			break;
		case 6:
			msg = HIC"$N"HIC"使出獨孤九劍之「破索式」，劍化流星，迅急無比地點向$n"HIC"的手腕。\n";
			break;
		case 7:
			msg = HIC"$N"HIC"舉劍連點，運起獨孤九劍之「破箭式」, 將$n擲過來的"+weapon2->name()+"打得向$n"HIC"反擊回去。\n";
			break;
	}
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill(bskill) + skill;
	dp = target->query_skill(bskill) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-50);
		switch (sk)
		{
			case 1:
				msg = HIY"$n頓時覺得眼前一花，手心一涼，手掌中心一截劍尖冒了出來。\n"NOR;
				break;
			case 2:
				msg = HIY"$n頓時覺得眼前一花，手腕一麻，手中"+weapon2->name()+HIY"脫手而出！\n"NOR;
				break;
			case 3:
				msg = HIY"$n肩頭劇痛，雙手使不出力道，手中"+weapon2->name()+HIY"“噹啷”一聲掉在地上。\n"NOR;
				break;
			case 4:
				msg = HIY"$n頓時大驚，為保手指，忙把手中"+weapon2->name()+HIY"撒手拋出！\n"NOR;
				break;
			case 5:
				msg = HIY"$n頓覺手心猛地劇痛，手中"+weapon2->name()+HIY"被絞得脫手飛出！\n"NOR;
				break;
			case 6:
				msg = HIY"$n只覺得$N的"+weapon->name()+"乘空直入，手中"+weapon2->name()+HIY"被擋在外門，回救不及，不得不棄之騰出手來空手招架。\n"NOR;
				break;
			case 7:
				msg = HIY"$n頓時覺得鋪天蓋地的"+weapon2->name()+HIY"反而向自己襲來！全身上下立刻被打得跟馬蜂窩似的\n" NOR;
				break;
		}
		me->start_busy(1+random(2));
		target->receive_damage("qi", damage,me);
		if (!target->is_busy())
		target->start_busy(2);
		if (sk ==1)
		{
			if (!target->query_temp("lonely-sword/pozhang"))
			{
				target->set_temp("lonely-sword/pozhang",1);
				target->start_call_out((:call_other, __FILE__, "remove_effect", target:), skill/30+2);
			}
		}
		else 
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		if(sk==1)
			msg = HIG"可是$n看破了$N的劍路，一個鐵坂橋，避開$N的兇狠出手。\n"NOR;
		else
			msg = HIG"可是$n看破了$N的劍路，立刻將手中" + weapon2->name()+ "舞得風雨不透，使$N的出手落空。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}
void remove_effect(object me)
{
	if (me->query_temp("lonely-sword/pozhang"))
	{
//	 tell_object(find_player("qingyun"),me->name()+"remove eff from pozhang\n");
	 me->delete_temp("lonely-sword/pozhang");
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		擊落手持兵器的敵手之兵器，並傷敵氣血
		攻擊未持兵器的敵手，傷敵氣血

	出手要求：
		身為風清揚嫡傳弟子
		獨孤九劍50級
		內力修為500
		內力250
HELP
	);
	return 1;
}

